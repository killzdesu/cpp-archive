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
ll dp[1010][1020];

int main(){
int a, b, c, d;
int T;
cin >> T;
while(T--){
    cin >> N >> M;
    REP(a, 1000) REP(b, 1001) dp[a][b] = 0;
    dp[0][0] = 1;
    for(a=0;a<N;a++){
        for(b=0;b<=M;b++){
            dp[a][b] %= 9241;
            // |
            dp[a+1][b] += dp[a][b];
            // =
            dp[a+2][b] += dp[a][b];
            // []
            if(b<=M-1||1) dp[a+2][b+1] += dp[a][b];
            // |=|
            if(b<=M-2||1){
                for(c=3;c<=N;c++){
                    dp[a+c][b+2] += 2*dp[a][b];
                }
            }
        }
    }
    ll k = 0;
    for(a=0;a<=M;a++){
        k += dp[N][a];
    }
    printf("%lld\n", k% 9241);
}



return 0;
}
