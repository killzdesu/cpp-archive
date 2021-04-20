#include "bits/stdc++.h"
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(x,y) for(x=0;x<(int)y;x++)
#define REPI(x,y) for(x=1;x<=(int)y;x++)
#define pii pair<int,int>
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define len(x) (int)((x).size())

using namespace std;

int i, N, M, K, k;
vector<int> e[200010];
vector<int> h[200010];
bool chk[200010];

int dfs2(int x, int P, int c){
  if(c<=1) chk[x]=true;
  if(c>2) return 0;
  for(auto y:e[x]){
    if(y!=P) dfs2(y, x, c+1);
  }
  return 0;
}

vector<int> ans;

int dfs(int x, int P){
  if(len(e[x])==1 and e[x][0]==P) return 0;
  int ret = 3;
  for(auto y: e[x]){
    if(y == P) continue;
    int c = (dfs(y, x)+1)%3;
    if(ret!=0 and ret!=1  and c==2) ret = 2;
    if(ret!=1 and c==0) ret = 0;
    if(c==1) ret = 1;
  }
  if(ret == 1 and !chk[x]) ans.pb(x);
  if(ret==3) ret = 0;
  return ret;
}

int main(){
	int a, b, c, d;
	int T;
  cin >> N;
  REP(a, N-1){
    scanf("%d%d", &c, &d);
    e[c].pb(d);
    e[d].pb(c);
  }
  dfs2(1, -1, 0);
  dfs(1, -1);
  /* for(auto x: ans) printf("%d ", x); */
  cout << len(ans);

	return 0;
}
