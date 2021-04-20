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
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;

int i, n, k, N, M, K;
int s[100010];

struct fenwick{
    int m[2*100010];
    void update(int x, int val){
        while(x <= N+5){
            m[x] += val;
            x += (x&-x);
        }
    }
    int query(int idx) {
        int sum = 0;
        while (idx > 0){
            sum += m[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    int qat(int x){
        return query(x)-query(x-1);
    }
}F;

struct tree{
    int val;
    int lo, hi;
};

struct segment_tree{
    tree m[100010*6];

    void init(int key, int lo, int hi){
        m[key].val = 2e9;
        m[key].lo = lo;
        m[key].hi = hi;
        if(lo == hi-1){
            m[key].val = s[lo];
            return;
        }
        init(key*2, lo, (lo+hi)/2);
        init(key*2+1, (lo+hi)/2, hi);
        m[key].val = min(m[key*2].val, m[key*2+1].val);
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
        m[key].val = min(m[key*2].val, m[key*2+1].val);
    }

    int query(int key, int lo, int hi){
        if(m[key].hi <= lo or hi <= m[key].lo) return 2e9;
        if(lo <= m[key].lo and m[key].hi <= hi) return m[key].val;
        return min(query(key*2, lo, hi), query(key*2+1, lo, hi));
    }

    void trav(int key){
        printf("%d %d %d\n", m[key].lo, m[key].hi, m[key].val);
        if(m[key].lo == m[key].hi-1) return;
        trav(key*2);
        trav(key*2+1);
    }

}sg;

priority_queue<pii, vector<pii>, greater<pii> > Q;

int main(){
int a, b, c, d;
cin >> N;
vector<pii> ans;
REPI(a, N){
    scanf("%d", s+a);
    Q.push(mp(s[a], a));
}
sg.init(1, 0, N+2);
//cout << sg.query(1, 1, 4);
//return 0;
pii p;
int lo, hi, mi;
while(!Q.empty()){
    p = Q.top();
    Q.pop();
    if(p.fi == F.query(p.se)){
        continue;
    }
    int diff = p.fi-F.query(p.se);
    lo = p.se;
    hi = N;
    while(lo < hi){
        mi = lo+(hi-lo+1)/2;
        if(sg.query(1, p.se, mi+1) == p.fi){
            lo = mi;
        }
        else hi = mi-1;
    }
    int r = lo;

    lo = 1;
    hi = p.se;
    while(lo < hi){
        mi = lo+(hi-lo)/2;
        if(sg.query(1, mi, p.se+1) == p.fi){
            hi = mi;
        }
        else lo = mi+1;
    }

    F.update(lo, diff);
    F.update(r+1, -diff);
    REP(a, diff){
        ans.pb(mp(lo, r));
    }
}
printf("%d\n", ans.size());
for(auto p:ans){
    printf("%d %d\n", p.fi, p.se);
}

return 0;
}
