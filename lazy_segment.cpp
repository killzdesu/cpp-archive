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

struct tree{
    int val;
    int lo, hi;
    int flag;
    int flag_val;
};

struct lazy_segment_tree{
    int N;
    tree m[100010*6];

    void init(int key, int lo, int hi){
        m[key].val = 0;
        m[key].lo = lo;
        m[key].hi = hi;
        m[key].flag = 0;
        if(lo == hi-1)return;
        init(key*2, lo, (lo+hi)/2);
        init(key*2+1, (lo+hi)/2, hi);
    }

    void inherit(int key){
        if(m[key].flag == 0) return;
        m[key].val = m[key].flag_val;
        if(m[key].lo != m[key].hi-1){
            m[key*2].flag = m[key*2+1].flag = 1;
            m[key*2].flag_val = m[key*2+1].flag_val = m[key].flag_val;
        }
        m[key].flag = 0;
    }

    void update(int key, int lo, int hi, int val){
        //if(m[key].lo <= t and t < )
        if(m[key].lo >= hi or lo >= m[key].hi) return;
        inherit(key);
        if(lo <= m[key].lo and m[key].hi <= hi){
            m[key].val = val;
            m[key].flag = 1;
            m[key].flag_val = val;
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

int main(){
int a, b, c, d;
cin >> N >> M;
char C[2];
Sg.init(1, 0, N+2);

//Sg.trav(1);

return 0;
}
