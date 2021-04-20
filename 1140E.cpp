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

int i, N, M;
ll K;
int s[200010];
ll const MOD = 998244353;

void chk2(){
  for(int i=2;i<N-2;i++){
    if(s[i-2] != s[i+2]){
      cout << 0;
      exit(0);
    }
  }
}
ll mm[200010];

int main(){
	int a, b, c, d;
	int T;
  cin >> N >> K;
  REP(a, N) scanf("%d", s+a);
  ll mul = 1;
  ll rt, lt;
  for(a=0;a<N;a++){
    if(a > 1 and s[a]!=-1 and s[a]==s[a-2]) mul = 0;
    if(s[a] == -1){
      lt = rt = 0;
      if(a >= 2) {
        lt = 1;  
      }
      if(a < N-2){
        if(s[a+2]!=-1){
          if(a > 1 and s[a-2]!=-1){
            if(s[a-2]!=s[a+2]) rt = 1;
            else rt = 0;
          }
          else if(a < 2) rt = 1;
        }
        else if(a < N-4 and s[a+4]!=-1){
          rt = -1;
          s[a+2] = -2;
        }
      }
      if(rt != -1){
        mul *= (K-lt-rt);
      }
      else {
        mul = mul*(K-1) + mul*(K-lt-1)*(K-2);
      }
      mul %= MOD;
    }
  } 


  cout << mul % MOD;
	return 0;
}
