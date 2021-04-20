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
char s[100][100];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N;
  rep(a, 0, N) rep(b, 0, N) cin >> s[a][b];
  rep(a, 0, N) rep(b, 0, N){
    if(s[a][b] == '.'){
      if(s[a+1][b]!='.' or s[a+1][b-1]!='.' or s[a+1][b+1]!='.' or s[a+2][b]!='.'){
        cout << "NO";
        return 0;
      }
      s[a][b] = s[a+1][b] = s[a+1][b-1] = s[a+1][b+1] = s[a+2][b] = '#';
    }
  }
  cout << "YES";


	return 0;
}
