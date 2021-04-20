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
int s[200010];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d, k;
	int T;
  cin >> N >> k;
  rep(a, 0, N) cin >> s[a];
  sort(s, s+N);
  c = s[k-1];
  if(k!=N and c == s[k]) cout << -1;
  else if(k==0 and s[0]==1) cout << -1;
  else if(k==0) cout << 1;
  else cout << s[k-1];

	return 0;
}
