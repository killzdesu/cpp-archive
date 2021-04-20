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

vector<int> v[200010];
int ans[200010];
int leaf[200010];

void dfs(int x, int par, int d){
	if(v[x].size() == 0){
		leaf[x] = 1;
		ans[x] = 1;
		return ;
	}
	for(auto u: v[x]){
		if(u == par) continue;
		dfs(u, x, d+1);
        leaf[x] += leaf[u];
	}
    if(d%2 == 1){
		int c = 2e9, sm = 0;
		for(auto u: v[x]){
			if(u!=par) sm += (ans[u]-1);
		}
        ans[x] = sm+1;
    }
    else {
		int c = -2e9, sm = 0;
        for(auto u: v[x]){
			if(u == par) continue;
			sm += leaf[u];
        }
        for(auto u: v[x])if(u != par) c = max(c, sm-leaf[u]+ans[u]);
        ans[x] = c;
    }
//    printf("%d[%d]: %d/%d\n", x, d%2, ans[x], leaf[x]);
}

void dfs2(int x, int par, int d){
	if(v[x].size() == 0){
		ans[x] = 1;
		return ;
	}
	for(auto u: v[x]){
		if(u == par) continue;
		dfs2(u, x, d+1);
	}
    if(d%2 == 1){
		int c = 2e9, sm = 0;
		for(auto u: v[x])if(u != par) c = min(ans[u], c);
        ans[x] = c;
    }
    else {
		int c = 0, sm = 0;
        for(auto u: v[x])if(u != par) sm += ans[u];
        ans[x] = sm;
    }
}

int main(){
int a, b, c, d;
cin >> N;
REP(a, N-1){
	scanf("%d %d", &c, &d);
	v[c].pb(d);
}
dfs(1, -1, 0);
cout << ans[1] << " ";
dfs2(1, -1, 0);
cout << ans[1] << " ";

return 0;
}
