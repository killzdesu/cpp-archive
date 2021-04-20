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
map<int, int> ma;
pii Q[100010];
vector<int> z;
int s[100010];

bool cmp(pii a, pii b){
    return a.se!=b.se?a.se < b.se:a.fi < b.fi;
}

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

int cnt[100010];

int main(){
int a, b, c, d;
RUN:;
cin >> N;
if(N == 0) return 0;
z.clear();
ma.clear();
cin >> M;
REP(a, N){
    scanf("%d", &s[a]);
    z.pb(s[a]);
}
sort(z.begin(), z.end());
z.resize(distance(z.begin(), unique(z.begin(), z.end())));
REP(a, sz(z)){
    ma[z[a]] = a;
}
REP(a, M){
    scanf("%d %d", &Q[a].fi, &Q[a].se);
}
sort(Q, Q+M, cmp);
i = 0;
sg.init(1, 0, N+4);
REP(a, N){
    c = ma[s[a]];
    sg.update(1, )
    while(i < M and i){

    }
}


goto RUN;

return 0;
}
