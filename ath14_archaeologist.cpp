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
int val[305][305], dp[2][305][305];
int now , prev ;
void send(int h, int X, int Y, int x, int y){
    if(x == y){
        dp[now][x][y] = max(dp[now][x][y], val[h+1][x] + dp[prev][X][Y]);
    }
    else {
        dp[now][x][y] = max(dp[now][x][y], val[h+1][x] + val[h+1][y] + dp[prev][X][Y]);
    }
}

int main(){
int a, b, c, d;
cin >> N >> M;
REPI(a, N) REPI(b, M) {
    scanf("%d", &val[a][b]);
}
for(a=1;a<=M;a++)for(b=a;b<=M;b++){
//    dp[1][1][a] = val[1][a];
    //if(a != 1) dp[1][1][a] += val[1][1];
    if(a!=b) dp[1][a][b] = val[1][a] + val[1][b];
    else dp[1][a][b] = val[1][a];
   // if(a!=1) dp[1][1][a] += dp[1][1][a-1];
   //printf("%d ", dp[1][1][a]);
}
//printf("\n");
now = 0; prev = 1;
for(a=1;a<N;a++){
    REPI(b, M)REPI(c, M)dp[now][b][c] = -2e9;
    REPI(b, M){
        for(c=b;c<=M;c++){
            if(dp[prev][b][c] == -2e9) continue;
            send(a, b, c, b+1, c+1);
            send(a, b, c, b+1, c);
            send(a, b, c, b+1, c-1);
            send(a, b, c, b-1, c+1);
            send(a, b, c, b-1, c);
            send(a, b, c, b-1, c-1);
            send(a, b, c, b, c+1);
            send(a, b, c, b, c);
            send(a, b, c, b, c-1);
        }
    }
    swap(now, prev);
//    REPI(b, M) REPI(c, M){
//        dp[a+1][b][c] = max(dp[a+1][b][c], dp[a+1][c][b]);
//        dp[a+1][c][b] = dp[a+1][b][c];
//    }
}
//return 0;
int mx = -2e9;
REPI(a, M){
    mx = max(mx, dp[prev][a][a]);
}
printf("%d", mx);
//cout << dp[1][1][2] <<"\n";
//cout << dp[2][2][2] <<"\n";
//cout << dp[3][2][3] <<"\n";
//cout << dp[4][3][3] <<"\n";
//cout << dp[5][3][4] <<"\n";
//cout << dp[6][4][4] <<"\n";

return 0;
}
