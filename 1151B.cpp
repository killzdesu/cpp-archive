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
int s[505][505];
int dp[505][1050];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N >> M;
  rep(a, 1, N+1) rep(b, 0, M) cin >> s[a][b];
  rep(a, 0, N+1) rep(b, 0, 1024) dp[a][b] = -1;
  dp[0][0] = 0;
  rep(a, 1, N+1){
    rep(b, 0, 1024) if(dp[a-1][b] != -1){
      rep(c, 0, M) dp[a][b^s[a][c]] = b;
    }
  }
  /* rep(a, 1, N+1){ */
  /*   rep(b, 0, 16) cout << dp[a][b] <<' '; */
  /*   cout <<'\n'; */
  /* } */
  rep(a, 1, 1024) if(dp[N][a] != -1) break; 
  if(a==1024) {cout << "NIE"; return 0;}
  cout << "TAK\n";
  vector<int> ans;
  rep(b, 0, N){
    d = (a^dp[N-b][a]);
    rep(c, 0, M) if(s[N-b][c] == d) break;
    ans.pb(c+1);
    a = dp[N-b][a];
  }
  reverse(all(ans));
  rep(a, 0, N) cout << ans[a] << ' ';
	return 0;
}
