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
    int lo, hi;
    int mx, mx1;
}oo;

struct segtree{
    tree m[6*100010];

    tree combine(tree a, tree b){
        tree t;
        t.lo = min(a.lo, b.lo);
        t.hi = max(a.hi, b.hi);
        t.mx1 = max(a.mx1, b.mx1);
        t.mx = max(a.mx, max(b.mx, a.mx1+b.mx1));
        return t;
    }

    void init(int key, int lo, int hi){
        m[key].lo = lo;
        m[key].hi = hi;
        if(lo == hi-1){
            m[key].mx1 = s[lo];
            m[key].mx = -2e9;
            return ;
        }
        init(key*2, lo, (lo+hi)/2);
        init(key*2+1, (lo+hi)/2, hi);
        m[key] = combine(m[key*2], m[key*2+1]);
    }

    void update(int key, int t, int val){
        if(m[key].lo > t or m[key].hi <= t) return;
        if(m[key].lo == m[key].hi-1){
            m[key].mx1 = val;
            return;
        }
        update(key*2, t, val);
        update(key*2+1, t, val);
        m[key] = combine(m[key*2], m[key*2+1]);
    }

    tree query(int key, int lo, int hi){
        if(m[key].lo >= hi or m[key].hi <= lo) return oo;
        if(lo <= m[key].lo and m[key].hi <= hi) return m[key];
        return combine(query(key*2, lo, hi), query(key*2+1, lo, hi));
    }
}sg;

int main(){
int a, b, c, d;
oo.mx = -2e9;
oo.mx1 = -2e9;
cin >> N;
REP(a, N) scanf("%d", s+a+1);
cin >> M;
char ss[10];
sg.init(1, 0, N+4);
REP(a, M){
    scanf("%s %d %d", ss, &c, &d);
    if(ss[0] == 'Q'){
        printf("%d\n", sg.query(1, c, d+1).mx);
    }
    else {
        sg.update(1, c, d);
    }
}

return 0;
}
