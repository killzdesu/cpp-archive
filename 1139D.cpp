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
vector<int> pr;
int lp[100010];

void genP(int N){
  pr.pb(2);
  for(int i=3;i<=N;i+=2){
    if(!lp[i]){
      lp[i] = i;
      pr.pb(i);
      /* continue; */
    }
    for(auto x: pr){
      if(x>lp[i] or x*i > N) break;
      lp[i*x] = x;
    }
  }
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N;
  genP(N);

	return 0;
}
