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

using namespace std;

struct Edge{
	int t, w, p;
} tmp;

vector<Edge> e[200010];

int i, N, M, K, k;
int w[200010], p[200010];
int st[200010];

void scout(int x, int par){
	for(auto y: e[x]){
		if(y.t == par) continue;
		w[y.t] = y.w;
		p[y.t] = y.p;
		scout(y.t, x);
	}
}

void dfs(int x, int par){
	st[x] = w[x];
	for(auto y: e[x]){
		if(y.t == par) continue;
		dfs(y.t, x);
		st[x] += st[y.t];
	}
}

int lost;

void solve(int x, int par){
	if(lost == 0) return;
	for(auto y: e[x]){
		if(y.t == par) continue;
		solve(y.t, x);
	}
	int red = min(p[x], w[x]-1);
	red = min(red, (p[x]+w[x]-st[x]>0?p[x]+w[x]-st[x]:0));
	red = min(red, lost);
	p[x] -= red;
	w[x] -= red;
	st[x] -= red;
	lost -= red;
	st[par] -= red;
}

void output(int x, int par){
	if(par!=-1) printf("%d %d %d %d\n", par+1, x+1, w[x], p[x]);
	for(auto y: e[x]){
		if(y.t == par) continue;
		output(y.t, x);
	}
}

int main(){
	int a, b, c, d;
	int T;
	cin >> N;
	REP(a, N-1){
		cin >> c >> d >> b >> T;
		d--;c--;
		tmp.t = d; tmp.w=b; tmp.p=T;
		e[c].pb(tmp);
		tmp.t = c; tmp.w=b; tmp.p=T;
		e[d].pb(tmp);
	}
	scout(0, -1);
	dfs(0, -1);

	for(auto y: e[0]){
		lost = -1*min(0, p[y.t]-(st[y.t]-w[y.t]));
		solve(y.t, 0);
		if(lost != 0){
			puts("-1");
			return 0;
		}
	}

	cout << N << endl;
	output(0, -1);
	
	/* REP(a, N){ */
	/* 	printf("%d %d/%d\n", a, st[a]-w[a], p[a]); */
	/* } */

	return 0;
}
