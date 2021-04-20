#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;

int i, n, k, N, M, K;
ll A, B;
ll t, m;

int can(int l, int r){
    ll sm = ((A+(ll)(l-1)*B)+(A+(ll)(r-1)*B))*(r-l+1)/2;
    if(sm <= t*m and (A+(ll)(r-1)*B) <= t) return 1;
    return 0;
}


int main(){
int a, b, c, d;
int l, r, lo, hi, mi;
cin >> A >> B >> N;
int zz;
REP(zz, N){
    scanf("%d %d %d", &l, &t, &m);
    lo = l;
    hi = 20000020;
    while(lo < hi){
        mi = lo+(hi-lo+1)/2;
        if(can(l, mi)){
            lo = mi;
        }
        else {
            hi = mi-1;
        }
    }
    if(can(l, lo)) printf("%d\n", lo);
    else printf("-1\n");
}

return 0;
}
