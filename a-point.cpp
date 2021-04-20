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

ll dp[700][700];
int chk[700][700];
int s[1000];

ll solve(int lo, int hi){
	if(lo == hi) return 0;
	if(chk[lo][hi]) return dp[lo][hi];
	chk[lo][hi] = 1;
	int a;
	ll mx = 0, val, A, B;
	for(a=lo+1;a<=hi;a++){
        A = s[a-1]-s[lo-1];
        B = s[hi]-s[a-1];
        if(A > B) swap(A, B);
        val = A*2+B;
        mx = max(mx, solve(lo, a-1)+solve(a, hi)+val);
	}
	dp[lo][hi] = mx;
//	printf("%d %d- %d\n", lo, hi, mx);
	return mx;
}

int main(){
freopen("apapapap.txt", "r", stdin);
int a, b, c, d;
cin >> N;
REPI(a, N){
	scanf("%d", &s[a]);
	s[a] += s[a-1];
}

REPI(a, N) dp[a][a] = 0;
int A, B, val;
for(i=2;i<=N;i++){
	for(a=1;a<=N;a++){
        for(b=0;b<i-1;b++){
			A = s[a+b]-s[a-1];
			B = s[a+i-1]-s[a+b];
			if(A > B) swap(A, B);
			val = A*2+B;
            maxa(dp[a][a+i-1], dp[a][a+b]+dp[a+b+1][a+i-1]+val);
        }
	}

}
cout << dp[1][N];
//cout << solve(1, N);


return 0;
}
