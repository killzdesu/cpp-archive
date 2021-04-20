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
int ck[400];
int lose[300];
string s[300];

int win(char x, char y){
  if(x == 'R'){
    if(y == 'R') return 0;
    if(y == 'S') return 1;
    if(y == 'P') return -1;
  }
  if(x == 'S'){
    if(y == 'R') return -1;
    if(y == 'S') return 0;
    if(y == 'P') return 1;
  }
  if(x == 'P'){
    if(y == 'R') return 1;
    if(y == 'S') return -1;
    if(y == 'P') return 0;
  }
  return 0;
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T, TT;
  cin >> TT;
  rep(T, 1, TT+1){
    vector<char> ans;
    cin >> N;
    rep(a, 0, N) lose[a] = 0;
    rep(a, 0, N) cin >> s[a];
    rep(i, 0, 1001){
      ck['R'] = ck['P'] = ck['S'] = 0;
      rep(a, 0, N){
        if(lose[a]) continue;
        if(s[a][i%len(s[a])] == 'S') ck['P'] = 1;
        if(s[a][i%len(s[a])] == 'P') ck['R'] = 1;
        if(s[a][i%len(s[a])] == 'R') ck['S'] = 1;
      }
      if(ck['P'] and ck['R'] and ck['S']){
        ans.clear();
        cout << "Case #"<<T<<": ";
        cout << "IMPOSSIBLE\n";
        break;
      }
      if(ck['P']+ck['R']+ck['S'] == 2){
        if(!ck['P']) ans.pb('P');
        if(!ck['R']) ans.pb('R');
        if(!ck['S']) ans.pb('S');
      }
      else {
        if(ck['P']) ans.pb('R');
        if(ck['R']) ans.pb('S');
        if(ck['S']) ans.pb('P');
      }
      c = 0;
      rep(a, 0, N) {
        if(lose[a]){
          c++;
          continue;
        }
        if(win(s[a][i%len(s[a])], ans[len(ans)-1])==-1){
          c++;
          lose[a] = 1;
        }
      }
      if(c == N) break;
    }
    if(!ans.empty()){
      cout << "Case #"<<T<<": ";
      for(auto x: ans) cout << x;
      cout << '\n';
    }


  }



	return 0;
}
