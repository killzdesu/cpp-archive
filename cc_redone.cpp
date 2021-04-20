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
const ll mod = 1e9+7;
ll ans[1000002];

ll cal(ll x, ll y){
  return ((x+1)*(y+1)-1)%mod;
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  ans[1] = 1;
  rep(a, 2, 1000001){
    ans[a] = cal(ans[a-1], a);
  }
  cin >> T;
  while(T--){
    cin >> c;
    cout << ans[c] << '\n';
  }
  



	return 0;
}
