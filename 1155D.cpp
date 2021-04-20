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


int i, N, M, X;
ll s[300010];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N >> X;
  rep(a, 0, N) cin >> s[a];
  if( X > 0 ){
    ll sm = 0;
    ll mx = 0;
    rep(a, 0, N){
      sm += s[a];
      mx = max(mx, sm);
      if(sm < 0) sm = 0;
    }
    cout << mx*X;
  }
  else if( X < 0){
    ll sm=0, mn=0;
    int l=0, r=-1, m=0;
    rep(a, 0, N){
      sm += s[a];
      mn = min(mn, sm);
      if(mn == sm) m = l, r = a;
      if( sm > 0 ) sm = 0, l = a+1;
    }
    /* dump(m); dump(r); */
    rep(a, m, r+1){
      s[a] *= X;
    }
    /* rep(a, 0, N) cout << s[a] << ' ';cout << endl; */
    sm = 0;
    ll mx = 0;
    rep(a, 0, N){
      sm += s[a];
      mx = max(mx, sm);
      if( sm < 0 ) sm = 0;
    }
    cout << mx;
  }
  else {
    ll sm = 0;
    ll mx = 0;
    ll A = 0;
    int l=0, r=-1; c = 0;
    rep(a, 0, N){
      sm += s[a];
      mx = max(mx, sm);
      if(mx == sm) r = a, l = c;
      if(sm < 0){
        sm = 0;
        c = a+1;
      }
    }
    A = mx;
    mx = 0; sm = 0;
    for(a = r+1;a<N;a++){
      sm += s[a];
      mx = max(mx, sm);
      if(sm < 0) sm = 0;
    }
    ll R = mx;
    mx = 0; sm = 0;
    for(a = l-1;a>=0;a--){
      sm += s[a];
      mx = max(mx, sm);
      if(sm < 0) sm = 0;
    }
    ll L = mx;
    cout << A + max(L, R);

    
  }




	return 0;
}
