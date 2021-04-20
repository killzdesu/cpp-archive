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


int i, N, M, H;
int F[110], L[110], T[110][110];
int A[110][110];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
  cin >> N >> M >> H;
  rep(a, 0, M) cin >> F[a];
  rep(a, 0, N) cin >> L[a];
  rep(a, 0, N) rep(b, 0, M){
    cin >> T[a][b];
    if(T[a][b] == 0) continue;
    A[a][b] = min(F[b], L[a]);
  }
  rep(a, 0, N){
    rep(b, 0, M) cout << A[a][b] << ' ';
    cout << '\n';
  }



	return 0;
}
