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
bool m[300010];
vector<int> e[300010];
int L;

int dfs(int x){
  int t, c;
  if(e[x].empty()) return 1;
  if(m[x]){
    t = N+1;
    for(auto y:e[x]){
      c = dfs(y);
      t = min(c, t);
    }
    /* cout << x <<':'<<t<<'\n'; */
    return t;
  }
  else {
    t = 0;
    for(auto y: e[x]){
      t += dfs(y);
    }
    /* cout << x <<':'<<t<<'\n'; */
    return t;
  }
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N;
  rep(a, 1, N+1) cin >> m[a];
  rep(a, 2, N+1){
    cin >> c;
    e[c].pb(a);
  }
  rep(a, 1, N+1) if(e[a].empty()) L++;
  /* dump(L); */
  cout << L+1-dfs(1);

	return 0;
}
