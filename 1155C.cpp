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
vector<ll> X;
ll G;

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, d;
  ll c;
	int T;
  cin >> N >> M;
  rep(a, 0, N){
    cin >> c;
    X.pb(c);
  }
  G = 0;
  rep(a, 0, N-1){
    if(G==0) G = X[a+1]-X[a];
    else G = __gcd(G, X[a+1]-X[a]);
  }
  /* dump(G); */
  rep(a, 0, M){
    cin >> c;
    if( G % c == 0){
      cout << "YES\n";
      cout << X[0] <<' '<<a+1;
      /* cout << c; */
      return 0;
    }
  }
  cout << "NO";


	return 0;
}
