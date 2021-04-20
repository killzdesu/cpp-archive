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

struct node{
  int lo, hi; 
  ll val;
};
node t[200010*6];

void build(int x, int lo, int hi){
  t[x].lo = lo; t[x].hi = hi;
  if(lo >= hi-1) return;
  int mi = (lo+hi)/2;
  build(x*2, lo, mi);
  build(x*2+1, mi, hi);
}

void upd(int x, int T, ll v){
  if(t[x].lo > T or t[x].hi <= T) return;
  if(t[x].lo >= t[x].hi-1){
    t[x].val = max(t[x].val, v);
    return ;
  }
  upd(x*2, T, v);
  upd(x*2+1, T, v);
  t[x].val = max(t[x*2].val, t[x*2+1].val);
}

ll query(int x, int lo, int hi){
  if(hi <= t[x].lo or t[x].hi <= lo) return 0;
  if(lo <= t[x].lo and t[x].hi <= hi) return t[x].val;
  return max(query(x*2, lo, hi), query(x*2+1, lo, hi));
}

struct ring{
  int a, b, h;
  bool operator < (const ring & x) const { return (b!=x.b?b>x.b:a>x.a); }
};
ring s[100'010];

vector<int> vm;
unordered_map<int,int> m;

int main(){
  m.reserve(65'536);
  m.max_load_factor(0.25);
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N;
  rep(a, 0, N) cin >> s[a].a >> s[a].b >> s[a].h;

  rep(a, 0, N) vm.pb(s[a].a), vm.pb(s[a].b);
  sort(all(vm));
  vm.erase(unique(all(vm)), vm.end());
  rep(i, 0, len(vm)) m[vm[i]] = i;

  sort(s, s+N);
  build(1, 0, 2*N);

  /* rep(i, 0, N) cout << s[i].a <<' '<<s[i].b<<' '<<s[i].h<<'\n'; */
  rep(i, 0, N){
    ll c = query(1, 0, m[s[i].b]);
    upd(1, m[s[i].a], c+s[i].h);
  }

  cout << query(1, 0, 2*N);

	return 0;
}
