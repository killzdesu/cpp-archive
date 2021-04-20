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
int dp[1010][11][11];

int main(){
int a, b, c, d;
cin >> N >> K;
REP(a, K){
    dp[0][K][a] = 1;
}
REPI(a, N-1){
    REP(b, K+1)REP(c, K)REP(d, K){
        if(b == c and c == d) continue;
        dp[a][c][d] += dp[a-1][b][c];
        dp[a][c][d] %= 1000000007;
    }
}

REP(b, K+1) REP(a, K+1){
    k += dp[N-1][a][b];
    k %= ((int)1e9+7);
}
cout << k;

return 0;
}
