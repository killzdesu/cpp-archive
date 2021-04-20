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
  vector<int> ans;
  cin >> N >> T;
  a = 0;
  b = 0;
  if(T != 0){
    if(N%4 == 1) ans.pb(T);
    else if(N%4 == 2) ans.pb(T), ans.pb(0);
    else if(N%4 == 3) ans.pb(0), ans.pb(300001), ans.pb((300001^T));
    else {
      b = 1;
      if(T <= 3) ans.pb(12), ans.pb(8), ans.pb(4), ans.pb(T);
      else ans.pb(T), ans.pb(1), ans.pb(2), ans.pb(3);
    }
  }
  else {
    if(N%4 == 1) ans.pb(T);
    else if(N%4 == 2){
      if(N == 2){
        cout << "NO";
        return 0;
      }
      ans.pb(1); ans.pb(2); ans.pb(3); ans.pb(4); ans.pb(8); ans.pb(12);
      b = 1;
    }
    else if(N%4 == 3) ans.pb(1), ans.pb(2), ans.pb(3);
    else {
      b = 1;
      ans.pb(7), ans.pb(2), ans.pb(4), ans.pb(1);
    }
  }

  rep(a, b, N/4){
    ans.pb(800002+a*2); ans.pb(800003+a*2);
    ans.pb(600002+a*2); ans.pb(600003+a*2);
  }
  cout << "YES\n";
  for(auto x: ans) cout << x << ' ';

	return 0;
}
