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

const int mod = 1000000009;

struct edge{
	int x, y, w;
};

int C[2][70][1100];
vector<edge> E;
int ans[110];
vector<pii> v[70];

int main(){
int now=1, prev=0;
int a, b, c, d;
cin >> N >> M >> K;
if(K > 2000) assert(1!=1);
//return 0;
REP(a, M){
	scanf("%d %d %d", &c, &d, &b);
    v[c].pb({d, b});
    v[d].pb({c, b});
    E.pb({c, d, b});
}
C[0][1][0] = 1;
if(K == 0){
	cout << 1;
	return 0;
}
for(int xx=0;xx<1000;xx++){
	REPI(a, N) REP(b, 1001) C[now][a][b] = 0;
    for(auto e: E){
		for(b=0;b<K+2;b++){
			C[now][e.x][b+e.w] += C[prev][e.y][b];
			C[now][e.x][b+e.w] %= mod;
			C[now][e.y][b+e.w] += C[prev][e.x][b];
			C[now][e.y][b+e.w] %= mod;
		}
    }
    REPI(a, N){
    	ans[a] += C[now][a][K];
    	ans[a] %= mod;
    }
    swap(now, prev);
//    REPI(a, N){
//    printf("%d ", ans[a]%mod);
//	}EL;
}
REPI(a, N){
    printf("%d\n", ans[a]%mod);
}

return 0;
}
