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

using namespace std;

int i, N, M, K, k;

int main(){
	int a, b, c, d;
	int T;
  char tc;
  cin >> T;
  N = 0, M = 0;
  while(T--){
    scanf(" %c %d %d", &tc, &c, &d);
    if(c>d) swap(c, d);
    if(tc == '+'){
      N = max(c, N);
      M = max(d, M);
    }
    if(tc == '?'){
      if(N<=c and M<=d) printf("YES\n");
      else printf("NO\n");
    }
    /* printf(" ---- > %d %d\n", N, M); */
  }



	return 0;
}
