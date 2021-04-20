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
  vector<int> v;
  rep(a, 0, N){
    cin >> c;
    v.pb(c);
  }
  sort(all(v));
  vector<int> s;
  rep(a, 0, N) s.pb(v[a]);
  v.erase(unique(all(v)), v.end());
  if(len(v) == 1) cout << 0;
  else if(len(v) > 3) cout << "-1";
  else if(len(v) == 2){
    c = v[1]-v[0];
    if(c%2==1) cout << c;
    else cout << c/2;
  }
  else if(len(v) == 3){
    if(v[2]-v[1] != v[1]-v[0]) cout << -1;
    else cout << v[2]-v[1];
  }


	return 0;
}
