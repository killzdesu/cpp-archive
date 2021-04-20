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
int dp[2][5010];

int main(){
int a, b, c, d, X, Y;
int T, prev=1, now=0;
//cin >> T;
//while(T--){
    cin >> N >> K;
    REP(a, 2003) dp[1][a] = 2e9;
    dp[1][1000] = 0;
    prev = 1; now = 0;
    REP(i, N){
        scanf("%d %d", &X, &Y);
        for(a=1000-K-5;a<=1000+K+5;a++)dp[now][a] = 2e9;
        for(a=1000-K;a<=1000+K;a++){
            dp[now][a+1] = min(dp[now][a+1], dp[prev][a] + X);
            if(a!=0)dp[now][a-1] = min(dp[now][a-1], dp[prev][a] + Y);
        }
        swap(now, prev);
    }
    k = 2e9;
    for(a=1000-K;a<=1000+K;a++){
//        if(a-(N-a)>K or (N-a)-a>K) continue;
        k = min(k, dp[prev][a]);
//        printf("%d -- %d\n", a-200, dp[prev][a]);
    }
    printf("%d\n", k);
//}


return 0;
}
