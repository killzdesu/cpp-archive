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
pair<ll,ll> p[100010];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N;
  rep(a, 0, N)cin >> p[a].fi >> p[a].se;
  /* rep(a, 0, N){ */
  /*   cout<<a<<'|'; */
  /*   rep(b, 0, N) cout<<' '<<p[a].fi*b+p[a].se*(N-b-1); */
  /*   cout << '\n'; */
  /* } */
  sort(p,p+N, [](pii a, pii b){
      return a.fi-b.fi+b.se-a.se>0;
      });
  /* sort(p,p+N, [](pii a, pii b){ */
  /*       return (a.se!=b.se?a.se<b.se:a.fi>b.fi); */
  /*     }); */
  ll sm = 0;
  rep(a, 0, N) sm += p[a].fi*a+p[a].se*(N-a-1);
  cout << sm;

	return 0;
}
