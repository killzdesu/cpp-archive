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
string S[1005];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int TT, T;
  cin >> TT;
  rep(T, 1, TT+1){
    vector<int> o = {0, 1, 2, 3, 4, 5};
    cin >> N;
    rep(a, 0, N){
      cin >> S[a];
      reverse(all(S[a]));
    }
    sort(S, S+N);
    /* rep(a, 0, N){ */
    /*   cout << S[a] <<'\n'; */
    /* } */
    int cnt = 0, mx=0;;
    string t[10];
    do {
      cnt = 0;
      for(a=1;a<=N;a+=2){
        c = 0;
        t[a] = "";
        for(b=0;b<min(S[o[a]].length(), S[o[a-1]].length());b++){
          if(S[o[a]][b] != S[o[a-1]][b]) break;
          t[a].pb(S[o[a]][b]);
        }
        c = 1;
        while(c){
          c = 0;
          if(t[a].length()==0) break;
          for(b=0;b<a;b++){
            if(t[a].length()>0 and t[b]==t[a]){
              c = 1;
              t[a].pop_back();
            }
          }
        }
        if(t[a].length()>0) cnt++;
      }
      mx = max(mx, cnt);
    }while(next_permutation(all(o)));
    cout << "Case #"<<T<<": "<<mx*2;
    cout << '\n';
  }



	return 0;
}
