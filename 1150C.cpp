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
int t1, t2;
vector<int> P;
bool ck[200010];

void init(int X){
  P.pb(2);
  int a, b;
  for(a=3;a<=X;a+=2){
    if(ck[a] == 0){
      P.pb(a);
      for(b = a; b <= X; b+= a) ck[b] = 1;
    }
  }
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
  init(200001);
  /* dump_all(P); */
	int a, b, c, d;
	int T;
  cin >> N;
  rep(a, 0, N){
    cin >> c;
    if(c%2) t1++;
    else t2++;
  }
  int s = 0;
  int i = 0;
  int ans = 0;
  while(t1!=0 or t2!=0){
    if(P[i]-s >= 2){
      if(t2){
        t2--; s += 2;
        cout << "2 ";
      }
      else {
        t1--; s++;
        cout << "1 ";
      }
    }
    else {
      if(t1){
        t1--; s++;
        cout << "1 ";
      }
      else {
        t2--; s+= 2;
        cout << "2 ";
      }
    }
    if( s == P[i] ) i++, ans++;
    if( s >= P[i] ) i++;
  }

  /* cout << ans; */


	return 0;
}
