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
long long *v = new long long[1000000000];

int main(){
	int a, b, c, d;
	int T;
  v[1] = 1;
  v[2] = 2;
  for(i=3;i<=1000000000;i++){
    v[i] = max(v[i], v[i/2]+v[i/3]+v[i/4]);
  }
  while(cin >> N){
    printf("%I64d\n", v[N]);
  }
  /* cin >> N; */
  /* cout << v[N]; */


	return 0;
}
