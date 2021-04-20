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
vector<ll> P;
unordered_map<int, int> lp;

const int MAX = 100000;

void sieve(){
  P.pb(2);
  for(int i=3;i<MAX;i+=2){
    if(lp[i]==0){
      lp[i] = i;
      P.pb(i);
    }
    for(auto x:P){
      ll k = x*i;
      if(x > lp[i] or k > MAX) break;
      lp[(int)k] = x;
    }
  }
}

int main(){
	int a, b, c, d;
	int T;
  cin >> T;
  sieve();

  while(T--){
    cin >> N >> M;
    for(a=N;a<=M;a++){
      if(a==1) continue;
      i = true;
      for(auto x:P){
        if(a==x) printf("%d\n", a), i=0;
        else if(a%x==0) { i=false;break; }
      }
      if(i) printf("%d\n", a);
    }
    printf("\n");
  }



	return 0;
}
