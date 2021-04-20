#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(x,y) for(x=0;x<(int)y;x++)
#define REPI(x,y) for(x=1;x<=(int)y;x++)
#define pii pair<int,int>
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define len(x) (x).size()

using namespace std;

int i, N, M, K, k;
vector<pii> e[100010];
int vs[100010];
ll gr;

void dfs(int x, int h){
  if(vs[x]) return;
  vs[x] = 1;
  gr++; 
  for(auto y:e[x]){
    if(y.se != 1) dfs(y.fi, 1);
  }
}

ll const MOD = 1000000007;

ll pow(ll g){
  ll xx= g;
  for(int i=0;i<k-1;i++){
    g*=xx;
    g%=MOD;
  }
  return g;
}

int main(){
	int a, b, c, d;
	int T;
  ll cnt = 0;
  cin >> N >> k;
  REP(a, N-1){
    scanf("%d %d %d", &c, &d, &b);
    e[c].pb({d, b});
    e[d].pb({c, b});
  }
  REPI(a, N){
    if(vs[a]==0){
      gr = 0;
      dfs(a, a);
      /* printf("%d gr\n", gr); */
      cnt += pow(gr);
      /* printf("%lld cnt\n", cnt); */
      cnt %= MOD;
    }
  }
  ll all = (ll)N;
  REP(a, k-1){
    all *= N;
    all %= MOD;
  }
  /* cout << all << endl; */
  /* cout << cnt << endl; */
  all += MOD;
  cout << (all-cnt)%MOD;

	return 0;
}
