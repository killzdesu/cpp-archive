#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back

using namespace std;

int i, n, k, N, M, K;
typedef long long ll;

//map<int, int> m;

vector<int> v;

int fp(int x){
    return distance(v.begin(), lower_bound(v.begin(), v.end(), x));
}

struct question{
    int x, y, z, p;
}q[100010];

struct tree{
    ll val;
    int lo, hi;
    bool flag;
    int flag_val;
};

struct lazy_segment_tree{
    int N;
    tree m[1000000];

    ll find_val(int key, long long x){
        return (v[m[key].hi]-(long long)v[m[key].lo])*x;
    }

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

    void build(int n){
        N = n;
        //m = new tree[5*N+1];
    }

    void inherit(int key){
        if(m[key].flag == 0) return;
        m[key].val = find_val(key, m[key].flag_val);
        if(m[key].lo != m[key].hi-1){
            m[key*2].flag = m[key*2+1].flag = 1;
            m[key*2].flag_val = m[key*2+1].flag_val = m[key].flag_val;
        }
        m[key].flag = 0;
        m[key].flag_val = 0;
    }

    ll query(int key, int lo, int hi){
        inherit(key);
        if(m[key].hi <= lo or hi <= m[key].lo) return 0;
        if(lo <= m[key].lo and m[key].hi <= hi){
//            printf("+%lld: %d %d :: %d\n", m[key].val, v[m[key].lo], v[m[key].hi], m[key].flag_val);
            return m[key].val;
        }
        return query(key*2, lo, hi) + query(key*2+1, lo, hi);
    }

    void update(int key, int lo, int hi, int val){
        inherit(key);
        if(m[key].lo >= hi or lo >= m[key].hi) return;
        if(lo <= m[key].lo and m[key].hi <= hi){
            m[key].val = find_val(key, val);
//            printf(">> %d - %d : %d\n", v[m[key].lo], v[m[key].hi], m[key].val);
            if(m[key].lo != m[key].hi-1){
                m[key*2].flag = 1;
                m[key*2+1].flag = 1;
                m[key*2].flag_val = val;
                m[key*2+1].flag_val = val;
            }
            return;
        }
        update(key*2, lo, hi, val);
        update(key*2+1, lo, hi, val);
        m[key].val = m[key*2].val + m[key*2+1].val;
    }

    void trav(int key){
        inherit(key);
        printf("%d %d| %d\n", m[key].lo, m[key].hi, m[key].val);
        if(m[key].lo == m[key].hi-1) return;
        trav(key*2);
        trav(key*2+1);
    }

}Sg;

int main(){
int a, b, c, d;
cin >> N >> M;
REP(a, M){
    scanf("%d", &q[a].p);
    if(q[a].p == 0){
        scanf("%d %d %d", &q[a].x, &q[a].y, &q[a].z);
        v.pb(q[a].x);
        v.pb(q[a].y);
    }
    else {
        scanf("%d %d", &q[a].x, &q[a].y);
        v.pb(q[a].x);
        v.pb(q[a].y);
    }
}
v.pb(N);
sort(v.begin(), v.end());
v.resize(distance(v.begin(), unique(v.begin(), v.end())));
k = v.size();
//printf(" <\n");

Sg.build(k+2);
Sg.init(1, 0, k+1);

REP(a, M){
//    printf("\n");
    if(q[a].p == 0){
//        printf("Set %d - %d : %d\n", q[a].x, q[a].y, q[a].z);
        Sg.update(1, fp(q[a].x), fp(q[a].y), q[a].z);
    }
    else {
//        printf("Sum %d - %d\n", q[a].x, q[a].y);
        printf("%lld\n", Sg.query(1, fp(q[a].x), fp(q[a].y)));
    }
}
//Sg.trav(1);

return 0;
}
