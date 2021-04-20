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
dp[prev][0][2][N-1][0] = s[0][0]+s[N-1][0];
for(i=1;i<M;i++){
//    REP(d1, N)REP(d2, N)REP(d3, 3)REP(d4, 3) dp[now][d1][d3][d2][d4] = -2e9;
    for(a=0;a<N;a++){
        for(b=a;b<N;b++){
            if(a!=b) c = s[a][i] + s[b][i];
            else c = s[a][i];
//            for(d1=-1;d1<=1;d1++){
//                if(a+d1<0 or a+d1>=N)continue;
//                for(d2=-1;d2<=1;d2++){
////                    if(a+d1+d2<0 or a+d1+d2>=N)continue;
//                    if(d1 == 0 and d2 == 0) continue;
//                    for(d3=-1;d3<=1;d3++){
////                        if(b+d3<0 or b+d3>=N)continue;
//                        for(d4=-1;d4<=1;d4++){
////                            if(b+d3+d4<0 or b+d3+d4>=N)continue;
//                            if(d3 == 0 and d4 == 0) continue;
//                            if(valid(b+d3, d4)){
//                                dp[now][a][d1+1][b][d3+1] = max(dp[now][a][d1+1][b][d3+1], dp[prev][a+d1][d2+1][b+d3][d4+1]+c);
//                                dp[now][b][d3+1][a][d1+1] = dp[now][a][d1+1][b][d3+1];
//                            }
//                        }
//                    }
//                }
//            }
            for(d1=-1;d1<=1;d1++){
                for(d2=-1;d2<=1;d2++){
                    for(d3=-1;d3<=1;d3++){
                        for(d4=-1;d4<=1;d4++){
                            if(invalid(a, d1) or invalid(b, d2) or invalid(a+d1, d3) or invalid(b+d2, d4)) continue;
                            if(d1 == 0 and d3 == 0) continue;
                            if(d2 == 0 and d4 == 0) continue;
                            dp[i][a][d1+1][b][d2+1] = max(dp[i][a][d1+1][b][d2+1], dp[i-1][a+d1][d3+1][b+d2][d4+1]+c);
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
