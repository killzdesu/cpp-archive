#include "bits/stdc++.h"
#define rep(i, x,y) for(i=(int)x;i<(int)y;i++)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define pb push_back
#define dump(x) cout <<(#x) << " = " << x << "\n";
#define dump_all(s) cout<<(#s)<<":\n";for(auto x:s)cout<<x<<" ";cout<<"\n";

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;


int i, N, M;
char s[100010];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
  int eight=0, pre=2e9;
	int T;
  cin >> N;
  cin >> s;
  rep(a, 0, N) if(s[a]=='8') eight++, pre=min(pre, a);
  pre++;
  int P = (N-11)/2;
  int V = (N-11-P);
  /* cout<<V<<' '<<P; */
  /* dump(pre);dump(eight); */
  if( eight <= P ) {cout << "NO"; return 0;}
  /* if( pre > V ) { cout << "NO"; return 0;} */
  i = 0;
  rep(a, 0, N){
    if(s[a] == '8') i++;
    if( P+1 == i ) break;
  }
  /* dump(a-P); */
  if( V < a-P ) { cout << "NO"; return 0;} 

  cout << "YES";

	return 0;
}
