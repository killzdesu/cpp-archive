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

ll power[62];

int main(){
int a, b, c, d;
cin >> K >> M;
power[0] = 1;
REPI(a, K){
    power[a] = power[a-1]*2;
}
pair<ll, int> X, Y;
ll t, lo, now, df;
int cnt;
while(M--){
    cnt =0;
//    cin >> X.fi >> X.se >> Y.fi >> Y.se;
    scanf("%lld %d %lld %d", &X.fi, &X.se, &Y.fi, &Y. se);
    if(X.se > Y.se) swap(X, Y);

    while(1){
        now = power[Y.se];
        lo = Y.fi/now;
        lo = lo * now;
        if(X.fi < lo or X.fi >= lo + now) Y.se++;
        else break;
        cnt++;
    }

    while(X.se != Y.se){
        t = power[Y.se-1];
        now = power[Y.se];
        lo = Y.fi/now;
        lo = lo * now;
        if(lo + t > X.fi){
            if(Y.fi >= lo+t) Y.fi -= t;
        }
        else {
            if(Y.fi < lo+t) Y.fi += t;
        }
        Y.se--;
        cnt++;
    }
    df = abs(X.fi-Y.fi);
    if(df == 0){
        printf("%d\n", cnt);
        continue;
    }
    lo = (df&-df);
    lo = (ll)log2((double)lo);
//    dump(cnt);
    printf("%lld\n", 2*(X.se-lo)+cnt);
}


return 0;
}
