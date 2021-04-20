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
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long

using namespace std;

int i, n, k, N, M, K;
int m[1010][1010];
int dp[1010][1010][3];

int main(){
int a, b, c, d;
cin >> N >> M;
REP(a, N) REP(b, M){
    scanf("%d", &m[a][b]);
//    dp[a][b][0] = dp[a][b][1] = 0;
}
dp[0][0][1] = m[0][0];
REP(a, N) REP(b, M){
    dp[a+1][b][0] = max(dp[a+1][b][0], max(dp[a][b][0], max(dp[a][b][1], dp[a][b][2])));
    dp[a+1][b][1] = max(dp[a+1][b][1], dp[a][b][0]+m[a+1][b]);
    dp[a+1][b][2] = max(dp[a+1][b][2], dp[a][b][1]+m[a+1][b]);
    dp[a][b+1][0] = max(dp[a][b+1][0], max(dp[a][b][0], max(dp[a][b][1], dp[a][b][2])));
    dp[a][b+1][1] = max(dp[a][b+1][1], dp[a][b][0]+m[a][b+1]);
    dp[a][b+1][2] = max(dp[a][b+1][2], dp[a][b][1]+m[a][b+1]);
}
cout << max(dp[N-1][M-1][0], max(dp[N-1][M-1][1], dp[N-1][M-1][2]));

return 0;
}
