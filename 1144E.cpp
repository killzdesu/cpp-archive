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
int A[200010], B[200010];

int main(){
	int a, b, c, d;
	char T[200010];
  cin >> N;
  cin >> T;
  REP(a, N) A[a] = T[a]-'a';
  cin >> T;
  REP(a, N) B[a] = T[a]-'a';
  for(a=N-1;a>=0;a--){
    B[a]-=A[a];
    if(B[a] < 0 and (a)){
      B[a] += 26;
      B[a-1]--;
    }
  }
  REP(a, N){
    B[a+1] += (B[a]%2)*26;
    B[a]/=2;
  }
  for(a=N-1;a>=0;a--){
    A[a] += B[a];
    if(A[a] >= 26 and a) A[a-1]++;
    T[a] = (A[a]%26)+'a';
  }
  cout << T;


	return 0;
}
