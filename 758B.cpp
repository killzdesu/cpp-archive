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
string sc;
char s[5];
map<char, int> m;
int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> sc;
  rep(a, 0, len(sc)){
    if(sc[a]!='!') s[a%4] = sc[a];
  }
  rep(a, 0, len(sc)){
      if(sc[a] == '!')
        m[s[a%4]]++;
  }
  cout << m['R'] << ' ' << m['B'] << ' ' << m['Y'] << ' ' << m['G'];


	return 0;
}
