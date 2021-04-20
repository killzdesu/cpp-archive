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

bool isMagic(int *s){
  int i, j;
  rep(i, 0, 3) if(s[i]+s[3+i]+s[6+i] != 15) return false;
  rep(i, 0, 3) if(s[3*i]+s[1+3*i]+s[2+3*i] != 15) return false;
  if(s[0]+s[4]+s[8]!=15 or s[2]+s[4]+s[6]!=15) return false;
  return true;
}

int formingMagicSquare(vector<vector<int>> s) {
  int S[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  vector<int> v;
  int i, j, k;
  rep(i, 0, 3) rep(j,0,3) v.pb(s[i][j]);
  int mn = INF;
  do{
    if(!isMagic(S)) continue;
    k = 0;
    rep(i, 0, 9) k += abs(v[i]-S[i]);
    mn = min(mn, k);
  }while(next_permutation(S, S+9));
  dump(mn);
  return mn;
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
