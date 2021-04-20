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
vector<int> v;

bool can(int x){
  k = 0; i = -x;
  for(auto p:v){
    if(p-i >= x){
      k++; i = p;
    }
  }
  /* printf(">%d\n", k); */
  return k>=M;
}

int main(){
	int a, b, c, d;
	int T;
  cin >> T;
  while(T--){
    v.clear();
    scanf("%d%d",&N,&M);
    REP(a, N){
      scanf("%d",&c);
      v.pb(c);
    }
    sort(ALL(v));
    int lo, mi, hi;
    lo = 0, hi = 1000000000;
    while(lo < hi){
      /* printf("%d %d\n", lo, hi); */
      mi = lo+(hi-lo+1)/2; 
      if(can(mi)) lo = mi;
      else hi = mi-1;
    }
    cout << lo << '\n';
  }


	return 0;
}
