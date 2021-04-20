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
  ll cnt = 0;
  vector<int> s;
  rep(a, 0, N){
    cin >> c;
    s.pb(c);
    if(a){
      if(d==1){
        if(c == 2){
          if(s[a-2]!=3)cnt += 3;
          else cnt += 2;
        }
        if(c == 3) cnt += 4;
      }
      if(d == 2){
        if(c == 1) cnt += 3;
        if(c == 3) cnt -=2e9;
      }
      if(d == 3){
        if(c == 1) cnt += 4;
        if(c == 2) cnt -= 2e9;
      }
    }
    d = c;
  }

  if( cnt < 0 ) cout << "Infinite";
  else {
    cout << "Finite\n"<<cnt;
  }

	return 0;
}
