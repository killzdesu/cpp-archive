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
int x[600], y[600];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> T;
  while(T--){
    cin >> N;
    rep(a, 0, N) x[a] = y[a] = 0;
    rep(a, 0, N) rep(b, 0, N){
      cin >> c;
      if(!c) x[a] = y[b] = 1;
    }
    c = 1;
    rep(a, 0, N) if(!x[a] or !y[a]) c = 0;
    if(c) cout << "YES\n";
    else cout << "NO\n";
  }



	return 0;
}
