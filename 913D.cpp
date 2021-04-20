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


int T;
int i, N, M;
pii s[200010];
int L[200010], R[200010];

int chk(int m){
  vector<int> val;
  for(int a=0;a<N;a++) if(s[a].fi >= m) val.pb(s[a].se);
  if(m > len(val)) return -1;
  /* nth_element(val.begin(), val.begin()+m-1, val.end()); */
  sort(all(val));
  int p = 0;
  p = accumulate(val.begin(), val.begin()+m, 0);
  if(p > T) return -1; 
  return val[m-1];
}

int main(){
  pii tmp[200010];
  vector<int> cp;
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
  cin >> N >> T;
  rep(a, 0, N) cin >> s[a].fi >> s[a].se;
  int lo = 0, hi = N, mi;
  while(lo < hi){
    mi = (lo+hi+1)/2;
    if(chk(mi)!=-1) lo = mi;
    else hi = mi-1;
  }

  int m = lo;
  cout << m << endl;
  i = chk(m);
  cout << m << endl;
  vector<pii> v;
  rep(a, 0, N) if(s[a].fi >= m) v.pb({s[a].se, a+1});
  sort(all(v));
  rep(a, 0, m) cout << v[a].se <<' ';


	return 0;
}
