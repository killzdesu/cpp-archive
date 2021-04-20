#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
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
int dp[60][60][60][2];

int main(){
int a, b, c, d;
int T;
cin >> T;
while(T--){
    REP(a, 51)REP(b, 51)REP(c, 51)dp[a][b][c][0] = dp[a][b][c][1] = 0;
    scanf("%d %d", &N, &K);
    dp[N][0][0][0] = 1;
    for(a=N;a>0;a--){
        for(b=N;b>=0;b--){
            for(c=0;c<=N;c++){
                dp[a][b][c][0]%=2009;
                dp[a][b][c][1]%=2009;
                // pop
                if(b)dp[a][b-1][c][0] += dp[a][b][c][0];
                // pass
                dp[a-1][b][c][0] += dp[a][b][c][0] + dp[a][b][c][1];
                // push
                dp[a-1][b+1][c+1][1] += dp[a][b][c][0] + dp[a][b][c][1];
            }
        }
    }
    k = 0;
    for(a=0;a<=N;a++){
        k += dp[0][a][K][0];
        k%=2009;
    }
    printf("%d\n", k);
}


return 0;
}
