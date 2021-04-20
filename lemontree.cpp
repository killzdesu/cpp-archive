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

ll dp[20010];

int main(){
int a, b, c, d;
ll mod = 909091;

dp[0] = 1;
dp[1] = 1;
dp[2] = 2;
dp[3] = 5;
N = 10000;
cin >> N;
for(i=4;i<=N;i++){
	for(a=1;a<=(i+1)/2;a++){
        b = (a-1 != i-a) ?2:1;
        dp[i] += (dp[a-1]*dp[i-a]*b) % mod;
	}
	dp[i] %= mod;
}
freopen("xx.cpp", "w", stdout);
printf("{");
REP(a, 10001) printf("%lld, ", dp[a]);
printf("}");


return 0;
}
