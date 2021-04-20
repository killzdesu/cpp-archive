#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(x,y) for(x=0;x<(int)y;x++)
#define REPI(x,y) for(x=1;x<(int)y;x++)
#define pii pair<int,int>
#define ll long long
#define ALL(x) (x).begin(),(x).end()

using namespace std

int i, N, M, K, k;
int col[100010];
vector<int> e[100010];
int cnt[100010];
int sz[100010];
ll ans[100010];
ll MAX, SUM;
bool isBig[100010];

void run_sz(int x, int p){
	sz[x] = 1;
	for(auto u:e[x])
		if(u != p)
			run_sz(u, x), sz[x]+=sz[u];
}

void cls(int x, int p){
	cnt[col[x]]--;
	for(auto u:e[x])
		if(u!=p and !isBig[u])
			cls(u, x);
}

void solve(int x, int p){
	cnt[col[x]]++;
	if(cnt[col[x]] > MAX) MAX=cnt[col[x]], SUM=col[x];
	else if(cnt[col[x]] == MAX) SUM+=col[x];
	for(auto u:e[x]){
		if(u!=p and !isBig[u])
			solve(u, x);
	}
}

void dfs(int x, int p, bool keep){
	int MX=0, Big=-1;
	for(auto u:e[x])
		if(u!=p and sz[u]>MX)
			MX=sz[u], Big=u;
	for(auto u:e[x])
		if(u!=p and u!=Big)
			dfs(u, x, false);
	if(Big+1){
		isBig[Big] = true;
		dfs(Big, x, true);
	}
		
	solve(x, p);
	ans[x] = SUM;
	if(Big+1) isBig[Big] = false;	
	if(!keep){
		cls(x, p);
		MAX = 0; SUM = 0;
	}
}

void read_input(){
	int a, b, c, d;
	cin >> N;
	REP(a, N) cin >> col[a];
	REP(a, N-1) cin >> c >> d, e[--c].pb(--d), e[d].pb(c);
}
int main(){
	int a, b, c, d;
	int T;
	read_input();
	run_sz(0, -1);	
	dfs(0, -1, true);

	REP(a, N) printf("%lld ", ans[a]);
	return 0;
}
