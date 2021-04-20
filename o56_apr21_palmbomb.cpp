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
#define sz(_x) (int)_x.size()
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

int DBG=1;
int i, n, k, N, M, K;

struct tree{
    pii val, flag_val;
    int lo, hi, flag;
};


struct segment_tree{
    tree m[100010*6];

    void init(int key, int lo, int hi){
        m[key].val = mp(0, 0);
        m[key].lo = lo;
        m[key].hi = hi;
        m[key].flag = 0;
        if(lo == hi-1)return;
        init(key*2, lo, (lo+hi)/2);
        init(key*2+1, (lo+hi)/2, hi);
    }

    void inherit(int key){
        if(!m[key].flag) return;
        m[key].flag = 0;
        m[key].val = m[key].flag_val;
        if(m[key].lo != m[key].hi-1){
            m[key*2].flag_val = m[key].flag_val;
            m[key*2+1].flag_val = m[key].flag_val;
            m[key*2].flag = m[key*2+1].flag = 1;
        }
        m[key].flag_val = mp(0, 0);
    }

    void update(int key, int t, pii val){
        //if(m[key].lo <= t and t < )
        inherit(key);
        if(m[key].lo > t or t >= m[key].hi) return;
        if(m[key].lo == m[key].hi-1){
            m[key].val = val;
            m[key].flag = 1;
            m[key].flag_val = val;
            return;
        }
        update(key*2, t, val);
        update(key*2+1, t, val);
        m[key].val = max(m[key*2].val, m[key*2+1].val);
    }

    pii query(int key, int lo, int hi){
        inherit(key);
        if(m[key].hi <= lo or hi <= m[key].lo) return mp(-2e9, -1);
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
int a, b, c, d, h;
cin >> N;
REP(a, N){
    scanf("%d %d", &c, &d);
}


return 0;
}
