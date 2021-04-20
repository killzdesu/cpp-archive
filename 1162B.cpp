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
int A[60][60], B[60][60];

void end(){
  cout << "Impossible";
  exit(0);
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N >> M;
  rep(a, 0, N) rep(b, 0, M) cin >> A[a][b];
  rep(a, 0, N) rep(b, 0, M) cin >> B[a][b];

  rep(a, 0, N) rep(b, 0, M) if(A[a][b] > B[a][b]) swap(A[a][b], B[a][b]);
  rep(a, 0, N) rep(b, 0, M){
    if(a) if(A[a][b] <= A[a-1][b]) end();
    if(b) if(A[a][b] <= A[a][b-1]) end();
    if(a) if(B[a][b] <= B[a-1][b]) end();
    if(b) if(B[a][b] <= B[a][b-1]) end();
  }
  cout << "Possible";

	return 0;
}
