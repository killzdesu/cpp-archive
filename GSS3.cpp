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

struct tree{
    int sum, left, right, mx;
    int lo, hi;
};

int s[100100];


struct segment_tree{
    tree m[100010*6];

    tree combine(tree x, tree y){
        tree t;
        t.sum = x.sum + y.sum;
        t.left = max(x.left, x.sum+y.left);
        t.right = max(x.right+y.sum, y.right);
        t.mx = max(max(x.mx, y.mx), x.right+y.left);
        t.lo = min(x.lo, y.lo);
        t.hi = max(x.hi, y.hi);
        return t;
    }

    void init(int key, int lo, int hi){
        m[key].lo = lo;
        m[key].hi = hi;
        if(lo == hi-1){
            m[key].sum = s[lo];
            m[key].mx = s[lo];
            m[key].left = s[lo];
            m[key].right = s[lo];
            return ;
        }
        init(key*2, lo, (lo+hi)/2);
        init(key*2+1, (lo+hi)/2, hi);
        m[key] = combine(m[key*2], m[key*2+1]);
        m[key].lo = lo;
        m[key].hi = hi;
    }

    void update(int key, int t, int val){
        if(t >= m[key].hi or t < m[key].lo) return;
        if(m[key].lo == m[key].hi-1){
            m[key].sum = val;
            m[key].left = val;
            m[key].right = val;
            m[key].mx = val;
            return;
        }
        update(key*2, t, val);
        update(key*2+1, t, val);
        m[key] = combine(m[key*2], m[key*2+1]);
    }

    tree query(int key, int lo, int hi){
        if(lo <= m[key].lo and m[key].hi <= hi) return m[key];
//        printf("%d %d ", lo, hi);
        int mi = (m[key].hi+m[key].lo)/2;
//        printf("----- %d\n", mi);
        if(hi <= mi) return query(key*2, lo, hi);
        if(lo >= mi) return query(key*2+1, lo, hi);
        return combine(query(key*2, lo, hi), query(key*2+1, lo, hi));
    }

}sg;

int main(){
int a, b, c, d;
cin >> N;
REP(a, N) cin >> s[a];
sg.init(1, 0, N);
cin >> M;
while(M--){
    scanf("%d %d %d", &b, &c, &d);
    if(b)printf("%d\n", (sg.query(1, c-1, d)).mx);
    else sg.update(1, c-1, d);
}


return 0;
}
