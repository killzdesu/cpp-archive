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

int DBG=1;
int i, n, k, N, M, K;

struct trip{
    int x, y, z;
    trip(){}
    trip(int a, int b, int c){
        x = a; y = b; z = c;
    }
    bool operator < (const trip &b) const{
        if(x!=b.x)return x > b.x;
        if(x!=b.y)return y > b.y;
        return z > b.z;
    }
}T[100010];

struct tree{
    int val;
    int lo, hi;
};

struct segment_tree{
    tree m[100010*6];


    void init(int key, int lo, int hi){
        m[key].val = -1;
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

vector<int> z;

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    scanf("%d %d %d", &T[a].x, &T[a].y, &T[a].z);
    z.pb(T[a].y);
}
sort(z.begin(), z.end());
z.resize(distance(z.begin(), unique(z.begin(), z.end())));

sg.init(1, 0, z.size());
sort(T, T+N);
REP(a, N){
    c = distance(z.begin(), lower_bound(z.begin(), z.end(), T[a].y));
    d = sg.query(1, c, z.size());
    if(d >= T[a].z) k++;
    sg.update(1, c, max(T[a].z, sg.query(1, c, c+1)));
}
cout << k;
return 0;
}
