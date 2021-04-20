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
vector<int> s;
int dp[200010][2];
deque<int> q;
multiset<int> S;

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N >> T;
  rep(a, 0, N){
    cin >> c;
    s.pb(c);
  }
  sort(all(s));
  int cnt = 0;
  for(a=N-1;a>=0;a--){
    if(!S.empty()){
      auto it = S.lower_bound(s[a]+T);
      if(it!=S.end() and *it-s[a] >= T){
        cnt++;
        S.erase(it);
        continue;
      }
    }
    S.insert(s[a]);
  }
  /* rep(a, 0, N) cnt = max(cnt, dp[a][0]); */
  cout << cnt;

	return 0;
}
