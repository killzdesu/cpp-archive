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

ll mod;
ll sum;

int s[1010];
ll dp[2][510][510];

int main(){
int a, b, c, d;
int now=1, prev=0;
cin >> N >> M >> K >> mod;
REPI(a, N){
	scanf("%d", &s[a]);
}
REPI(a, N) dp[0][a][0] = 1;
REPI(a, M){
    REP(b, 505) REP(c, 505) dp[now][b][c] = 0;
    REPI(i, N){
		REP(b, K+1){
            if(b+s[i] > K) break;
            dp[now][i][b+s[i]] += dp[prev][i][b];
            dp[now][i][b+s[i]] += dp[prev][i-1][b];
            dp[now][i][b+s[i]] %= mod;
		}
    }
}
REPI(a, N) REP(b, K+1){
	sum += dp[prev][a][b];
    sum %= mod;
}
cout << sum;
return 0;
}
