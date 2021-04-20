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
vector<int> e[200010];
int h[200010];
int fh(int x){
  return (h[x]<0?x:h[x]=fh(h[x]));
}
int ch(int x){
  return -h[fh(x)];
}

bool vs[200010];
int cc;
int dfs(int x, int par){
  if(vs[x]){
    if(cc == ch(x)+1 and x == fh(x)) return true;
    return false;
  }
  vs[x] = true;
  if(e[x].size()>2) return false;
  /* if(e[x].size() and e[x][0]!=par) {cc++; return dfs(e[x][0], x);} */
  /* else if(e[x].size()>1) {cc++; return dfs(e[x][1], x);} */
  for(auto g: e[x])if(par!=g){cc++; return dfs(g, x);};

  return false;
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N >> M;
  rep(i, 1, N+1) h[i] = -1;
  rep(i, 0, M){
    cin >> c >> d;
    e[c].pb(d);
    e[d].pb(c);
    if(fh(c)!=fh(d)){
      c=fh(c), d=fh(d);
      h[d] += h[c];
      h[c] = d;
      /* cout << "join "<<c<<' '<<d << endl; */
      /* rep(a, 1, N+1) cout << a << ":" << fh(a) << " " << ch(a) << endl; */
    }
  }
  int cnt = 0;
  rep(i, 1, N+1){
    /* cout << "dfs " << i << " : " << fh(i) << ' ' << vs[fh(i)] << '\n'; */
    if(vs[fh(i)]) continue;
    /* cout << "GO" << '\n'; */
    cc = 1;
    c = dfs(fh(i), -1);
    vs[fh(i)] = true;
    if(c and ch(i)>=3) cnt++;
  }
  cout << cnt;

	return 0;
}
