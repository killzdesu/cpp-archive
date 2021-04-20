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
int s[300][300];
int v[300][300];
int Max;

queue<pii> q;

void go(int a, int b, int x, int y){
  if(x > N or x < 1 or y > M or y < 1) return;
  if(s[x][y]==1) return;
  if(v[x][y] < 2e8) return;
  v[x][y] = v[a][b]+1; 
  q.push({x, y});
}

void fill(){
  int a, b;
  REPI(a, N) REPI(b, M){
    v[a][b] = 2e8;
    if(s[a][b]) q.push({a, b}), v[a][b] = 0;
  }
  while(!q.empty()){
    a = q.front().fi;
    b = q.front().se;
    go(a, b, a-1, b);
    go(a, b, a+1, b);
    go(a, b, a, b-1);
    go(a, b, a, b+1);
    q.pop();
  }
  /* REPI(a, N){ */
  /*   REPI(b, M) printf("%d ", v[a][b]); */
  /*   printf("\n"); */
  /* } */
  Max = 0;
  REPI(a, N) REPI(b, M) Max = max(Max, v[a][b]);
} 

vector<pii> mxn;

int main(){
	int a, b, c, d;
	int T, TT;
  char tc;
  cin >> TT;
  REPI(T, TT){
    cin >> N >> M;
    REPI(a, N) REPI(b, M) scanf("%1d", &s[a][b]);
    fill();
    mxn.clear();
    REPI(a, N) REPI(b, M) if(v[a][b] == Max) mxn.pb({a, b});
    c = 0; d = 0;
    for(auto x:mxn){
      c += x.fi, d += x.se;
      /* printf(": %d %d\n", x.fi, x.se); */
    }
    c = (int)floor((double)c/len(mxn));
    d = (int)floor((double)d/len(mxn));
    /* printf(">> %d %d\n", c, d); */
    int nx = c, ny = d;
    int ans = Max;
    if(s[nx][ny] != 1){
      s[nx][ny] = 1;
      fill();
      s[nx][ny] = 0;
      ans = min(ans, Max);
    }
    nx++;
    if(s[nx][ny] != 1){
      s[nx][ny] = 1;
      fill();
      s[nx][ny] = 0;
      ans = min(ans, Max);
    }
    ny++;
    if(s[nx][ny] != 1){
      s[nx][ny] = 1;
      fill();
      s[nx][ny] = 0;
      ans = min(ans, Max);
    }
    nx--;
    if(s[nx][ny] != 1){
      s[nx][ny] = 1;
      fill();
      s[nx][ny] = 0;
      ans = min(ans, Max);
    }
    printf("Case #%d: %d\n", T, ans);
  }

	return 0;
}
