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
int s[504][504];
int o[504][504];
set<int> v[504], h[504];

void END(){puts("No");exit(0);}

int main(){
	int a, b, c, d;
	int T;
  cin >> N >> M;
  REP(a, N)REP(b, M) scanf("%d",&s[a][b]);
  REP(a, N)REP(b, M){
    scanf("%d", &c);
    s[a][b] = (s[a][b]==c?0:1);
    if(s[a][b]) h[a].insert(b), v[b].insert(a);
  }
  /* REP(a, N){ */
  /*   REP(b, M) printf("%d", s[a][b]); */
  /*   printf("\n"); */
  /* } */

  REP(a, N){
    REP(b, M){
      if(s[a][b]==0) continue;
      if(len(h[a]) == 1 or len(v[b])==1) 
        /* printf("%d %d: %d %d", c, d, len(h[a]), len(v[b])), */ 
        END();
      /* printf(">> %d %d\n", len(h[a]), len(v[b])); */
      /* for(auto x: h[a]) printf("%d ", x); printf("\n"); */
      /* for(auto x: v[b]) printf("%d ", x); printf("\n"); */
      h[a].erase(b); v[b].erase(a);
      d = *(h[a].begin());
      c = *(v[b].begin());
      h[a].erase(d);
      v[b].erase(c);

      h[c].erase(b); v[b].erase(c);
      h[a].erase(d); v[d].erase(a);
      s[a][d] = 0;
      s[c][b] = 0;
      /* printf("> %d %d: %d %d\n", a, b, c, d); */
      /* for(auto x: h[a]) printf("%d ", x); printf("\n"); */
      /* for(auto x: v[b]) printf("%d ", x); printf("\n"); */
      if(s[c][d] == 0){
        s[c][d] = 1;
        h[c].insert(d);
        v[d].insert(c);
      }
      else {
        s[c][d] = 0;
        h[c].erase(d);
        v[d].erase(c);
      }
    }
  }
  cout << "Yes";

	return 0;
}
