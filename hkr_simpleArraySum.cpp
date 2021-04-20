#include "bits/stdc++.h"
#define rep(i, x,y) for(i=(int)x;i<(int)y;i++)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define pb push_back
#define dump(x) cout <<(#x) << " = " << x << "\n";
#define dump_all(x) cout<<(#x)<<":\n";for(auto x:s)cout<<x<<" ";cout<<"\n";

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int i, N, M;

int main(){
  ios::sync_with_stdio(false); cin.tie(0);
	int a, b, c, d;
	int T;
  cin >> N;
  ll sm = 0;
  rep(a,0,N) cin >> c, sm += c;
  cout << sm;

	return 0;
}
