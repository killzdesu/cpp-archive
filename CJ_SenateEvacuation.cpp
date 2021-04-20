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

int main(){
	int a, b, c, d;
	int T,Tx;
  cin >> Tx;
  REPI(T, Tx){
    int cnt = 0;
    printf("Case #%d: ", T);
    cin >> N;
    vector<pii> s;
    REP(a, N){
      cin >> c;
      s.pb({c, a});
    }
    sort(ALL(s), greater<pii>());
    /* for(auto x:s) printf("%d ", x.fi); */
    while(s[0].fi > s[1].fi){
      printf("%c ", s[0].se+'A');
      s[0].fi--;
    }
    for(int i=2;i<N;i++){
      REP(a, s[i].fi) printf("%c ", s[i].se+'A');
    }
    REP(a, s[0].fi) printf("%c%c ", s[0].se+'A', s[1].se+'A');
    printf("\n");
  }

	return 0;
}
