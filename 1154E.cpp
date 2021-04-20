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


int i, N, M, k;
vector<int> v;
set<pii> s;
set<int, greater<int>> num;
int l[200010];
int t[200010];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N >> k;
  rep(a, 0, N){
    cin >> c;
    l[c] = a;
    s.insert({a, c});
    num.insert(c);
  }
  T = 1;
  while(!num.empty()){
    int p;
    while(!num.empty()){
      p = *num.begin();
      if(s.find({l[p], p}) != s.end()) break;
      num.erase(num.begin());
    }
    if(num.empty()) break;
    p = *num.begin();
    auto it = s.lower_bound({l[p], p});
    auto i = it;
    auto j = it;
    for(a=0;a<k and i!=s.end();a++) i++;
    for(a=0;a<k and j!=s.begin();a++) j--;
    if(i!=s.end())i++;
    for(it=j;it!=i;it++){
      num.erase(it->se);
      t[it->fi] = T;
    }
    s.erase(j, i);
    T = (T-1?1:2);
  }
  rep(a, 0, N) cout << t[a];

	return 0;
}
