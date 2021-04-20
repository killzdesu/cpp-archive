#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<set>
#include<vector>
#include<iostream>
#include<cmath>
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

struct tree {
    int lo, hi, flag, flag_val;
    ll val;
};

//vector<int> z;
ll z[1000000];

struct seg_tree{
    tree m[6*100010];
    int N;

    void build(int x){N = x;}

    ll getv(int key){
        return z[m[key].hi]-z[m[key].lo];
    }

    void init(int key, int lo, int hi){
        m[key].lo = lo;
        m[key].hi = hi;
        m[key].val = getv(key);
        m[key].flag = 0;
        m[key].flag_val = 0;
//        printf("%d[%d - %d]: %d\n", key, z[m[key].lo], z[m[key].hi], m[key].val);
        if(lo == hi-1)return;
        init(key*2, lo, (lo+hi)/2);
        init(key*2+1, (lo+hi)/2, hi);
    }

    void inherit(int key){
        if(m[key].flag == 0) return;
        m[key].flag = 0;
        if(m[key].flag_val == 0){
            return;
        }
        m[key].val = getv(key)-m[key].val;
        if(m[key].lo != m[key].hi-1){
            m[key*2].flag = m[key*2+1].flag = 1;
            m[key*2].flag_val ^= 1;
            m[key*2+1].flag_val ^= 1;
        }
        m[key].flag_val = 0;
    }

    void update(int key, int l, int r){
        inherit(key);
        if(m[key].hi <= l or m[key].lo >= r) return;
        if(l <= m[key].lo and m[key].hi <= r){
            m[key].val = getv(key)-m[key].val;
            m[key*2].flag = m[key*2+1].flag = 1;
            m[key*2].flag_val ^= 1;
            m[key*2+1].flag_val ^= 1;
//            printf("end at [%lld-%lld]\n", z[m[key].lo], z[m[key].hi]);
//            printf("[%lld-%lld] --> %d\n", z[m[key*2].lo], z[m[key*2].hi], m[key*2].flag_val);
//            printf("m[%d] = %d\n", key*2, m[key*2].flag_val);
            return;
        }
        update(key*2, l, r);
        update(key*2+1, l, r);
        m[key].val = m[key*2].val + m[key*2+1].val;
    }

    ll query(int key, int l, int r){
        inherit(key);
        if(m[key].hi <= l or m[key].lo >= r) return 0;
        if(l <= m[key].lo and m[key].hi <= r){
            return m[key].val;
        }
        return query(key*2, l, r) + query(key*2+1, l, r);
    }

    void trav(int key){
//        inherit(key);
        printf("[%lld-%lld] %lld  -%d \n", z[m[key].lo], z[m[key].hi], m[key].val, m[key].flag_val);
        if(m[key].lo == m[key].hi-1){
            return;
        }
        trav(key*2);
        trav(key*2+1);
    }
}sg;

ll Q[100010];
set<int> S;
set<int>::iterator it, is;
int L;
int main(){
int a, b, c, d;
cin >> L >> N;
z[k++] = 0;
z[k++] = L;
REP(a, N){
    scanf("%d", &c);
    Q[a] = c;
    z[k++] = c;
}
sort(z, z+k);
k = distance(z, unique(z, z+k));
z[k+1] = z[k] = L;
//REP(a, k){
//    printf("%d ", z[a]);
//}
//printf("\n\n\n");
sg.build(k);
sg.init(1, 0, k);
S.insert(0);
S.insert(L);
//cout << sg.query(1, 0, k);
//sg.trav(1);
for(a=0;a<N;a++){
//    it = S.lower_bound(Q[a]);
    c = distance(z, lower_bound(z, z+k, Q[a]));
//    d = distance(z, lower_bound(z, z+k, (*it)));
//    S.insert(Q[a]);
//    printf("------------------\n");
//    printf("> %d %d  [%lld - %lld]\n", c, k, z[c], z[k]);
    sg.update(1, c, k);
//    printf(">> %d\n", sg.m[10].flag_val);
//    sg.trav(1);
    printf("%lld\n", sg.query(1, 0, k));
}

return 0;
}
