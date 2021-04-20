/*
  TASK: blaho
  LANG: C++
  AUTHOR: kill-z
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
#define REP(x, y) for(x = 0;x<y;x++)
#define REPI(x, y) for(x=1;x<=y;x++)
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define pb push_back

using namespace std;

int i, n, k, N, M, K;

char tid[10100];
vector<int> v[10010], vt[10010];
pii df[10010];
bool u[10010];

string s[10010];

void dfs_t(int x){
	u[x] = 1;
	int a;
	REP(a, vt[x].size()){
		if(u[vt[x][a]] == 0){
			dfs_t(vt[x][a]);
		}
	}
	df[x].se = x;
	df[x].fi = k++;
}

int grp[10010];
vector<pii> e;
//vector<int> mem[10010];

void scc(int x){
	u[x] = 1;
	int a;
	REP(a, v[x].size()){
		if(u[v[x][a]] == 0){
			scc(v[x][a]);
		}
	}
	grp[x] = k;
}

void dfs_n(int x){
	u[x] = 1;
	int a;
	REP(a, vt[x].size()){
		if(u[vt[x][a]] == 0){
			dfs_n(vt[x][a]);
		}
	}
	df[x].se = x;
	df[x].fi = i++;
}

int dp[10010], h[10010];

int dfs(int x){
	if(u[x]) return dp[x];
	u[x] = 1;
	h[x] = -1;
	if(x == grp[N]) return dp[x];
	if(vt[x].size() == 0) return -2e8;
	int mx = 0, a, c;
	string tp;
	REP(a, vt[x].size()){
		c = dfs(vt[x][a]);
		if(c > mx){
			mx = c;
			h[x] = vt[x][a];
			tp = s[vt[x][a]];
		}
		else if(c == mx){
			if(s[vt[x][a]] < tp){
				h[x] = vt[x][a];
				tp = s[vt[x][a]];
			}
		}
	}
	if(mx == 0) return -2e8;
	dp[x] += mx;
	s[x] += tp;
	return dp[x];
}

int main(){
    int a, b, c, d;
    cin >> N >> M;
	scanf("%s", tid+1);
	REP(a, M){
		scanf("%d %d", &c, &d);
		v[c].pb(d);
		vt[d].pb(c);
		e.pb(mp(c, d));
	}

	k = 1;
	REPI(a, N){
		if(!u[a]) dfs_t(a);
	}
	sort(df+1, df+N+1, greater<pii>());

	k = 0;
	fill(u, u+N+1, 0);
	REPI(a, N){
		if(!u[df[a].se]){
			k++;
			scc(df[a].se);
		}
	}

	//REPI(a, N) printf("%d - %d\n", a, grp[a]);
	REPI(a, k+1){
		vt[a].clear();
	}

	REPI(a, N){
		//vt[grp[a]].pb(a);
		s[grp[a]].pb(tid[a]);
	}

	REP(a, e.size()){
		e[a].fi = grp[e[a].fi];
		e[a].se = grp[e[a].se];
	}
	sort(e.begin(), e.end());
	e.resize(distance(e.begin(), unique(e.begin(), e.end())));

	REP(a, e.size()){
		if(e[a].fi != e[a].se){
			vt[e[a].fi].pb(e[a].se);
			//printf("%d -> %d\n", e[a].fi, e[a].se);
		}
	}
	fill(u, u+N+1, 0);
	i = 1;
	REPI(a, k){
		dp[a] = s[a].length();
		sort(s[a].begin(), s[a].end());
		if(!u[a]) dfs_n(a);
	}
	sort(df+1, df+k+1, greater<pii>());
	int mx = -2e8;
	fill(u, u+N+2, 0);
	/*REPI(a, k){
		b = df[a].se;
		if(mx <= dfs(b)){
			mx = dfs(b);
			d = b;
		}
		}*/
	dfs(grp[1]);
	d = grp[1];
	//REPI(a, k)printf("dp[%d] = %d\n", a, h[a]);
	//return 0;
	//cout << d;
	while(d != -1){
		cout << s[d];
		return 0;
		d = h[d];
	}

    return 0;
}
