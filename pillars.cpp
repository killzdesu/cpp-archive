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
};

template <typename SomeType, typename comp = std::less<SomeType> >
struct segment_tree{
    int N;
    tree m[100010*6];

    void build(int n){
        N = n;
    }

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
        m[key].val = comp(m[key*2].val, m[key*2+1].val);
    }

    int query(int key, int lo, int hi){
        if(m[key].hi <= lo or hi <= m[key].lo) return -2e9;
        if(lo <= m[key].lo and m[key].hi <= hi) return m[key].val;
        return comp(query(key*2, lo, hi), query(key*2+1, lo, hi));
    }
    void trav(int key){
        printf("%d %d| %d\n", m[key].lo, m[key].hi, m[key].val);
        if(m[key].lo == m[key].hi-1) return;
        trav(key*2);
        trav(key*2+1);
    }

};



struct cmax{
    int operator() (const int& x, const int& y) const {return max(x, y);}
};

template<typename SomeType, typename Comparator>
struct heap
{
    int x, y;
    Comparator comp;
    void set(int a, int b){
        x = a;
        y = b;
    }
    void print(){
//        if(comp(x, y)) printf("%d more !", x);
//        else printf("%d more !", y);
        printf("%d", comp(x, y));
    }
};

int main(){
int a, b, c, d;
//cin >> N >> M;
char C[2];
//segment_tree<int, less<int> > Sg;
//Sg.init(1, 0, N+2);
//REP(a, M){
//    scanf("%s %d %d", C, &c, &d);
//    if(C[0] == 'U') Sg.update(1, c, d);
//    if(C[0] == 'P') printf("%d\n", Sg.query(1, c, d+1));
//}
////Sg.trav(1);
heap<int, cmax > h;
h.set(2, 1);
h.print();
return 0;
}
