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
string s[500010];

int cmp(int x, int y){

  for(int a=0;a<len(s[x]);a++){
    if(a == len(s[y]) or s[x][a] > s[y][a]){
      int t = len(s[x])-a;
      s[x] = s[x].substr(0, a);
      return t;
    }
    if(s[x][a] == s[y][a]) continue;
    if(s[x][a] < s[y][a]) return 0;
  }
  return 0;
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N;
  rep(a, 0, N){
    cin >> s[a];
  }
  int cnt = 0;
  for(a=N-2;a>=0;a--){
    c = cmp(a, a+1);
    cnt += c;
  }
  rep(a, 0, N) cout << s[a] << '\n';


	return 0;
}
