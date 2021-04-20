#include "bits/stdc++.h"
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(x,y) for(x=0;x<(int)y;x++)
#define REPI(x,y) for(x=1;x<=(int)y;x++)
#define pii pair<int,int>
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define len(x) int((x).size())

using namespace std;

int i, N, M, K, k;
int s[300010];

int main(){
	int a, b, c, d;
	int T;
  cin >> N;
  REP(a, N) cin >> s[a];
  int mx = 0;
  REP(a, N) if(s[a]!=s[N-1]) break;
  mx = max(mx, N-1-a);
  for(a=N-1;a>=0;a--) if(s[a]!=s[0]) break;
  mx = max(mx, a);
  cout << mx;

	return 0;
}
