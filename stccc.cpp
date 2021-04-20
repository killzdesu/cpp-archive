#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin(), unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define dump(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;

int i, n, k, N, M, K;
ll dp[501][501];

ll solve(int n, int m){
    if(m == 0) return 0;
    if(n == 0) return 1;
    if(n == m) return 1+solve(n, m-1);
    if(n < m) return solve(n, m-1);
    if(n==1 and m == 1) return 1;
    if(dp[n][m] == -1){
        dp[n][m] = solve(n, m-1)+solve(n-m, m-1);
//        printf("%d %d - %I64d\n", n, m, dp[n][m]);
    }
    return dp[n][m];
}

int main(){
int a, b, c, d;
cin >> N;
memset(dp, -1, sizeof(dp));
cout << solve(N, N)-1;



return 0;
}
