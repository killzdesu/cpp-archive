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

vector<int> pr(){
  const int MAXN = 1'000'000;
  int lp[MAXN+1];
  vector<int> pr;

  for (int i=2; i<=N; ++i) {
      if (lp[i] == 0) {
          lp[i] = i;
          pr.push_back (i);
      }
      for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
          lp[i * pr[j]] = pr[j];
  }
  return pr;
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;




	return 0;
}
