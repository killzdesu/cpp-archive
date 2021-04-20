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
int ct[100];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> T;
  while(T--){
    rep(a, 0, 100) ct[a] = 0;
    string s;
    cin >> s;
    rep(a, 0, len(s)){
      ct[s[a]-'a']++;
    }
    /* rep(a, 0, 26) cout << ct[a] <<' ';cout << '\n'; */
    N = len(s);
    s.clear();
    rep(a, 0, N){
      if(a == 0) c = -2;
      int mx = 0;d = -1;
      rep(b, 0, 26){
        if(b == c+1 or b == c-1) continue;
        if(ct[b] > mx) mx = ct[b], d = b;
      }
      dump(d);
      if(d == -1) break;
      s.pb((char)(d+'a'));
      ct[d]--;
      c = d;
    }
    /* dump(d); */
    if(d == -1)
      cout << "No answer\n";
    else cout << s << "\n";

  }



	return 0;
}
