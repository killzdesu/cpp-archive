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

int dp[1000];
int dp2[1000];
int s[50];

int MX(int x){
    if(x <= M) return x;
    if(x <= M+N-1) return x-M+1;
    if(x <= 2*M+N-2) return x-M+1-N+1;
    return x-M-N-M+3;
}

int main(){
int a, b, c, d;
cin >> K >> N >> M;
REP(a, K) cin >> s[a];
int A = (M+N)*2-4;
dp[0] = 1;
REPI(a, A){
    REP(b, K){
        if(s[b] <= a and s[b] <= MX(a)){
            dp[a] += dp[a-s[b]];
            dp[a] %= 9661;
        }
    }
}

dp2[1] = 1;
for(a=2;a<A;a++){
    REP(b, K){
        if(s[b] < a and s[b] <= MX(a)){
            dp2[a] += dp2[a-s[b]];
            dp2[a] %= 9661;
        }
    }
}

int sm = dp[A];
REP(a, K){
    if(s[a] == 1) continue;
    if(s[a] > N) continue;
    sm += dp2[A-s[a]+1];
    sm %= 9661;
}
//cout << (dp[A]+dp[A-2])%9661;
cout << sm;
return 0;
}
