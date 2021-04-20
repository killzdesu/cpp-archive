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
char s[1000010];
char C;

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, d;
	int T;
  cin >> T;
  ll sm, c;
  while(T--){
    cin >> N;
    cin >> s+1 >> C;
    s[N+1] = C;
    sm = 0;
    int lt = 0;
    rep(a, 1, N+2){
      if(s[a] == C){
        c = a-lt-1;
        sm += c*(c+1)/2;
        lt = a;
      }
    }
    c = (ll)N*((ll)N+1)/2;
    cout << c-sm << '\n';
    /* dump(c); */
    /* dump(sm); */

  }




	return 0;
}
