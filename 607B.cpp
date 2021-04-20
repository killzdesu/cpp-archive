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
int s[505];
int dp[505][505];

int main(){
	int a, b, c, d;
	int T;
  cin >> N;
  REP(a, N) scanf("%d", s+a);
  REP(i, N){
    REP(a, N-i){
      b = a+i;
      dp[a][b] = 2e8;
      if(i==0){ dp[a][a]=1; continue;}
      if(i==1){ dp[a][b]=(s[a]==s[b]?1:2); continue;}
      if(s[a]==s[b]) dp[a][b] = min(dp[a][b], dp[a+1][b-1]);
      for(c=a;c<b;c++){
        dp[a][b] = min(dp[a][b], dp[a][c]+dp[c+1][b]);
      }
    }
  }
  /* REP(a, N) REP(b, N) if(a<=b) printf("%d %d: %d\n", a, b, dp[a][b]); */
  cout << dp[0][N-1];


	return 0;
}
