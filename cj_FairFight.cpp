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

int sc[100010][20], sd[100010][20];
int lg[100010];
int C[100010], D[100010];
int i, N, M;

void init(){
  int a, i;
  lg[1] = 0;
  rep(i, 2, 100005)
    lg[i] = lg[i/2] + 1;

  rep(a, 0, N){
    sc[a][0] = C[a];
    sd[a][0] = D[a];
  }
  rep(a, 0, 100008) rep(i, 1, 20) sc[a][i] = sd[a][i] = 0;

  rep(i, 1, 20){
    for(a=0;a+(1<<i) <= 100005; a++){
      sc[a][i] = max(sc[a][i-1], sc[a+(1<<(i-1))][i-1]);
      sd[a][i] = max(sd[a][i-1], sd[a+(1<<(i-1))][i-1]);
    }
  }
  
}


int chk(int L, int R){
  int j = lg[R - L + 1];
  int mc = max(sc[L][j], sc[R- (1 << j) + 1][j]);
  int md = max(sd[L][j], sd[R- (1 << j) + 1][j]);
  if(mc > md) swap(mc, md);
  /* dump(mc); dump(md); */
  return (md-mc <= M);
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T, TT;
  cin >> TT;
  rep(T, 1, TT+1){
    ll ans = 0;
    cin >> N >> M;
    rep(a, 0, N) cin >> C[a];
    rep(a, 0, N) cin >> D[a];
    init();
    ll r = 0;
    rep(a, 0, N) rep(b, a, N){
      if(chk(a, b)) r++;
    }
    /* rep(a, 0, N){ */
    /*   int lo = a, hi = N-1, mi; */
    /*   ans = 0; */
    /*   while(lo < hi){ */
    /*     mi = (lo+hi+1)/2; */
    /*     if(chk(a, mi)) hi = mi-1; */
    /*     else lo = mi; */
    /*   } */
    /*   dump(lo); */
    /*   if(chk(a, lo)) ans += (N-lo); */
    /*   else if(lo != N-1){ */
    /*     lo++; */
    /*     if(chk(a, lo)) ans += (N-lo); */
    /*   } */
    /*   dump(ans); */
    /*   r += ans; */
    /* } */
    cout << "Case #"<<T<<": "<<r<<"\n";
  }


	return 0;
}
