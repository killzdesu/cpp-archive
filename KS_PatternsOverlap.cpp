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
#define len(x) (int)((x).size())

using namespace std;

int i, N, M, K, k;

char tmp[2005];
string s1, s2;
bool dp[10005][10005];
bool chk[10005][10005];

void solve(int x, int y){
  if(chk[x][y] != 0) return;
  if(x==0 and y==0) return;
  chk[x][y] = 1;
  if(x and y){
    if(s1[x-1]==s2[y-1] or s1[x-1]=='*' or s2[y-1]=='*'){
      solve(x-1,y-1);
      dp[x][y] |= dp[x-1][y-1];
    }
  }
  if(x){
    if(s1[x-1]=='*'){
      solve(x-1, y); dp[x][y] |= dp[x-1][y];
    }
  }
  if(y and s2[y-1]=='*'){
    solve(x, y-1);
    dp[x][y] |= dp[x][y-1];
  }
  /* printf("%d %d >> %d\n", x, y, dp[x][y]); */
}

int main(){
  ofstream out;
  out.open("B.lg.out");
	int a, b, c, d;
	int _T, T;
  cin >> _T;
  REPI(T, _T){
    // Input
    scanf("%s", tmp);
    N = strlen(tmp);
    s1.clear();
    s2.clear();
    REP(a, N){
      s1.push_back(tmp[a]);
      if(tmp[a] == '*') REP(i, 3) s1.push_back('*');
    }
    scanf("%s", tmp);
    N = strlen(tmp);
    REP(a, N){
      s2.push_back(tmp[a]);
      if(tmp[a] == '*') REP(i, 3) s2.push_back('*');
    }
    
    // Calculation
    REP(a, len(s1)+2) REP(b, len(s2)+2) chk[a][b] = dp[a][b] = 0;
    dp[0][0] = 1;
    solve(len(s1), len(s2));
    string ans="";
    if(dp[len(s1)][len(s2)]==1) ans += "TRUE";
    else ans += "FALSE";
    printf("Case #%d: %s\n", T, ans.c_str());
  }



	return 0;
}
