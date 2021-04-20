#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin(), unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define dump(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

int i, n, k, N, M, K;
ll T, H;
ll sm;
ll dp2[1000010];
int chk2[1000010];

ll iftry(int lo, int hi){
    if(lo > hi) return 0;
    return (hi-lo+1)*T;
}

ll run(int lo, int hi){
    int mi = (lo+hi)/2;
    if(lo == hi) return T;
    if(lo == hi-1) return T*2;
    if(lo > hi) return 0;
    if(chk2[hi-lo]) return dp2[hi-lo];
    chk2[hi-lo] = 1;
    ll tt = iftry(lo, hi);
    ll A = 2e15;
    int a = 0;
//    printf("%d %d\n", lo, hi);
    for(mi = lo; mi <= hi; mi++){
//        dump(mi);
        ll left = T+H+run(lo, mi-1);
        ll right = T+run(mi+1, hi);
        if(mina(A, max(left, right))){}
    }
//    if(lo == 2 and hi == N-1){
//        for(i = lo; i<= hi; i++){
//            ll left = T+H+run(lo, i-1);
//            ll right = T+run(i+1, hi);
////            if(max(left, right) == A) printf(".%d ", i);
//        }
//    }
    return dp2[hi-lo] = min(tt, A);
}

ll run2(int lo, int hi){
    int mi = (lo+hi)/2;
    if(lo == hi) return T;
    if(lo == hi-1) return T*2;
    if(lo > hi) return 0;
    ll tt = iftry(lo, hi);
    ll A = 2e15;
    int a = 0;
//    printf("> %d %d\n", lo, hi);
    mi = (lo+hi-H/T)/2;
    for(mi = max(lo, mi-2); mi <= hi and a < 5; a++, mi++){
//        dump(mi);
        ll left = T+H+run2(lo, mi-1);
        ll right = T+run2(mi+1, hi);
        A = min(A, max(left, right));
    }
    return min(tt, A);
}

int main(){
//freopen("mount.txt", "r", stdin);
int a, b, c, d;
cin >> N >> H >> T;
//solve(2, N-1, 0);
//cout << sm;
    cout << run(2, N-1);

return 0;
return 0;
}
