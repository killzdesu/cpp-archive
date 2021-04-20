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
  cin >> N;
  int Mish=0, Chris=0;
  rep(a, 0, N){
    cin >> c >> d;
    Mish += (c>d);
    Chris += (d>c);
  }
  if(Mish==Chris) cout << "Friendship is magic!^^";
  else if(Mish > Chris) cout << "Mishka";
  else cout << "Chris";


	return 0;
}
