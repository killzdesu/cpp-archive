#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#define rep(i, x,y) for(i=(int)x;i<(int)y;i++)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define pb push_back
#define dump(x) cout <<(#x) << " = " << x << "\n";
#define dump_all(s) cout<<(#s)<<":\n";for(auto x:s)cout<<x<<" ";cout<<"\n";

using namespace std;
using namespace __gnu_pbds;

typedef pair<int,int> pii;
typedef long long ll;

int i, N, M;
int s[200010];

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
      int operator()(int x) const { return x ^ RANDOM; }
};

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
      // http://xorshift.di.unimi.it/splitmix64.c
      x += 0x9e3779b97f4a7c15;
      x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
      x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
      return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
      static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
      return splitmix64(x + FIXED_RANDOM);
  }
};

gp_hash_table<int, int, custom_hash> m;

int main(){
  /* cin.tie(0); ios::sync_with_stdio(false); */
  /* m.reserve(65536); */
  /* m.max_load_factor(0.25); */
	int a, b, c, d;
	int T;
  cin >> N;
  rep(a, 0, N) scanf("%d",s+a);
  rep(a, 0, N){
    c = m[s[a]-1];
    m[s[a]] = max(m[s[a]], c+1);
  };
  int mx = 0;
  rep(a, 0, N){
    c = m[s[a]];
    if(mx < c){
      mx = c;
      i = s[a];
    }
  }
  i = i-mx+1;
  cout << mx << '\n';
  rep(a, 0, N) if(i==s[a]) printf("%d ", a+1), i++;

	return 0;
}
