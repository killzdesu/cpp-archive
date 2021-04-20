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
int s[1010][1010];
ll dpf00[1010][1010];
ll dpfn0[1010][1010];
ll dpfnm[1010][1010];
ll dpf0m[1010][1010];

void fn0(){
  int a, b;
  for(a=N-1;a>=0;a--) REP(b, M){
    dpfn0[a][b] = s[a][b];
    if(a!=N-1) dpfn0[a][b] = max(dpfn0[a][b], dpfn0[a+1][b]+s[a][b]);
    if(b) dpfn0[a][b] = max(dpfn0[a][b], dpfn0[a][b-1]+s[a][b]);
  }
}
void f00(){
  int a, b;
  REP(a, N) REP(b, M){
    dpf00[a][b] = s[a][b];
    if(a) dpf00[a][b] = max(dpf00[a][b], dpf00[a-1][b]+s[a][b]);
    if(b) dpf00[a][b] = max(dpf00[a][b], dpf00[a][b-1]+s[a][b]);
  }
}
void f0m(){
  int a, b;
  REP(a, N) for(b=M-1;b>=0;b--){
    dpf0m[a][b] = s[a][b];
    if(a) dpf0m[a][b] = max(dpf0m[a][b], dpf0m[a-1][b]+s[a][b]);
    if(b!=M-1) dpf0m[a][b] = max(dpf0m[a][b], dpf0m[a][b+1]+s[a][b]);
  }
}
void fnm(){
  int a, b;
  for(a=N-1;a>=0;a--) for(b=M-1;b>=0;b--){
    dpfnm[a][b] = s[a][b];
    if(a!=N-1) dpfnm[a][b] = max(dpfnm[a][b], dpfnm[a+1][b]+s[a][b]);
    if(b!=M-1) dpfnm[a][b] = max(dpfnm[a][b], dpfnm[a][b+1]+s[a][b]);
  }
}

int main(){
	int a, b, c, d;
	int T;
  cin >> N >> M;
  REP(a, N) REP(b, M) scanf("%d", &s[a][b]);
  fn0();
  f00();
  fnm();
  f0m();
  /* printf("===\n"); */
  /* REP(a, N){REP(b, M) printf("%d ", dpf00[a][b]);printf("\n");} */
  /* printf("===\n"); */
  /* REP(a, N){REP(b, M) printf("%d ", dpfn0[a][b]);printf("\n");} */
  /* printf("===\n"); */
  /* REP(a, N){REP(b, M) printf("%d ", dpf0m[a][b]);printf("\n");} */
  /* printf("===\n"); */
  /* REP(a, N){REP(b, M) printf("%d ", dpfnm[a][b]);printf("\n");} */
  ll mx = 0, t;
  REPI(a, N-2) REPI(b, M-2){
    t = 0;
    if(b) t+=dpf00[a][b-1];
    if(a) t+=dpf0m[a-1][b];
    if(b!=M-1) t+= dpfnm[a][b+1];
    if(a!=N-1) t+= dpfn0[a+1][b];
    /* printf(": %d %d %d %d\n", dpf00[a][b-1], dpf0m[a-1][b], dpfnm[a][b+1], dpfn0[a+1][b]); */
    mx = max(mx, t);
    t = 0;
    if(a) t+=dpf00[a-1][b];
    if(b) t+=dpfn0[a][b-1];
    if(b!=M-1) t+= dpf0m[a][b+1];
    if(a!=N-1) t+= dpfnm[a+1][b];
    /* printf(": %d %d %d %d\n", dpf00[a-1][b], dpfn0[a-1][b], dpf0m[a][b+1], dpfnm[a+1][b]); */
    mx = max(mx, t);
  }
  cout << mx;

	return 0;
}
