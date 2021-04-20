#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin, unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;

int i, n, k, N, M, K;

const int mod = 1000001;

ll power(long long x, long long y){
    long long pow[10000];
    int a;
    for(a=2;(1<<a)<y;a++){
        pow[a] = pow[a-1]*pow[a-1];
        pow[a] %= mod;
    }
    long long ans = 1;
    for(a--;a>0;a--){
        if(a <= y) {
            y-=a;
            ans *= pow[a];
            ans %= mod;
        }
    }
    return ans;
}

pair<pii, int> s[200010];

struct tree{
    int val;
    int lo, hi;
};


struct segment_tree{
    tree m[100010*6];

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
        printf("%d %d %d\n", m[key].lo, m[key].hi, m[key].val);
        if(m[key].lo == m[key].hi-1) return;
        trav(key*2);
        trav(key*2+1);
    }

}sg;

int main(){
int a, b, c, d;
cin >> N;
sg.init(1, 0, 100003);
REP(a, N){
    scanf("%d %d", &c, &d);
    s[a] = mp(mp(c, d), a+1);
}
sort(s, s+N, greater<pair<pii, int> >());
vector<int> ans;
REP(a, N){
    c = s[a].fi.fi;
    d = sg.query(1, c, c+1);
    if(sg.query(1, c+1, 100002) < s[a].fi.se and d <= s[a].fi.se){
        ans.pb(s[a].se);
    }
    sg.update(1, c, max(d, s[a].fi.se));
}
sort(ALL(ans));
REP(a, ans.size()){
    printf("%d ", ans[a]);
}
return 0;
}
