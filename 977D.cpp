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
int get3(ll x){
  int c = 0;
  while(x%3==0){
    c++; x/=3;
  }
  return c;
}

unordered_map<ll, int> m;
ll s[110];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N;
  rep(a, 0, N) cin >> s[a];
  rep(a, 0, N) m[s[a]] = get3(s[a]);
  sort(s, s+N, [](ll x, ll y){ return (m[x]==m[y]?x<y:m[x]>m[y]);});
  rep(a, 0, N) cout << s[a] << ' ';

	return 0;
}
