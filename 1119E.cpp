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
  REP(a, N) scanf("%d",s+a);
  ll ans = 0;
  c = 0;
  for(a=N-1;a>=0;a--){
    if(s[a]==0) continue;
    if(c == 1){
      /* s[a] -= c; */
      /* c = 0; ans++; */
    }
    ans += s[a]/3;
    s[a] %= 3;
    if(s[a]==2) c = 1;
  }

  cout << ans;
	return 0;
}
