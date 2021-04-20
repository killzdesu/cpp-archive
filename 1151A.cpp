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
string S;
string G = "ACTG";

int cm(int x){
  int cnt = 0;
  for(int a=x;a<x+4;a++){
    if(S[a] >= G[a-x]){
      cnt += min(S[a]-G[a-x], G[a-x]-S[a]+26);
    }
    else {
      cnt += min(G[a-x]-S[a], S[a]-G[a-x]+26);
    }
  }
  return cnt;
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N;
  cin >> S;
  int mn = 2e9;
  rep(a, 0, S.size()-3){
    mn = min(mn, cm(a));
  }
  cout << mn;


	return 0;
}
