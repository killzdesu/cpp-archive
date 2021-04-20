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
int mem[125][6];
int p[6];

struct RNG {
    int operator() (int n) {
        return rand() / (1.0 + RAND_MAX) * n;
    }
};

int isin(int x, int id){
    int a;
    rep(a, 0, 3) if(mem[id][a] == x) return true;
    return false;
}

int main(){
  auto rng = default_random_engine {};
  srand(time(0));

  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T, TT;
  vector<int> g;
  int u[10];
  int Q;
  cin >> TT >> Q;
  rep(a, 0, 119) g.pb(a);
  char C;
  rep(T, 1, TT+1){
    M = Q;
    N = 119;
    int X, Y;
    string ANS = "";
    rep(a, 0, 5) u[a] = 0;
    rep(i, 1, 5){
      rep(a, 0, 7) p[a] = 0;
      random_shuffle(all(g));
      c = 5-i+1;
      if(i == 4){
        rep(a, 0, 5) if(!u[a]) break; X = a;
        for(a++;a<5;a++) if(!u[a]) break; Y = a;
        /* cerr << "M " << M << "\n"; */
      }
      int cri = 0;
      if(M <= 118) cri = 1;
      rep(a, 0, N){
        if(i == 4 and cri and isin(X, g[a]) and isin(Y, g[a])){
          /* cerr << "sk\n"; */
          continue;
        }

        cout << 5*g[a]+i << endl; cin >> C;
        mem[g[a]][i-1] = (int)(C-'A');
        M--;
        p[C-'A']++;
        if(p[C-'A'] == 24 and u[C-'A']==0) c--;
        if(c == 1){
          /* cerr << "Break at " << a << '\n'; */
          break;
        }
        if(M == 0){
          /* cout << "ABCDE" << endl; */
          /* return 0; */
          break;
        }
      }
      rep(a, 0, 5) if(p[a]!=24 and !u[a]) break;
      ANS.pb((char)(a+'A'));
      u[a] = 1;
      /* cerr << c <<' '<< M << " C\n"; */
      /* rep(a, 0, 5){ */
      /*   cerr << (char)(a+'A') <<": "<<p[a]<<'\n'; */
      /* } */
      /* rep(a, 0, 5) cerr << u[a] << ' '; cerr << '\n'; */
      /* cerr << '\n'; */
    }
    rep(a, 0, 5) if(u[a] == 0) break;
    ANS.pb((char)(a+'A'));
    cout << ANS << endl;
    cin >> C;
    if( C != 'Y'){
      cerr << X << ' ' << Y << ' ' << M;;
      return 0;
    }
  }



	return 0;
}

