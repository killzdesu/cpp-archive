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
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

int i, n, k, N, M, K;
const int mod = 7919;

ll dp[360][360][4];
int pas[1010][1010];
ll dp2[500];

int solve1(int x){
    if(x == 1) return 1;
    if(dp2[x] != 0) return dp2[x];
    int b, a;
    for(a=0;a<=min(2*K, x-2);a++){
        b = K+1-abs(K-a);
        dp2[x] += b;
        dp2[x] %= mod;
    }

    return dp2[x];
}

int solve(int x, int y, int d){
    if(x==0 or y==0) return 1;
    if(x == 1){
        if(d == 0){
            return solve1(max(x, y));
        }
        return 0;
    }
    if(y == 1){
        if(d == 1){
            return solve1(max(x, y));
        }
        return 0;
    }
    if(dp[x][y][d] != 0) return dp[x][y][d];
    int a, b, i;
    if(d!=0){
        for(a=1;a<=min(2*K, x-1);a++){
            b = K+1-abs(K-a);
//            printf("%d %d %d: += %d\n", x, y, d, solve(x-a, y, 0)*b);
            dp[x][y][d] += (ll)solve(x-a, y, 0)*b;
            if(a == x-1) dp[x][y][d] -= b;
            dp[x][y][d] %= mod;
        }
        if(x <= K){
            dp[x][y][d]++;
        }
    }
    if(d!=1){
        for(a=1;a<=min(2*K, y-1);a++){
            b = K+1-abs(K-a);
//            printf("%d %d %d: += %d\n", x, y, d, solve(x, y-a, 1)*b);
            dp[x][y][d] += (ll)solve(x, y-a, 1)*b;
            if(a == y-1) dp[x][y][d] -= b;
            dp[x][y][d] %= mod;
        }
        if(y <= K) dp[x][y][d]++;
    }
    return dp[x][y][d];
}

int main(){
int a, b, c, d;
cin >> N >> M >> K;
REPI(a, 1000){
    pas[a][0] = 1;
    REPI(b, a-1){
        pas[a][b] = pas[a-1][b-1]+pas[a-1][b];
        pas[a][b] %= mod;
    }
    pas[a][a] = 1;
}
cout << solve(N, M, 0)+solve(N, M, 1) << "\n";
dump(dp[3][2][0]);
return 0;
}
