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
vector<int> o[100010];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N >> M;
  rep(a, 0, M){
    cin >> c;
    c--;
    o[c].pb(a);
  }
  ll cnt = 0;
  rep(a, 0, N){
    if(o[a].empty()) cnt++;
    if(a){
      if(o[a-1].empty() or o[a].empty()) cnt++;
      else{
        c = o[a][0];
        auto it = lower_bound(all(o[a-1]), c);
        if(it == o[a-1].end()) cnt++;
      }
    }
    if(a!=N-1){
      if(o[a+1].empty() or o[a].empty()) cnt++;
      else{
        c = o[a][0];
        auto it = lower_bound(all(o[a+1]), c);
        if(it == o[a+1].end()) cnt++;
      }
    }
  }
  cout << cnt;



	return 0;
}
