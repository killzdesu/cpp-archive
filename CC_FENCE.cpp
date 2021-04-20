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

struct HASH{
    size_t operator()(const pair<int,int>&x)const{
          return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
            }
};

int i, N, M, K;
unordered_map<pii, int, HASH> m, v;
queue<pii> q;
int cnt;

bool skip(pii t){
  if(v[t]) return true;
  if(!m[t] or t.fi < 1 or t.fi > N or t.se < 1 or t.se > M){
    cnt++;
    return true;
  }
  return false;
}

int main(){
  m.reserve(65536);
  m.max_load_factor(0.25);
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> T;
  pii tp;
  while(T--){
    cin >> N >> M >> K;
    m.clear();
    v.clear();
    rep(a, 0, K){
      cin >> c >> d;
      tp = {c, d};
      m[tp] = true;
      q.push(tp);
    }
    cnt = 0;
    while(!q.empty()){
      tp = q.front(); q.pop();
      if(skip(tp)) continue;
      /* cout << ">" << tp.fi <<' '<<tp.se<<'\n'; */
      q.push(make_pair(tp.fi+1, tp.se));
      q.push(make_pair(tp.fi-1, tp.se));
      q.push(make_pair(tp.fi, tp.se+1));
      q.push(make_pair(tp.fi, tp.se-1));
      v[tp] = true;
    } 
    cout << cnt << '\n';
  }



	return 0;
}
