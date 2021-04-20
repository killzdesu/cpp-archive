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

int dp[2][50][3][50][3];
int s[51][3010];

int invalid(int x, int y){
    if(x+y < 0 or x+y >= N) return 1;
    return 0;
}

int valid(int x, int y){
    if(x+y < 0 or x+y >= N) return 0;
    return 1;
}

int main(){
//freopen("test_fastfood.in", "r", stdin);
int a, b, c, d, d1, d2, d3, d4;
cin >> N >> M;
int now=0, prev=1;
REP(a, N){
    REP(b, M){
        scanf("%d", &s[a][b]);
    }
}

REP(a, 2) REP(b, N) REP(c, 3) REP(d, N) REP(i, 3){
    dp[a][b][c][d][i] = -2e8;
}
dp[prev][0][1][N-1][1] = s[0][0]+s[N-1][0];
for(i=1;i<M;i++){
    REP(d1, N)REP(d2, N)REP(d3, 2)REP(d4, 2) dp[now][d1][d3][d2][d4] = -2e8;
    for(a=0;a<N;a++){
        for(b=a;b<N;b++){
            if(a!=b) c = s[a][i] + s[b][i];
            else c = s[a][i];
            for(d1=-0;d1<=1;d1++){
                for(d2=0;d2<=1;d2++){
                    if(d1==0 and d2==0){
                        dp[now][a][0][b][0] = dp[prev][a][1][b][1]+c;
                        dp[now][b][0][a][0] = dp[now][a][0][b][0];
                        continue;
                    }
                    for(d3=0;d3<=1;d3++){
                        if(d1==0 and d2!=0){
                            if(valid(b, -1))dp[now][a][0][b][1] = max(dp[now][a][0][b][1], dp[prev][a][1][b-1][d3]+c);
                            if(valid(b, 1))dp[now][a][0][b][1] = max(dp[now][a][0][b][1], dp[prev][a][1][b+1][d3]+c);
                            dp[now][b][1][a][0] = dp[now][a][0][b][1];
                            continue;
                        }
                        if(d1!=0 and d2==0){
                            if(valid(a, -1))dp[now][a][1][b][0] = max(dp[now][a][1][b][0], dp[prev][a-1][d3][b][1]+c);
                            if(valid(a, 1))dp[now][a][1][b][0] = max(dp[now][a][1][b][0], dp[prev][a+1][d3][b][1]+c);
                            dp[now][b][0][a][1] = dp[now][a][1][b][0];
                            continue;
                        }
                        for(d4=0;d4<=1;d4++){
                            for(int x1=-1;x1<=1;x1+=2)for(int x2=-1;x2<=1;x2+=2)
                            if(valid(a, x1) and valid(b, x2)) dp[now][a][1][b][1] = max(dp[now][a][1][b][1], dp[prev][a+x1][d3][b+x2][d4]+c);
                            dp[now][b][1][a][1] = dp[now][a][1][b][1];
                        }
                    }
                }
            }
        }
    }
    swap(now, prev);
}
int mx = 0;
//for(k=0;k<M;k++){
//printf("--------- %d ----------\n", k);
REP(a, N) REP(b, N) REP(c, 3) REP(d, 3){
    mx = max(mx, dp[prev][a][c][b][d]);
//    if(i > 0)printf("%d %d %d %d: %d\n", a, a+c-1, b, b+d-1, i);
}
//}
cout << mx;
return 0;
}
