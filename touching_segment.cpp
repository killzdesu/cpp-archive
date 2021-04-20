#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin(), unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()


using namespace std;

int i, n, k, N, M, K;

struct tree{
    int val;
    int lo, hi;
    int flag;
    int flag_val;
};

struct lazy_segment_tree{
    int N;
    tree m[200010*6];

    void init(int key, int lo, int hi){
        m[key].val = 0;
        m[key].lo = lo;
        m[key].hi = hi;
        m[key].flag = 0;
        m[key].flag_val = 0;
        if(lo == hi-1)return;
        init(key*2, lo, (lo+hi)/2);
        init(key*2+1, (lo+hi)/2, hi);
    }

    void inherit(int key){
        if(m[key].flag == 0) return;
        m[key].val += m[key].flag_val;
        if(m[key].lo != m[key].hi-1){
            m[key*2].flag = m[key*2+1].flag = 1;
            m[key*2].flag_val +=  m[key].flag_val;
            m[key*2+1].flag_val +=  m[key].flag_val;
        }
        m[key].flag = 0;
        m[key].flag_val = 0;
    }

    void update(int key, int lo, int hi, int val){
        inherit(key);
        if(m[key].lo >= hi or lo >= m[key].hi) return;
        if(lo <= m[key].lo and m[key].hi <= hi){
//            m[key].val += val;
            m[key].flag = 1;
            m[key].flag_val += val;
            inherit(key);
            return;
        }
        update(key*2, lo, hi, val);
        update(key*2+1, lo, hi, val);
        m[key].val = max(m[key*2].val, m[key*2+1].val);
    }

    int query(int key, int lo, int hi){
        if(m[key].hi <= lo or hi <= m[key].lo) return -2e9;
        inherit(key);
        if(lo <= m[key].lo and m[key].hi <= hi) return m[key].val;
        return max(query(key*2, lo, hi), query(key*2+1, lo, hi));
    }

    void trav(int key){
        printf("%d %d| %d\n", m[key].lo, m[key].hi, m[key].val);
        if(m[key].lo == m[key].hi-1) return;
        trav(key*2);
        trav(key*2+1);
    }

}Sg;

pii s[100010];
map<int, int> m;
vector<int> E[200010], B[200100];
vector<int> z;

bool cmp(pii a, pii b){
    if(a.se != b.se) return a.se < b.se;
    return a.fi > b.fi;
}

int qs[200010];

int main(){
int a, b, c, d;
int TR;
//Sg.init(1, 0, 1000);
//Sg.update(1, 0, 2, 1);
//Sg.update(1, 2, 4, 1);
//Sg.update(1, 4, 6, 1);
//cout << Sg.query(1, 0, 3);
//return 0;
cin >> TR;
int X;
REP(X, TR){
    cin >> N;
    Sg.init(1, 0, 200005);
    m.clear();
    REP(a, 200005){
        qs[a] = 0;
        E[a].clear();
        B[a].clear();
    }
    z.clear();
    REP(a, N){
        scanf("%d %d", &s[a].fi, &s[a].se);
        z.pb(s[a].fi);
        z.pb(s[a].se);
    }
    sort(s, s+N, cmp);
    compress(z);
    REP(a, sz(z)){
        m[z[a]] = a;
    }
    REP(a, N) {
        s[a].fi = m[s[a].fi];
        s[a].se = m[s[a].se];
        B[s[a].fi].pb(a);
        E[s[a].se+1].pb(a);
    }
    int mx = 0;

    // sweep
    c = 0;
    REP(a, sz(z)){
        c += B[a].size();
        c -= E[a].size();
        REP(b, E[a].size()){
            i = E[a][b];
            Sg.update(1, s[i].fi, s[i].se+1, 1);
        }
//        printf("%d: %d + %d\n", a, c, Sg.query(1, 0, a));
        mx = max(mx, c + Sg.query(1, 0, a));
    }
    printf("Case %d: %d\n", X+1, mx);
}

return 0;
}
