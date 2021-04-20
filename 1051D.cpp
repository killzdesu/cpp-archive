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
int dp[1003][4][2005];
int const MOD = 998244353;

int main(){
	int a, b, c, d;
	int T;
  cin >> N >> k;
  dp[0][0][1] = dp[0][1][1] = dp[0][2][2] = dp[0][3][2] = 1;
  REPI(a, N-1) {
    REPI(b, k){
      REP(d, 4){
        REP(c, 4){
          if(c == d){
            dp[a][d][b] += dp[a-1][c][b];
          }
          else if(c==0 or c==1){
            dp[a][d][b] += dp[a-1][c][b-1];
          }
          else if(c+d==5 and b>1){
            dp[a][d][b] += dp[a-1][c][b-2];
          }
          else if(c==2 or c==3){
            dp[a][d][b] += dp[a-1][c][b];
          }
          dp[a][d][b] %= MOD;
          /* printf("%d %d %d, %d:  %d\n", a, d, c, b, dp[a][d][b]); */
        }
      }
    }
  }
  int sm = 0;
  REP(a, 4){
    sm += dp[N-1][a][k];
    sm %= MOD;
  }
  cout << sm;




	return 0;
}
