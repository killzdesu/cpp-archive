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
const int inf = 0x3f3f3f3f;

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N >> T;
  int mn = inf, bus = 0;
  rep(a, 0, N){
    cin >> c >> d;
    while(c < T) c+= d;
    if(c==T){
      cout << a+1;
      return 0;
    }
    if( c < mn ){
      mn = c;
      bus = a+1;
    }
  }
  cout << bus;


	return 0;
}
