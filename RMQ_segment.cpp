#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#define DB if(DBG)printf
#define IT iterator
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

int DBG=0;
int i, n, k, N, M, K;

struct tree{
    int val;
    int lo, hi;
};

int s[100010];
vector<int> z;

struct segment_tree{
    tree m[100010*6];

    void init(int key, int lo, int hi){
        m[key].val = s[lo];
        m[key].lo = lo;
        m[key].hi = hi;
        if(lo == hi-1)return;
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

struct sparse_table{
    int *m;
    int a, b, N, LN, c;
    int M[100010][18];

    void init(int *s, int N){
        m = s;
        LN = (int)ceil(log2(N));
        REP(a, N){
            M[a][0] = a;
        }
        REPI(b, LN){
            c = (1<<b);
            for(a=0;a+c-1<N;a++){
                if(m[M[a][b-1]] < m[M[a+c/2][b-1]]) M[a][b] = M[a][b-1];
                else M[a][b] = M[a+c/2][b-1];
            }
        }
    }

    int query(int lo, int hi){
        int k = (int)floor(log2(hi-lo+1));
//        DB(">> %d\n", k);
        if(m[M[lo][k]] < m[M[hi-(1<<k)+1][k]]) return m[M[lo][k]];
        else return m[M[hi-(1<<k)+1][k]];
    }
}ST;

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    cin >> s[a];
}
int Q;

//sg.init(1, 0, N);
ST.init(s, N);

cin >> Q;
while(Q--){
    scanf("%d %d", &c, &d);
    printf("%d\n", ST.query(c, d));
}

return 0;
}
