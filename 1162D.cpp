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
vector<int> f;
vector<int> e[100010];
int can[500];

void fact(){
  int a;
  f.pb(1);
  for(int i=2;i<=320;i++){
    if(N == i) break;
    if(N%i == 0) f.pb(i), f.pb(N/i);
  }
  sort(all(f));
  f.erase(unique(all(f)), f.end());
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N >> M;
  fact();
  reverse(all(f));
  rep(a, 0, M){
    cin >> c >> d;
    c--; d--;
    if(c > d) swap(c, d);
    e[c].pb(d-c);
    e[d].pb((N+c-d));
  }
  rep(a, 0, N) sort(all(e[a]));
  int p;
  /* dump_all(f); */
  rep(i, 0, len(f)){
    if(can[i] == 1) continue;
    p = f[i];
    /* dump(p); */
    rep(a, 0, p){
      d = N/p;
      rep(b, 1, d){
        c = b*p+a;
        if(len(e[a]) != len(e[c])) can[i] = 1;
        /* else if(e[a]!=e[b*p+a]) can[i] = 1; */
        else {
          for(int k=0;k<len(e[a]);k++) if(e[a][k]!=e[c][k]){
            can[i] = 1;
            break;
          }
        }
        if(can[i]){
          /* cout << a << ' ' << b*p+a << '\n'; */
          /* dump_all(e[a]); */
          /* dump_all(e[b*p+a]); */
          break;
        }
      }
      if(can[i]) break;
    }
    if(can[i] == 0){
      cout << "Yes";
      return 0;
    }
    for(a=i+1;a<len(f);a++) if(f[i]%f[a]==0) can[a] = 1;
  }


  cout << "No";
	return 0;
}
