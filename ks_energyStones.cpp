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
struct stone{
  int s, e, l;
  stone(): s(s), e(e), l(l) {}
};

stone s[110];

bool cmp(stone a, stone b){
  int x = a.e+max(0, b.e-a.s*b.l);
  int y = b.e+max(0, a.e-b.s*a.l);
  return (x!=y?x>y:a.l > b.l);
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T, _T;
  cin >> _T;
  rep(T, 1, _T+1){
    cin >> N;
    rep(a, 0, N){
      cin >> s[a].s >> s[a].e >> s[a].l;
    }
    sort(s, s+N, cmp);
    int t = 0;
    ll E = 0;
    rep(a, 0, N){
      /* cout << s[a].s <<' '<<s[a].e<<' '<<s[a].l<<endl; */
      c = max(0, s[a].e-s[a].l*t);
      E += c;
      t += s[a].s;
    }
    cout << "Case #"<<T<<": "<<E<<"\n";
  }



	return 0;
}
