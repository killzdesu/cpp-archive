#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define all(x) x.begin(),x.end()
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()


using namespace std;

int i, n, k, N, M, K;
int s[100010];

struct tree{
    int mx, mn;
    int lo, hi;
}T;


struct segment_tree{
    tree m[100010*6];

    void init(int key, int lo, int hi){
        m[key].lo = lo;
        m[key].hi = hi;
        if(lo == hi-1){
            m[key].mx = m[key].mn = s[lo];
            return;
        }
        init(key*2, lo, (lo+hi)/2);
        init(key*2+1, (lo+hi)/2, hi);
        m[key].mx = max(m[key*2].mx, m[key*2+1].mx);
        m[key].mn = min(m[key*2].mn, m[key*2+1].mn);
    }

    int query_max(int key, int lo, int hi){
        if(m[key].hi <= lo or hi <= m[key].lo) return -2e9;
        if(lo <= m[key].lo and m[key].hi <= hi) return m[key].mx;
        return max(query_max(key*2, lo, hi), query_max(key*2+1, lo, hi));
    }

    int query_min(int key, int lo, int hi){
        if(m[key].hi <= lo or hi <= m[key].lo) return 2e9;
        if(lo <= m[key].lo and m[key].hi <= hi) return m[key].mn;
        return min(query_min(key*2, lo, hi), query_min(key*2+1, lo, hi));
    }

}sg;

int run(int mi){
    int c=0, a;
//    printf("-- %d --\n", mi);
    REP(a, N-mi+1){
        if(abs(sg.query_max(1, a, a+mi)-sg.query_min(1, a, a+mi)) <= K){
//            printf(">>%d:: %d %d\n", a, sg.query_max(1, a, a+mi), sg.query_min(1, a, a+mi));
            c = 1;
            break;
        }
    }
    return c;
}

int main(){
int a, b, c, d;
cin >> N >> K;
REP(a, N){
    cin >> s[a];
}
sg.init(1, 0, N);
int lo=1, hi = N, mi;
while(lo < hi){
    mi = lo+(hi-lo+1)/2;
    c = run(mi);
    if(c) lo = mi;
    else hi = mi-1;
}
vector<int> ans;
mi = lo;
REP(a, N-mi+1){
    if(abs(sg.query_max(1, a, a+mi)-sg.query_min(1, a, a+mi)) <= K){
        ans.pb(a+1);
    }
}
printf("%d %d\n", lo, ans.size());
REP(a, ans.size()){
    printf("%d %d\n", ans[a], ans[a]+mi-1);
}
return 0;
}
