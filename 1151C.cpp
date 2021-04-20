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


ll i, N, M;
const ll MOD = 1000000007;

ll p2[65];

ll g_sum(ll p){
  ll k = floor(log2(p));
  
  return 0;
}

void init(){
  ll t = 1;
  for(int i=0;i<63;i++){
    p2[i] = t;
    t *= 2;
    t %= MOD;
  }
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  init();
  cin >> N >> M;
  ll x = 1e18;
  cout << x*x;
  /* g_sum(N); */
  /* cout << g_sum(N); */



	return 0;
}
