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

struct BridgePts{
  int Val(int x){
    x %= 13;
    if(x == 1) return 4;
    if(x == 13) return 3;
    if(x == 12) return 2;
    if(x == 11) return 1;
    return 0;
  };
  int pointValue(vector <int> hand){
    int sum = 0;
    vector<int> a = {0,0,0,0};
    int i;
    rep(i, 0, 13){
      sum += Val(hand[i]);
      a[hand[i]/13]++;
    }
    rep(i, 0, 4){
      if(a[i] == 2) sum += 1;
      if(a[i] == 1) sum += 2;
      if(a[i] == 0) sum += 3;
    }
    return sum;
  }
};

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;



	return 0;
}
