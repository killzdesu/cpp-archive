#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(x,y) for(x=0;x<(int)y;x++)
#define REPI(x,y) for(x=1;x<=(int)y;x++)
#define pii pair<int,int>
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define len(x) (x).size()

using namespace std;

int i, N, M, K, k;
ll s[100010], D;
vector<ll> cp;

struct Node{
  int lo, hi;
  pii val;
};
Node t[100010*6];

void build(int x, int l, int r){
  t[x].lo = l;
  t[x].hi = r;
  if(l == r-1){
    t[x].val.fi = 0;
    t[x].val.se = l;
    return;
  }
  build(x*2, l, (l+r)/2);
  build(x*2+1, (l+r)/2, r);
  t[x].val = max(t[x*2].val, t[x*2+1].val);
}

void update(int x, int tar, int v){
  if(t[x].lo > tar or t[x].hi <= tar) return;
  if(t[x].lo == t[x].hi-1){
    t[x].val = max(mp(v, t[x].lo), t[x].val);
    return;
  }
  update(x*2, tar, v);
  update(x*2+1, tar, v);
  t[x].val = max(t[x*2].val, t[x*2+1].val);
}

pii query(int x, int l, int r){
  if(t[x].hi <= l or t[x].lo >= r) return {-2e9, N+1};
  if(l <= t[x].lo and t[x].hi <= r) return t[x].val;
  return max(query(x*2, l, r), query(x*2+1, l, r));
}

unordered_map<ll, int> m;
int bt[100010];
int mx[100010];

int main(){
	int a, b, c, d;
	int T;
  cin >> N >> D;
  REP(a, N) scanf("%lld", s+a);
  REP(a, N) cp.pb(s[a]);
  sort(ALL(cp));
  cp.resize(distance(cp.begin(), unique(ALL(cp))));
  REP(a, cp.size()) m[cp[a]] = a;
  build(1, 0, N);
  int lb, ub;
  REP(a, N){
    lb = lower_bound(ALL(cp), s[a]-D+1)-cp.begin();
    ub = upper_bound(ALL(cp), s[a]+D-1)-cp.begin();
    pii p = max(query(1, 0, lb), query(1, ub, N));
    /* printf("%d:  %d %d --> %d\n", a, lb, ub, c); */
    bt[a] = cp[p.se];
    if(p.fi == 0) bt[a] = -1;
    mx[a] = p.fi+1;
    update(1, m[s[a]], p.fi+1);
    /* printf(":: %d %d\n", bt[a], p.se); */
  }
  pii ans = query(1, 0, N);
  printf("%d\n", ans.fi);
  stack<int> S;
  c = ans.fi;
  for(a=N-1;a>=0;a--) if(mx[a] == ans.fi) break;
  ll past = s[a];
  S.push(a+1);
  c--;
  for(a--;a>=0;a--){
    if(mx[a] == c && (s[a]+D <= past or s[a]-D >= past) ){
      S.push(a+1);
      past = s[a];
      c--;
    }
  }
  while(!S.empty()){
    printf("%d ", S.top());
    S.pop();
  }
  
	return 0;
}
