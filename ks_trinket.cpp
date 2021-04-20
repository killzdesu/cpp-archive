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

vector<int> v[100010];
int dp[100010];
int s[100010];

void reset(){
  int a;
  rep(a, 0, 100004) v[a].clear();
  rep(a, 0, 100004) dp[a] = 0;
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T, TT;
  cin >> TT;
  rep(T, 1, TT+1){
    reset();
    cin >> N >> M;
    rep(a, 0, N){
      cin >> c;
      s[a] = c;
      /* if(v[c].size() >= M) dp[a] = v[c][len(v[c])-M]; */
      v[c].pb(a);
    }
    int mx = 0;
    int sm = 0;
    rep(a, 1, N+1){
      rep(b, 0, N) dp[s[b]] = 0;
      sm = 0;
      rep(b, 0, a){
        if(dp[s[b]]<M) sm++, dp[s[b]]++;
        else if(dp[s[b]] == M)sm -= dp[s[b]], dp[s[b]]++;
        else dp[s[b]]++;
      }
      mx = max(mx, sm);
      rep(b, a, N){
        dp[s[b-a]]--;
        if(dp[s[b-a]] == M) sm += M;
        else if(dp[s[b-a]] < M) sm--;

        if(dp[s[b]]<M) sm++, dp[s[b]]++;
        else if(dp[s[b]] == M)sm -= M, dp[s[b]]++;
        else dp[s[b]]++;
      
        mx = max(mx, sm);
      }
    }
    cout << "Case #"<<T<<": "<<mx<<'\n';
  }



	return 0;
}
