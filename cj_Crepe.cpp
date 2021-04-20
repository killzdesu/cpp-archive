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
vector<int> vx, vy;
map<int, int> X, Y;


pii s[600];
char di[600];
int p[1050][1050];

void reset(){
  X.clear();
  Y.clear();
  vx.clear();
  vy.clear();
  int a, b;
  rep(a, 0, 1020) rep(b, 0, 1020) p[a][b] = 0;
}

void add(int c, char C){
  int a, b;
  if(C == 'N'){
    p[0][c] += 1;
  }
  else if(C == 'S'){
    p[0][0] += 1;
    p[0][c+1] -= 1;
  }
  else if(C == 'W'){
    p[0][0] += 1;
    p[c+1][0] -= 1;
  }
  else if(C == 'E'){
    p[c][0] += 1;
  }
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
  int P;
  char dir;
	int T, TT;
  cin >> TT;
  rep(T, 1, TT+1){
    reset();
    cin >> N >> P;
    rep(a, 0, N){
      cin >> c >> d >> di[a];
      s[a].fi = c, s[a].se = d;
      if(di[a] == 'E') vx.pb(c+1);
      if(di[a] == 'W') vx.pb(c-1);
      if(di[a] == 'N') vy.pb(d+1);
      if(di[a] == 'S') vy.pb(d-1);
      vx.pb(c);
      vy.pb(d);
    }
    vx.pb(0); vy.pb(0);
    sort(all(vx)); sort(all(vy));
    vx.erase(unique(all(vx)), vx.end());
    vy.erase(unique(all(vy)), vy.end());
    rep(a, 0, len(vx)) X[vx[a]] = a;
    rep(a, 0, len(vy)) Y[vy[a]] = a;
    rep(a, 0, N){
      if(di[a] == 'S'){
        add(Y[s[a].se-1], 'S');
      }
      if(di[a] == 'N'){
        add(Y[s[a].se+1], 'N');
      }
      if(di[a] == 'E'){
        add(X[s[a].fi+1], 'E');
      }
      if(di[a] == 'W'){
        add(X[s[a].fi-1], 'W');
      }
    }
    int mx = 0;
    rep(a, 0, len(vx)+2) rep(b, 0, len(vy)+2){
      c = 0, d = 0, i = 0;
      /* if(b == 0) cout << '\n'; */
      /* cout << p[a][b] << ' '; */
      if(a) p[a][b] += p[a-1][b], c = p[a-1][b];
      if(b) p[a][b] += p[a][b-1], d = p[a][b-1];
      if(a && b) p[a][b] -= p[a-1][b-1],i = p[a-1][b-1];
      
      mx = max(mx, p[a][b]);
    }
    cout << "Case #"<<T<<": ";
    rep(a, 0, 1002) rep(b, 0, 1002) if(p[a][b] == mx){
      cout << vx[a] << ' ' << vy[b] << '\n';
      a = 2e8;
      b = 2e8;
    }
  }


	return 0;
}
