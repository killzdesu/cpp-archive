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

const ll mod = 1000003;

int s[120][120];
ll t[120][120][34];
ll dp[120][120];
ll pow2[50];

void make_t(int x){
    int a, b;
	REP(a, 110) REP(b, 110) dp[a][b] = 0;
    dp[x][0] = 1;
    for(b=0;b<M-1;b++){
		for(a=0;a<N;a++){
			if(s[a][b] == 0){
                dp[a][b] = 0;
				continue;
			}
            if(a){
				dp[a-1][b+1] += dp[a][b];
				dp[a-1][b+1] %= mod;
            }
            dp[a][b+1] += dp[a][b];
            dp[a][b+1] %= mod;
            if(a != N-1){
				dp[a+1][b+1] += dp[a][b];
				dp[a+1][b+1] %= mod;
            }
		}
    }
//    printf("----%d----\n", x);
//    REP(a, N) REP(b, M) cout << dp[a][b] << " \n"[b==M-1];
    REP(a, N){
    	if(s[a][M-1] == 1) t[x][a][0] = dp[a][M-1] % mod;
		else t[x][a][0] = 0;
    }
}

ll ans[120][120];
ll tmp[120][120];

int main(){
//freopen("hell.txt", "r", stdin);
int a, b, c, d;
pow2[0] = 1;
REPI(a, 34) pow2[a] = pow2[a-1]*2;
ll K;
cin >> N >> M >> K;
REP(a, N) REP(b, M) scanf("%d", &s[a][b]);

REP(a, N) make_t(a);
//return 0;

REPI(k, 32){
    REP(a, N) REP(b, N) REP(c, N){
        t[a][b][k] += t[a][c][k-1]*t[c][b][k-1];
        t[a][b][k] %= mod;
    }
}
//REP(a, N) REP(b, N) cout << t[a][b][0] << " \n"[b==N-1];

REP(a, N) ans[a][a] = 1;
int first = 1;
for(k = 31; k>=0; k--){
    if(pow2[k] > K) continue;
    K -= pow2[k];
//    if(first){
//		REP(a, N) REP(b, N) ans[a][b] = t[a][b][k];
//        first = 0;
//        continue;
//    }
    REP(a, N) REP(b, N) tmp[a][b] = 0;
    REP(a, N) REP(b, N){
        REP(c, N){
            tmp[a][b] += ans[a][c]*t[c][b][k];
            tmp[a][b] %= mod;
        }
	}
	REP(a, N) REP(b, N) ans[a][b] = tmp[a][b];
}


REP(a, N){
    ll sm = 0;
    REP(b, N) sm += ans[a][b], sm %= mod;
    printf("%lld\n", sm);
}

return 0;
}
