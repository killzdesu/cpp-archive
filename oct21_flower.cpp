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
int dp[105][105][110];

int main(){
int a, b, c, d, e;
REP(a, 104)REP(b, 104)REP(c, 104) dp[a][b][c] = -1;
cin >> M >> N;
dp[0][0][0] = 0;
REP(i, N){
    scanf("%d %d %d", &k, &d, &e);
    for(b=M;b>=0;b--){
        for(a=N;a>=0;a--){
            for(c=N;c>=0;c--){
                if(dp[b][a][c] == -1)continue;
                if(b+k <= M){
                    if(e == 1)
                        dp[b+k][a+1][c] = max(dp[b+k][a+1][c], dp[b][a][c]+d);
                    else
                        dp[b+k][a][c+1] = max(dp[b+k][a][c+1], dp[b][a][c]+d);
                }
            }
        }
    }
}
//printf("%d\n", dp[2][2][0]);
k = 0;
for(a=0;a<=N;a++){
    for(c=0;c<=N;c++){
        if(c>a*2+2 or a>c*2+2)continue;
//        printf("%d %d\n", a, b);
        for(b=0;b<=M;b++){
            k = max(k, dp[b][a][c]);
            //if(k == 2200)printf("%d %d: %d\n", b, a, dp[][b][a]);
        }
    }
}
cout << k;

return 0;
}
