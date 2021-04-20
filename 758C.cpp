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


ll i, N, M;
ll k, x, y;

void solve1(){
  ll a, b, c;
  b = k/(N*M);
  if(k%(N*M) == 0) a = b;
  else a = b+1;
  if(k%(N*M) >= (x-1)*M+y) c = b+1;
  else c = b;

  cout << a<<' '<<b<<' '<<c;

  exit(0);
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	ll a, b, c, d;
	int T;
  cin >> N >> M >> k;
  cin >> x >> y;

  ll R = N*M;
  if(N > 2) R += (N-2)*M;
  if(N <= 2) solve1();

  b = k/R;
  ll a1, a2, a3;
  a2 = a3 = b*2;
  a1 = b;
  if(k%R != 0){
    if((k%R)>N*M) a3 += 2, a2++, a1++;
    else if((k%R)>M) a2 += 1, a1 += 1;
    else a1 += 1;
  }
  if(x == 1 or x == N) { 
    c = b;
    if(k%R >= (x-1)*M+y) c++;
  }
  else {
    c = 2*b;
    if(k%R >= (x-1)*M+y) c++;
    if(k%R > M*N){
      d = k%R-M*N;
      if(d >= (N-1-x)*M+y) c++;
    }
  }

  if(k%R>=M*N) b++;
  cout << max(a1, max(a2, a3))<<' '<<b<<' '<<c;
	return 0;
}
