#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#define DB if(DBG)printf
#define IT iterator
#define all(x) x.begin(),x.end()
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()
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

int DBG=1;
int i, n, k, N, M, K;
int A[5010][5010];
int dp[5010][5010];

int main(){
int a, b, c, d;
cin >> N;
REPI(a, N){
    for(b=a+1;b<=N;b++) scanf("%d", &A[a][b]);
}
int j;
REPI(a, N)REPI(b, N) dp[a][b] = 2e9;
dp[1][1] = 0;
dp[2][1] = A[1][2];
dp[1][2] = A[1][2];
for(i=3;i<N;i++){
    for(j=1;j<i;j++){
        if(j == i-1){
            for(a=1;a<j;a++){
                dp[i][j] = min(dp[i][j], dp[a][j]+A[a][i]);
                dp[j][i] = min(dp[j][i], dp[a][j]+A[a][i]);
            }
        }
        else {
            dp[i][j] = min(dp[i][j], dp[i-1][j]+A[i-1][i]);
            dp[j][i] = min(dp[j][i], dp[j][i-1]+A[i-1][i]);
        }
    }
}
//REPI(a, N) REPI(b, N){
//    printf("%d %d:: %d\n", a, b, dp[a][b]);
//}
k = 2e9;
REPI(a, N-2){
    k = min(k, dp[N-1][a]+A[N-1][N]+A[a][N]);
}
cout << k;
return 0;

}
