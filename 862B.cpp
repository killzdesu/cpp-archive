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
vector<int> O, E, e[100010];

void dfs(int x, int par, int g){
  if(g) O.pb(x);
  else E.pb(x);
  for(auto y: e[x]) if(par != y) dfs(y, x, g^1);
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N;
  rep(a, 1, N){
    cin >> c >> d;
    e[c].pb(d);
    e[d].pb(c);
  }
  dfs(1, -1, 0);
  cout << ((ll)len(O))*((ll)len(E))-N+1; 


	return 0;
}
