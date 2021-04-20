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
int C[110], A[110][110], B[110];
int dp[110][110][110];
int use[110][110];

int prev(int k){
	if(k == 1) return K;
	return k-1;
}
priority_queue<pii, vector<pii>, greater<pii> > Q;

int vs[200];

void spread(int lo, int hi){
    while(!Q.empty()) Q.pop();
    int a, b, c;
//    fill(vs, vs+105, 0);
    pii t;
    c = -1;
    REPI(a, K){
		if(c == -1 or dp[lo][hi][a] < dp[lo][hi][c]) c = a;
    }
    Q.push({dp[lo][hi][c], c});
    while(!Q.empty()){
		t = Q.top();
		Q.pop();
        if(vs[t.se] == 1) continue;
        vs[t.se] = 1;
        mina(dp[lo][hi][t.se], t.fi);
        REPI(a, K){
        	if(vs[a] == 1) continue;
            if(t.fi + A[t.se][a] > dp[lo][hi][a]) continue;
            Q.push({t.fi + A[t.se][a], a});
        }
    }
}

pii p[110];

void ans(int lo, int hi){
//	if(dp[lo][hi][k] != 0 ) return dp[lo][hi][k];
	if(use[lo][hi]) return;
//	printf("%d %d\n", lo, hi);
	use[lo][hi] = 1;
	for(int a=lo+1;a<hi;a++){
		ans(lo, a);
		ans(a, hi);
	}
	for(int k = 1; k<= K; k++){
		if(lo == hi-1){
			if(k != C[lo]) dp[lo][hi][k] = A[C[lo]][k];
            else dp[lo][hi][k] = 0;
            continue;
		}
		dp[lo][hi][k] = 2e9;
		for(int a=lo+1;a<hi;a++){
			dp[lo][hi][k] = min(dp[lo][hi][k], dp[lo][a][prev(k)]+dp[a][hi][prev(k)]+B[prev(k)]);
		}
	}
//	for(int c=0;c<40;c++){
//    for(int a=1;a<=K;a++){
//		for(int b=1;b<=K;b++){
//			if(a == b) continue;
//            dp[lo][hi][a] = min(dp[lo][hi][a], dp[lo][hi][b]+A[b][a]);
//		}
//    }
//	}

//	spread(lo, hi);

    for(int a=1;a<=K;a++) p[a-1] = {dp[lo][hi][a], a};
    sort(p, p+K);
    for(int a=0;a<K;a++){
		int c = -1;
        for(int b=a;b<K;b++) if(c == -1 or p[b].fi < p[c].fi) c = b;
        swap(p[a], p[c]);
        for(int b=a+1;b<K;b++){
            mina(p[b].fi, p[a].fi + A[p[a].se][p[b].se]);
        }
    }
    for(int a=0;a<K;a++) dp[lo][hi][p[a].se] = p[a].fi;
//    for(int a=0;a<K;a++){
//		for(int b=0;b<a;b++){
//			if(a == b) continue;
//            dp[lo][hi][p[a].se] = min(dp[lo][hi][p[a].se], dp[lo][hi][p[b].se]+A[p[b].se][p[a].se]);
//		}
//    }
}

int main(){
//freopen("citrus.txt", "r", stdin);
int a, b, c, d;
cin >> N >> K;
REP(a, N) scanf("%d", &C[a]);
REPI(a, K) REPI(b, K) scanf("%d", &A[a][b]);
REPI(a, K) scanf("%d", &B[a]);
int cc = 2e9;
ans(0, N);
REPI(a, K){
    cc = min(dp[0][N][a], cc);
}
cout << cc;
return 0;
}
