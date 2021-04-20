#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(x,y) for(x=0;x<(int)y;x++)
#define REPI(x,y) for(x=1;x<=(int)y;x++)
#define pii pair<int,int>
#define ll long long
#define ALL(x) (x).begin(),(x).end()

using namespace std;

const ll MOD = 100000000;

int i, N, M, K, k1, k2;
ll dp[205][105][12][2];

int main(){
	int a, b, c, d, n;
	int T;
	cin >> N >> M >> k1 >> k2;
	dp[1][1][1][0] = 1;
	dp[1][0][1][1] = 1;
	for(i=2;i<=N+M;i++){
		for(n=0;n<=N;n++){
			// Insert 0
			if(n!=0){
				for(a=1;a<=k2;a++){
					dp[i][n][1][0] += dp[i-1][n-1][a][1];
				}
				dp[i][n][1][0] %= MOD;
				for(a=2;a<=k1;a++){
					dp[i][n][a][0] += dp[i-1][n-1][a-1][0];
				}
			}
			// Insert 1
			for(a=1;a<=k1;a++){
				dp[i][n][1][1] += dp[i-1][n][a][0];
			}
			dp[i][n][1][1] %= MOD;
			for(a=2;a<=k2;a++){
				dp[i][n][a][1] += dp[i-1][n][a-1][1];
			}
		}
	}

	int ans = 0;
	REPI(a, k1) ans += dp[N+M][N][a][0];
	ans %= MOD;
	REPI(a, k2) ans += dp[N+M][N][a][1];
	cout << ans % MOD;
	return 0;
}
