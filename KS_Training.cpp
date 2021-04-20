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
ll s[100010];
ll sm;

int main(){
	int a, b, c, d;
	int T, TT;
  cin >> TT;
  REPI(T, TT){
    sm = 20000000000;
    cin >> N >> k;
    REPI(a, N) scanf("%lld", s+a);
    sort(s+1, s+N+1);
    REPI(a, N-1) s[a+1] += s[a];
    REPI(a, N-k+1){
      ll t = (s[a+k-1]-s[a+k-2])*k - s[a+k-1]+s[a-1];
      sm = min(sm, t);
    }
    printf("Case #%d: %lld\n", T, sm); 
  }



	return 0;
}
