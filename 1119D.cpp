#include "bits/stdc++.h"
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(x,y) for(x=0;x<(int)y;x++)
#define REPI(x,y) for(x=1;x<=(int)y;x++)
#define pii pair<int,int>
#define ll unsigned long long
#define ALL(x) (x).begin(),(x).end()
#define len(x) int((x).size())

using namespace std;

int i, N, M, K, k;
ll s[100010];
priority_queue<ll, vector<ll>, greater<ll> > q;
vector<ll> inc,v,w;

void solve1(){
  int T;
  cin >> T;
  long long C, D;
  while(T--){
    cin >> C >> D;
    C = D-C+1;
    cout << C << " ";
    /* printf("%lld ", C); */
  }
}

int main(){
	int a, b, c, d;
	int T;
  cin >> N;
  REP(a, N) cin >> s[a];
  sort(s, s+N);
  if(N==1){
    solve1();
    return 0;
  }
  ll t;
  REP(a, N-1){
    t = s[a+1]-s[a]+1;
    q.push(t);
  }
  ll sm = (q.top()-1)*(ll)N;
  while(!q.empty()){
    t = q.top();
    while(!q.empty() and q.top() == t) q.pop();
    w.pb(t);
    inc.pb(q.size()+1);
    v.pb(sm);
    if(q.empty()) break;
    sm += (q.top()-t)*(q.size()+1);
  }
  /* for(ll x:w) printf("%I64d ",(int64_t)x); printf("\n"); */
  /* for(ll x:inc) printf("%I64d ",(int64_t)x); printf("\n"); */
  /* for(ll x:v) printf("%I64d ",(int64_t)x); printf("\n"); */

  cin >> T;
  ll C,D;
  while(T--){
    cin >> C >> D;
    C = D-C+1;
    auto it = upper_bound(ALL(w), C);
    it--;
    a = it-w.begin();
    if(a!=-1){
      C = C-w[a]+1;
      /* printf("%.0lf ", (inc[a]*(C))+v[a]); */
      cout << (inc[a]*(C))+v[a] << " ";
    }
    else {
      cout << (ll)N*(C) << " ";
      /* printf("%.0lf ", (ll)N*(C)); */
    }
  }

	return 0;
}
