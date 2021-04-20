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

int val[1010];
int dp[1010][1010][2];

int main(){
int a, b, c, d;
cin >> N >> K;
REPI(a, N){
	scanf("%d", &val[a]);
}
REP(a, N+1){
    dp[0][a][0] = dp[0][a][1] = 0;
}
REPI(a, N){
//	printf("----%d-----\n", a);
    REP(b, K+1){
        maxa(dp[a][b][0], max(dp[a-1][b][0], dp[a-1][b][1]));
        dp[a][b][1] = max(dp[a][b][1], dp[a-1][b][0] + val[a]);
        dp[a][b+1][1] = max(dp[a][b+1][1], dp[a-1][b][1] + val[a]);
    }
//    REP(b, K+1){
//		printf("%d: %d %d\n", b, dp[a][b][0], dp[a][b][1]);
//    }
}
int mx = 0;
REP(a, K+1) maxa(mx, dp[N][a][0]);
REP(a, K+1) maxa(mx, dp[N][a][1]);
cout << mx;
return 0;
}
