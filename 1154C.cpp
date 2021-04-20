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
int A, B, C;
vector<int> T = {0, 1, 2, 0, 2, 1, 0};

int test(ll d, int st){
  int i;
  int p;
  int a, b, c;
  int s[4] = {0,0,0,0};
  a = d/7;
  rep(i, 0, 7){
    p = (i+st)%7;
    s[T[p]] += a+(d%7>=i+1?1:0);
  }
  /* printf("st: %d :%d %d %d\n", st, s[0], s[1], s[2]); */
  return (s[0]<=A and s[1]<=B and s[2]<=C);
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> A >> B >> C;
  ll lo = 0, hi = A+B+C;
  ll mi;
  while(lo < hi){
    mi = (lo+hi+1)/2;
    c = 0;
    rep(a, 0, 7) c |= test(mi, a);
    if(c) lo = mi;
    else hi = mi-1;
  }

  cout << lo;

	return 0;
}
