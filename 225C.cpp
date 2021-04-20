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
#define len(x) (x).size()

using namespace std;

int i, N, M, K, k;
char s[1010][1010];
int dp[1003][2][1010];
int cl[1010][2];

int clean(int x, char o){
  int cnt = 0;
  for(int i=1;i<=N;i++) cnt += (s[i][x]==o);
  return cnt;
}

int main(){
	int a, b, c, d;
	int T;
  int w_mx, w_mn;
  cin >> N >> M >> w_mn >> w_mx;
  REPI(a, N) scanf("%s", s[a]+1);
  REPI(a, M){
    cl[a][0] = clean(a, '.');
    cl[a][1] = clean(a, '#');
    cl[a][0] += cl[a-1][0];
    cl[a][1] += cl[a-1][1];
  }
  /* REPI(a, N){ REPI(b, M) printf("%c",s[a][b]);printf("\n");} */
  REP(b, M+3) REP(i, 2) REP(a, w_mx+2) dp[b][i][a] = 2e8;
  dp[w_mn][0][w_mn] = cl[w_mn][0];
  dp[w_mn][1][w_mn] = cl[w_mn][1];
  for(b=w_mn+1;b<=M;b++){
    REP(i, 2){
      for(a=w_mn+1;a<=w_mx;a++){
        dp[b][i][a] = min(dp[b][i][a], dp[b-1][i][a-1]+cl[b][i]-cl[b-1][i]);
      }
      c = cl[b][i]-cl[b-w_mn][i];
      for(a=w_mn;a<=w_mx;a++){
        dp[b][i][w_mn] = min(dp[b][i][w_mn], dp[b-w_mn][i^1][a]+c);
      }
    }
  }
  /* REPI(b, M) REP(i, 2) for(a=w_mn;a<=w_mx;a++) printf("%d %d %d: %d\n", b, i, a, dp[b][i][a]); */
  int ans = 2e9;
  REP(a, 2) for(b=w_mn;b<=w_mx;b++) ans = min(ans, dp[M][a][b]);
  cout << ans;

	return 0;
}
