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

vector<int> v[300000];
int p[300000];

vector<int> r;

void dfs(int x){
  vector<pii> ch;
  int a;
  for(int y: v[x]){
    ch.pb(make_pair(p[y], y));
  }
  sort(all(ch), greater<pii>());
  rep(a, 0, len(ch)){
    if(ch[a].fi <= p[x]) break;
    dfs(ch[a].se);
  }
  r.pb(x);
  rep(a, a, len(ch)){
    dfs(ch[a].se);
  }
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N;
  rep(a, 1, N+1) cin >> p[a];
  rep(a, 2, N+1){
    cin >> c;
    v[c].pb(a);
  }
  dfs(1);
  for(auto x: r) cout << x << " ";

	return 0;
}
