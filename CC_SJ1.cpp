#include "bits/stdc++.h"
#define rep(i, x,y) for(i=(int)x;i<(int)y;i++)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define pb push_back
#define dump(x) cout <<(#x) << " = " << x << "\n";
#define dump_all(s) cout<<(#s)<<":\n";for(auto x:s)cout<<x<<" ";cout<<"\n";

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int NNN = 100010;
int i, N, M;
vector<int> e[NNN];
ll g[NNN], v[NNN], m[NNN];
vector<pair<int, ll> > ans;

void reset(){
  rep(i, 0, N+1) e[i].clear();
  rep(i, 0, N+1) g[i] = 0;
  ans.clear();
}

void dfs(int x, int par){
  for(auto y:e[x]) if(par!=y) {
    g[y] = __gcd(v[y], g[x]);
    dfs(y, x);
  }
  if(x!=1 and len(e[x])==1){
    ans.pb({x, m[x]-__gcd(m[x],g[x])});
  }
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> T;
  while(T--){
    cin >> N;
    reset();
    rep(a, 0, N-1){
      cin >> c >> d;
      e[c].pb(d);
      e[d].pb(c);
    }
    rep(a, 1, N+1) cin >> v[a];
    rep(a, 1, N+1) cin >> m[a];
    
    g[1] = v[1];
    dfs(1, -1);
    /* for(auto x: ans) cout << x.fi <<' '<<x.se<<'\n'; */
    sort(all(ans));
    for(auto x: ans) cout << x.se << ' ';
    cout << '\n';
  }

	return 0;
}
