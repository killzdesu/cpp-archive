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
int sr[100010];

bool cmp(int a, int b){
    return s[a] < s[b];
}

struct tree{
    set<int> val;
    int lo, hi;
};


struct segment_tree{
    tree m[100010*6];

    void init(int key, int lo, int hi){
        m[key].val.clear();
        m[key].lo = lo;
        m[key].hi = hi;
        if(lo == hi-1)return;
        init(key*2, lo, (lo+hi)/2);
        init(key*2+1, (lo+hi)/2, hi);
    }

    void update(int key, int t, int val){
        if(m[key].lo > t or t >= m[key].hi) return;
        if(m[key].lo == m[key].hi-1){
            m[key].val.insert(val);
            return;
        }
        update(key*2, t, val);
        update(key*2+1, t, val);
        m[key].val.insert(val);
    }
//
//    int query(int key, int lo, int hi){
//        if(m[key].hi <= lo or hi <= m[key].lo) return -2e9;
//        if(lo <= m[key].lo and m[key].hi <= hi) return m[key].val;
//        return max(query(key*2, lo, hi), query(key*2+1, lo, hi));
//    }

}sg;

map<int, int> m;
int t[100010];

int main(){
int a, b, c, d;
cin >> N >> M;
REP(a, N){
    scanf("%d", s+a);
    sr[a] = a;
}
sort(sr, sr+N, cmp);
REP(a, N) m[s[sr[a]]] = a+1;
sg.init(1, 0, N+2);
REP(a, N){
   sg.update(1, a, m[s[a]]);
}

return 0;
}
