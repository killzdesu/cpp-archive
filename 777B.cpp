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
string s1, s2;
int A[12], B[12];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N;
  cin >> s1 >> s2;
  int mn=0, mx=0;
  rep(a, 0, N) B[s2[a]-'0']++;
  rep(a, 0, N){
    i = s1[a]-'0';
    b = i;
    while(b<10 and B[b]==0) b++;
    if(b == 10){
      b = 0;
      while(B[b]==0) b++;
    }
    B[b]--;
    if(i > b) mn++;
  }
  cout << mn << endl;
  rep(a, 0, N) B[s2[a]-'0']++;
  rep(a, 0, N){
    i = s1[a]-'0';
    b = i+1;
    while(b<10 and B[b]==0) b++;
    if(b == 10){
      b = 0;
      while(B[b]==0) b++;
    }
    B[b]--;
    if(i < b) mx++;
  }

  cout << mx;



	return 0;
}
