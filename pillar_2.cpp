#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<cmath>
#include<stack>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long

using namespace std;

int i, n, k, N, M, K;

struct tree{
    int val;
    int lo, hi;
};

template <typename Type>
struct MAX{
    Type operator () (const Type& a, const Type& b) const{
        return max(a, b);
    }
};

template <typename Comparator, int N>
struct segment_tree{
    tree m[100010*6];
    Comparator comp;


    void init(int key, int lo, int hi){
        m[key].val = 0;
        m[key].lo = lo;
        m[key].hi = hi;
        if(lo == hi-1)return;
        init(key*2, lo, (lo+hi)/2);
        init(key*2+1, (lo+hi)/2, hi);
    }

    void update(int key, int t, int val){
        //if(m[key].lo <= t and t < )
        if(m[key].lo > t or t >= m[key].hi) return;
        if(m[key].lo == m[key].hi-1){
            m[key].val = val;
            return;
        }
        update(key*2, t, val);
        update(key*2+1, t, val);
        m[key].val = max(m[key*2].val, m[key*2+1].val);
    }

    int query(int key, int lo, int hi){
        if(m[key].hi <= lo or hi <= m[key].lo) return -2e9;
        if(lo <= m[key].lo and m[key].hi <= hi) return m[key].val;
        return max(query(key*2, lo, hi), query(key*2+1, lo, hi));
    }
    void trav(int key){
        printf("%d %d| %d\n", m[key].lo, m[key].hi, m[key].val);
        if(m[key].lo == m[key].hi-1) return;
        trav(key*2);
        trav(key*2+1);
    }

};

ll s[100010];
int dp[100010];
stack<int> S, ans;
vector<ll> v;
vector<ll>::iterator it;

segment_tree<MAX<int>, 100000> Sg;

int main(){
int a, b, c, d;
ll D, l, r;
cin >> N >> D;
REP(a, N){
    scanf("%d", &s[a]);
    v.pb(s[a]);
}

sort(v.begin(), v.end());
v.resize(distance(v.begin(), unique(v.begin(), v.end())));

Sg.init(1, 0, v.size()+1);

int mx = 0;

REP(a, N){
    l = s[a]-D;
    r = s[a]+D;

    it = upper_bound(v.begin(), v.end(), l);
    c = distance(v.begin(), it);
    dp[a] = max(dp[a], Sg.query(1, 0, c)+1);

    it = lower_bound(v.begin(), v.end(), r);
    c = distance(v.begin(), it);
    dp[a] = max(dp[a], Sg.query(1, c, v.size()+1)+1);

    it = lower_bound(v.begin(), v.end(), s[a]);
    c = distance(v.begin(), it);

    mx = max(mx, dp[a]);
    Sg.update(1, c, dp[a]);
}
i = mx;
for(a=N-1;a>=0;a--){
    if(dp[a] == mx){
        S.push(a);
        break;
    }
}
i--;
for(a--;a>=0;a--){
    if(dp[a] == i and fabs(s[a]-s[S.top()]) >= D)
    {
        i--;
        S.push(a);
    }
}
printf("%d\n", mx);
while(!S.empty()){
    printf("%d ", S.top()+1);
    S.pop();
}
return 0;
}
