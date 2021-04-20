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
#define len(x) (int)(x).size()

using namespace std;

int i, N, M, K, k;
string S;

int main(){
	int a, b, c, d;
	int T;
  cin >> T;
  while(T--){
    scanf("%d", &N);
    cin >> S;
    for(a=0;a<N;a++){
      if(S[a] == '>') break;
    }
    c = a;
    for(a=N-1;a>=0;a--){
      if(S[a] == '<') break;
    }
    d = a;
    printf("%d\n", min(c, N-d-1));
  }



	return 0;
}
