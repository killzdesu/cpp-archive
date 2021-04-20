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
int s[200010];

int main(){
	int a, b, c, d;
	int T;
  ll cnt = 0;
  cin >> N;
  REP(a, N) scanf("%d", &s[a]);
  ll last = (ll)2e9, t;
  for(a=N-1;a>=0;a--){
    t = min(last-1, (ll)s[a]);
    t = max(t, 0LL);
    cnt += t;
    last = t;
  }
  cout << cnt;

	return 0;
}
