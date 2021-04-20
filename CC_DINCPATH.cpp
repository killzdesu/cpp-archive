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


int i, N, M;
int A[100010];
vector<int> e[100010];
vector<int> o;
int dp[100010];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> T;
  while(T--){
    cin >> N >> M;
    rep(a, 0, N+1) e[a].clear(), dp[a] = 0;
    rep(a, 1, N+1) cin >> A[a];
    rep(a, 0, M){
      cin >> c >> d;
      if(A[c] < A[d]) swap(c, d); 
      if(A[c] > A[d]) e[c].pb(d);
    }
    o.clear();rep(a, 1, N+1) o.pb(a);
    sort(all(o), [](int x,int y){return A[x]<A[y];});
    /* dump_all(o); */
    dp[o[0]] = 1; 
    int mx = 0;
    rep(a, 1, N){
      int p = o[a];
      for(auto x: e[p]){
        dp[p] = max(dp[p], dp[x]+1);
      }
      mx = max(dp[p], mx);
    }
    cout << mx << '\n';
  }



	return 0;
}
