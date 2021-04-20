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
vector<int> s[100010];
vector<int> m[100010];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N >> M;
  rep(a, 0, N) rep(b, 0, M){
    cin >> c;
    s[a].pb(c);
  }
  rep(b, 0, M){
    rep(a, 0, N){
      if(a==0){
        m[b].pb(0);
        continue;
      }
      if(s[a][b] >= s[a-1][b]){
        m[b].pb(m[b][a-1]);
      }
      else {
        m[b].pb(a);
      }
    }
  }

  /* rep(a, 0, N){ */
  /*   rep(b, 0, M) cout << m[b][a]<<' '; */
  /*   cout << '\n'; */
  /* } */
  
  /* return 0; */
  int ans[100010];
  rep(a, 0, N){
    if(!a) ans[a] = 0;
    else {
      ans[a] = a;
      rep(b, 0, M){
        ans[a] = min(ans[a], m[b][a]);
      }
    }
  }

  cin >> T;
  while(T--){
    cin >> c >> d;
    c--; d--;
    if(ans[d] <= c) cout << "Yes\n";
    else cout << "No\n";
  }


	return 0;
}
