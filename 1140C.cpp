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
ll sum;
priority_queue<ll, vector<ll>, greater<ll> > q;
pair<ll, ll> s[300010];

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
  if(a.se!=b.se) return a.se > b.se;
  return a.fi > b.fi;
}

int main(){
	int a, b, c, d;
	int T;
  cin >> N >> k;
  REP(a, N){
    scanf("%lld %lld", &s[a].fi, &s[a].se);
  }
  sort(s, s+N, cmp);
  ll cnt = 0, mx = 0;
  REP(a, N){
    q.push(s[a].fi);
    cnt += s[a].fi;
    while(q.size() > k){
      cnt -= q.top();
      q.pop();
    }
    mx = max(mx, s[a].se*cnt);
  }
  cout << mx;

	return 0;
}
