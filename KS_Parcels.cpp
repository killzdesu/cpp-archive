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
int s[300][300];
bool u[300][300];

int dif(int x, int y){
  return (x<y?y-x:x-y);
}

int main(){
	int a, b, c, d, i, j;
	int T, TT;
  cin >> TT;
  REPI(T, TT){
    cin >> N >> M;
    REPI(a, N) REPI(b, M) scanf("%1d", &s[a][b]);
    int t, mx, mn = 2e6;
    REPI(a, N) REPI(b, M){
      if(s[a][b] == 1) continue;
      mx = 0;
      s[a][b] = 1;
      REPI(c, N) REPI(d, M){
        if(s[c][d] == 1) continue;
        /* printf("%d %d\n", c, d); */
        t = 2e9;
        REPI(i, N) REPI(j, M){
          if(s[i][j] == 0) continue;
          t = min(t, dif(i, c)+dif(j, d));
        }
        /* printf("> %d\n", t); */
        mx = max(mx, (t>2e8?0:t));
      }
      s[a][b] = 0;
      mn = min(mn, mx);
    }
    if(mn >= 1e6) mn = 0;
    printf("Case #%d: %d\n", T, mn);
  }
          



	return 0;
}
