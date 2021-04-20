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
int cnt[1000];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> T;
  while(T--){
    cin >> N;
    rep(a, 0, 500) cnt[a] = 0;
    rep(a, 0, N){
      string s;
      cin >> s;
      for(auto x: s){
        cnt[x]++;
      }
    }
    int M = 1000;
    M = min(M, cnt['c']/2);
    M = min(M, cnt['e']/2);
    M = min(M, cnt['o']);
    M = min(M, cnt['d']);
    M = min(M, cnt['h']);
    M = min(M, cnt['f']);
    cout << M << '\n';
  }



	return 0;
}
