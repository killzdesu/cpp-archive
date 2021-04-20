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

const int MX = 1048576;

unordered_map<int, vector<int> > m[21];
vector<int, int> e[100010];
int i, N, M;

void reset(){
  rep(i, 1, 21){
    m[i].clear();
    m[i].reserve(1<<(i-1));
    m[i].max_load_factor(0.25);
  }
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> T;
  while(T--){
    reset();
    cin >> N >> M;

  }



	return 0;
}
