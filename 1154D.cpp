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
int A, B;
int s[200010];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N >> B >> A;
  int MA = A;
  rep(a, 0, N) cin >> s[a];
  rep(a, 0, N){
    if(s[a] == 0){
      if(A == 0){
        if(B == 0) break;
        B--;
      }
      else A--;
    }
    else {
      if(B != 0){
        if(A!=MA){
          B--;
          A++;
        }
        else {
          if(A!=0) A--;
          else B--;
        }
      }
      else {
        if(A==0) break;
        A--;
      }
    }
  }

  cout << a;

	return 0;
}
