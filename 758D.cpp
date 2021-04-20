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
string s;

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N;
  cin >> s;
  N--;
  M = 1+(int)log10(N);
  vector<int> v;
  for(a=len(s)-1;a>=0;a--){
    for(b = max(0,a-M+1);b<=a;b++){
      if(b!=a and s[b]=='0') continue;
      /* cout << b <<' '<<a<<endl; */
      /* cout << stoi(s.substr(b, a-b+1)) << endl; */
      i = stoi(s.substr(b, a-b+1));
      if( i <= N ){
        v.pb(i);
        a = b;
        break;
      }
    }
  }
  reverse(all(v));
  ll t = 0;
  for(auto x: v) {
    t*=((ll)N+1);
    t += (ll)x;
  }
  cout << t;


	return 0;
}
