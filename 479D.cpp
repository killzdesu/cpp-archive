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
#define len(x) (x).size()

using namespace std;

int i, N, M, K, k;
int G, B;
unordered_map<int, int> u;
int s[100010];

int main(){
	int a, b, c, d;
	int T;
  cin >> N >> K >> G >> B;
  REP(a, N){
    scanf("%d", &c);
    s[a] = c;
    u[c] = 1;
    if(G and u[c-G]==1){
      G = 0;
    }
    if(B and u[c-B]==1){
      B = 0;
    }
  }
  if(!G and !B){puts("0"); return 0;}
  if(G and !B){
    printf("1\n%d", G);
    return 0;
  }
  if(B and !G){
    cout << 1 << endl << B;
    return 0;
  }
  REP(a, N){
    c = s[a];
    if(c+B < K) if(u[c+B+G]==1 or u[c+B-G]==1){
      cout << 1 << endl << c+B;
      return 0;
    }
    if(c+G < K) if(u[c+B+G]==1 or u[c+G-B]==1){
      cout << 1 << endl << c+G;
      return 0;
    }
    if(c-B > 0) if(u[c-B+G]==1 or u[c-B-G]==1){
      cout << 1 << endl << c-B;
      return 0;
    }
    if(c-G > 0) if(u[c-G+B]==1 or u[c-G-B]==1){
      cout << 1 << endl << c-G;
      return 0;
    }
  }
  cout << 2 << endl << B << ' ' << G;


	return 0;
}
