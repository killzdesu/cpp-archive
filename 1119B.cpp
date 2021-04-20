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

int i, N, M, K, k, H;
int s[1010];
int t[1010];

bool check(int p){
  int a;
  ll b;
  REP(a, p) t[a] = s[a];
  sort(t, t+p, greater<int>() );
  b = 0;
  for(a=0;a<p;a+=2){
    b += t[a];
    if(b > H) return false;
  }
  return b <= H;
}

int main(){
	int a, b, c, d;
	int T;
  cin >> N >> H;
  REP(a, N) scanf("%d", s+a);
  int lo, hi, mi;
  lo = 1, hi = N;
  while(lo < hi){
    mi = (lo+hi+1)/2;
    if(check(mi)){
      lo = mi;
    }
    else {
      hi = mi-1;
    }
  }
  cout << lo;

	return 0;
}
