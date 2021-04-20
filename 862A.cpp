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
	int X;
  map<int, int> m;
  cin >> N >> X;
  rep(a, 0, N) cin >> c, m[c] = 1;
  i = 0;
  if(m[X] == 1) i++;
  rep(a, 0, X){
    if( m[a] == 0) i++;
  }
  cout << i;


	return 0;
}
