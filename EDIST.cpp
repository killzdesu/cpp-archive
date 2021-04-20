#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back

using namespace std;

int i, n, k, N, M, K;
char s[2010], z[2010];
int dp[2010][2010];

int main(){
int a, b, c, d;
int T;
cin >> T;
while(T--){
    cin >> s+1 >> z+1;
    N = strlen(s+1);
    M = strlen(z+1);
    REPI(a, N) dp[a][0] = a;
    REPI(a, M) dp[0][a] = a;
    REPI(a, N){
        REPI(b, M){
            if(s[a] == z[b]){
                dp[a][b] = dp[a-1][b-1];
            }
            else {
                dp[a][b] = min(dp[a-1][b]+1, dp[a][b-1]+1);
                dp[a][b] = min(dp[a][b], dp[a-1][b-1]+1);
            }
        }
    }
//    REP(a, N+1){
//        REP(b, M+1){
//            printf("%d ", dp[a][b]);
//        }
//        printf("\n");
//    }
    cout << dp[N][M] << "\n";
}

return 0;
}
