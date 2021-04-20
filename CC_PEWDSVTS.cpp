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
int A, B, X, Y, Z;
int s[100010];
priority_queue<int> q;
vector<int> con;

int chk(int m){
  int t = Z-A-con[m];
  t = (int)ceil((double)t/(1.0*X));
  return Z > B+Y*t;
}
vector<int> tmp;

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> T;
  while(T--){
    cin >> N >> A >> B >> X >> Y >> Z;
    tmp.clear();
    vector<int> res[31];
    con.clear();
    rep(a, 0, N){
      cin >> s[a];
      tmp.pb(s[a]);
    }
    sort(all(tmp), greater<int>());
    copy(all(tmp), res[0].begin());
    rep(a, 1, 31){
      for(auto x: res[a-1]) if(x/2!=0) res[a].pb(x/2);
      if(res[a].size() == 0) break;
    }
    rep(i, 0, a){
      tmp = res[0]
    }

    /* sort(all(tmp), greater<int>()); */
    con.pb(0);
    for(auto x: tmp) con.pb(con[len(con)-1]+x);
    tmp.clear();
    /* dump_all(con); */
    int lo=0, hi=len(con)-1, mi;
    while(lo < hi){
      mi = (lo+hi)/2;
      if(chk(mi)) hi = mi;
      else lo = mi+1;
    }
    if(chk(lo)) cout << lo << '\n';
    else cout << "RIP\n";
  }



	return 0;
}
