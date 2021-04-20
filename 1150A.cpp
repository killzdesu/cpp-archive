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

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N >> M >> T;
  vector<int> m, f;
  rep(a, 0, N){
    cin >> c;
    m.pb(c);
  }
  rep(a, 0, M){
    cin >> c;
    f.pb(c);
  }
  sort(all(m)); sort(all(f));
  reverse(all(f));
  int cnt  = 0;
  rep(a, 0, N){
    if(m[a] >= f[0]) break;
    if( T < m[a] ) break;
    cnt += T/m[a];
    T -= (T/m[a])*m[a];
  }
  T += cnt*f[0];

  cout << T;
	return 0;
}
