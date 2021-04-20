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
int h[100];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N >> T >> M;
  rep(a, 1, N+1) h[a] = T;
  rep(i, 0, M){
    cin >> c >> d >> b;
    rep(a, c, d+1) h[a] = min(h[a], b);
  }
  ll ans= 0;
  rep(a, 1, N+1) ans += h[a]*h[a];
  cout << ans;



	return 0;
}
