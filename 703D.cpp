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

int K = 21;
int i, N, M;
int s[1000010];
int m[2000010];

void update(int x, int val){
    while(x <= N){
        m[x] ^= val;
        x += (x&-x);
    }
}

int query(int idx) {
    int sum = 0;
    while (idx > 0){
        sum ^= m[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

pair<pii, pii> p[(int)1e6+5];
unordered_map<int, int> um;
int ps[1000005];

int main(){
  um.reserve(65536*4);
  um.max_load_factor(0.25);
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N;
  rep(a, 1, N+1) cin >> s[a], ps[a] = s[a]^ps[a-1];
  cin >> M;
  rep(a, 0, M) cin >> (p[a].fi).fi >> (p[a].fi).se, (p[a].se).fi = a;
  sort(p, p+M, [](pair<pii,pii> & l, pair<pii,pii> & r)->bool{
      return (l.fi).se < (r.fi).se;
      });
  i = 0;
  rep(a, 1, N+1){
    if(um[s[a]]) update(um[s[a]], s[a]);
    um[s[a]] = a;
    update(a, s[a]);
    while(i < N and (p[i].fi).se == a){
      int l = (p[i].fi).fi, r=( p[i].fi ).se;
      /* cout << l << ' ' << r<<':'<<((ps[r])^(ps[l-1]))<<'\n'; */
      int t = (ps[r]^ps[l-1]);
      t^= (query(r)^query(l-1));
      /* cout << l << ' '<<r<<": "<<t<<'\n'; */
      (p[i].se).se = t;
      i++;
    }
  }
  sort(p, p+M, [](pair<pii,pii> & l, pair<pii,pii> & r)->bool{
      return (l.se).fi < (r.se).fi;
      });
  rep(a, 0, M) cout << (p[a].se).se << '\n';

	return 0;
}
