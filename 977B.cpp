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
int dp[1000];
char S[102];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N;
  cin >> S;
  int mx = 0;
  rep(a, 0, N-1){
    c = (S[a]-'A')*26+(S[a+1]-'A');
    dp[c]++;
    if(dp[c]>mx) mx = dp[c], i = c;
  }
  char A, B;
  A = i/26+'A';
  B = i%26+'A';
  cout << A << B;


	return 0;
}
