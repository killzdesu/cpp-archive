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

int main(){
  /* cin.tie(0); ios::sync_with_stdio(false); */
	int a, b, c, d;
	int T;
  int p[] = {1, 1, 1, 1, 1, 1};
  rep(a, 1, 20){
    rep(b, 0, 6){
      if(a%(b+1) == 0) p[b] *= 2;
    }
    if( a < 12 ) continue;
    /* printf("%d:", a); */
    /* rep(b, 0, 6) printf(" %d", p[b]); printf("\n"); */
  }
  int TT;
  /* return 0; */
  cin >> TT >> M;
  ll A[10];
  ll Q[10];
  rep(T, 1, TT+1){
    cout << 12 << endl;
    cin >> Q[1];
    cout << 13 << endl;
    cin >> Q[2];
    A[0] = (Q[2]-Q[1])/4096;
    cout << 14 << endl;
    cin >> Q[3];
    cout << 15 << endl;
    cin >> Q[4];
    cout << 16 << endl;
    cin >> Q[5];
    cout << 11 << endl;
    cin >> Q[6];
    A[1] = (Q[3]-Q[2]-8192*A[0])/64;
    A[3] = (Q[5]-Q[4]-32767*A[0]-128*A[1])/8;
    A[5] = (Q[3]*2-Q[5]+32768*A[0])/4;
    A[2] = (Q[1]-Q[6]-2048*A[0]-32*A[1]-4*A[3]-2*A[5])/8;
    A[4] = (Q[6]-2048*A[0]-32*A[1]-8*A[2]-4*A[3]-2*A[5])/4;
    rep(a, 0, 6) cout << A[a] << ' ';
    cout << endl;
    cin >> a;
    if(a == -1) return 0;

  }



	return 0;
}
