#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
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

using namespace std;

int i, n, k, N, M, K;

int dp[102][101][11][102];

int main(){
int a, b, c, d;
int now, prev;
cin >> N >> K;
REPI(a, 9){
    dp[1][1][a][1] = 1;
}
int n1, n2;
for(a=2;a<=N;a++){
    for(n1=0;n1<10;n1++){
        for(n2=0;n2<10;n2++){
            if(n2 > n1){
                REPI(k, K){
                    REPI(b, k){
                        dp[a][k][n2][1] += dp[a-1][k][n1][b];
                        dp[a][k][n2][1] %= 1000000007;
                    }
                }
            }
            else {
                REPI(k, K){
                    REPI(b, k){
                        if(b < k){
                            dp[a][k][n2][b+1] += dp[a-1][k][n1][b];
                            dp[a][k][n2][b+1] %= 1000000007;
                        }
                        else if(b == k){
                            dp[a][k+1][n2][b+1] += dp[a-1][k][n1][b];
                            dp[a][k+1][n2][b+1] %= 1000000007;
                        }
                    }
                }
            }
        }
    }
}
ll sm=0;
REP(a, 10){
    REP(b, K+1){
        sm += dp[N][K][a][b];
        sm %= 1000000007;
    }
}
cout << sm;

return 0;
}
