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
bool C[100010];
int s[100010];
ll sm, sc;

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N >> M;
  rep(a, 0, N) cin >> s[a];
  ll al  = 0;
  ll ac = 0;
  rep(a, 0, N) al += s[a];
  rep(a, 0, M){
    cin >> c;
    ac += s[c-1];
    C[c-1] = true;
  }
  rep(a, 0, N){
    if(C[a]){
      sm += (al-s[a])*s[a];
    }
    else {
      sm += ac*s[a];
      b = (a+N-1)%N;
      c = (a+N+1)%N;
      if(!C[b]) sm += s[a]*s[b];
      if(!C[c]) sm += s[a]*s[c];
    }
  }

  cout << sm/2;


	return 0;
}
