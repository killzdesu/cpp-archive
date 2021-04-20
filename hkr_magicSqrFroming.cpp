#include "bits/stdc++.h"
#define rep(i, x,y) for(i=(int)x;i<(int)y;i++)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define pb push_back
#define dump(x) cout <<(#x) << " = " << x << "\n";
#define dump_all(x) cout<<(#x)<<":\n";for(auto t:x)cout<<t<<" ";cout<<"\n";

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
int dp[11][1030];
int abs(int o){ return (o)>0?(o):-o;};

int formingMagicSquare(vector<vector<int>> s) {
  vector<int> v;
  int i, j, k;
  v.pb(0);
  rep(i, 0, 3) rep(j,0,3) v.pb(s[i][j]);
  /* dump_all(v); */
  rep(i, 0, 10) fill(dp[i], dp[i]+1024, INF);
  dp[0][0] = 0;
  rep(i, 1, 10){
    rep(j, 1, 10){
      rep(k, 0, 1024){
        if((k&(1<<(j-1)))) continue; 
        if(__builtin_popcount(k)!=i-1) continue;
        dp[i][k|(1<<(j-1))] = min(dp[i][k|(1<<(j-1))], dp[i-1][k]+abs(v[i]-j));
      }
    }
  }

  rep(i, 1, 10){
    int mn = INF;
    rep(j, 0, 512) mn = min(mn, dp[i][j]);
    cout << i << ' ' << mn << "\n";
    rep(j, 0, 512) if(mn == dp[i][j]) 
      cout << bitset<9>(j) << ' ' << j << '\n';
  }
  /* cout << dp[9][511] << "\n"; */
  return dp[9][511]; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
