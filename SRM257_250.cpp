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

struct SubstitutionCode {
  int getValue(string key, string code){
    int i;
    int r = 0;
    for(auto x: code){
      for(i=0;i<key.length();i++){
        if(x == key[i]) break;
      }
      if(i != key.length()){
        r*=10;
        r += (i!=9?i+1:0);
      }
    }
    return r;
  }
}t;

int i, N, M;

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  string s1, s2;

  cin >> s1 >> s2;

  cout << t.getValue(s1, s2);

	return 0;
}
