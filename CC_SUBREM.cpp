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

const int inf = 0x3f3f3f3f;

int i, N, M;;
ll X;
vector<int> v[100010];
ll s[100010];
ll dp[100010];

void reset(){
  rep(i, 0, N+1) v[i].clear();
  fill(dp, dp+N+2, -inf);
}

void dfs(int x, int par){
  dp[x] = s[x];
  for(auto y:v[x]) if(y!=par){
    dfs(y, x);
    dp[x] += dp[y];
  }
  dp[x] = max(-X, dp[x]);
  /* dump(x); */
  /* dump(dp[ x ]); */
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> T;
  while(T--){
    cin >> N >> X;
    reset(); 
    rep(a, 1, N+1) cin >> s[a];
    rep(a, 0, N-1){
      cin >> c >> d;
      v[c].pb(d);
      v[d].pb(c);
    }
    dfs(1, -1);
    cout << dp[1] << '\n';
  }


	return 0;
}
