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
/* int s[30][100010]; */
vector<int> ch[30];
string s;

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T, TT;
  cin >> TT;
  rep(T, 1, TT+1){
    cin >> N >> M;
    cin >> s;
    rep(a, 0, 26) ch[a].clear();
    rep(a, 0, N){
      ch[s[a]-'A'].pb(a+1);
    }
    i = 0;
    while(M--){
      cin >> c >> d;
      b = 0;
      rep(a, 0, 26){
        if(distance(lower_bound(all(ch[a]), c), upper_bound(all(ch[a]), d))%2==1){
          if(b==1){
            b = -1;
            break;
          }
          b = 1;
        }
      }
      if(b == 0 or b == 1) i++;
    }
    cout<<"Case #"<<T<<": "<<i<<'\n';
  }



	return 0;
}
