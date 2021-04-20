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

int p[4];

int i, N, M;

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N >> M;

  p[M] = 1;
  if(M == 0){
    N%=6;
  }
  if(M == 1){
    N%=6;
  }
  if(M == 2){
    N%=6;
  }
  for(a=N;a>=1;a--){
    if(a%2) swap(p[0], p[1]);
    else swap(p[1], p[2]);
  }
  rep(a, 0, 3) if(p[a]) cout << a;



	return 0;
}
