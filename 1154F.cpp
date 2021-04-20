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


int i, N, M, k;
int s[200010], qs[200010];
int deal[200010];
int dp[2010];

int cal(int B, int i){
  return qs[i]-qs[i-B]-qs[i-(B-deal[B])]+qs[i-B];
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N >> M >> k;
  rep(a, 1, 1+N){
    cin >> s[a];
  }
  sort(s+1, s+N+1);
  rep(a, 1, 1+N) qs[a] = s[a]+qs[a-1];
  /* rep(a, 1, 1+N) cout << qs[a] <<' ' ; */
  rep(a, 0, M){
    cin >> c >> d;
    deal[c] = max(deal[c], d);
  }
  rep(a, 1, k+1){
    dp[a] = cal(a, a);
    rep(b, 1, a){
      dp[a] = min(dp[a], dp[b]+cal(a-b, a));
    }
    /* rep(b, 1, a) if(dp[b]+cal(a-b, a) == dp[a]) printf("> %d + %d\n, */
    /* printf("%d: %d\n", a, dp[a]); */
  }
  cout << dp[k];

	return 0;
}
