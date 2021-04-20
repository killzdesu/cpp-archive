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
char s[300010];
deque<char> q;
deque<int> p;

void end(){
  cout << ":(";
  exit(0);
}

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b; 
	int T;
  char ans[300010];
  cin >> N;
  cin >> s;
  if(N %2 == 1) end();
  if(s[0] == ')' or s[N-1]=='('){
    end();
  }
  ans[0] = '(';
  ans[N-1] = ')'; ans[N] = '\0';
  rep(a, 1, N-1){
    if(s[a] == '('){
      q.pb(s[a]);
      p.pb(a);
    }
    if(s[a] == '?'){
      q.pb(s[a]);
      p.pb(a);
    }
    if(s[a] == ')'){
      if(q.empty()) end();
      q.pop_back();
      b = p.back(); p.pop_back();
      ans[b] = '(';
      ans[a] = ')';
    }
  }
  if(len(q) %2 ==1) end();
  char c, d;
  deque<pair<char, int> > S;
  /* dump_all(q); */
  while(!q.empty()){
    c = q.back();
    d = p.back();
    q.pop_back(); p.pop_back();
    if(c == '?') S.pb({c, d});
    if(c == '(') {
      if(S.empty()) end();
      auto t = S.back(); S.pop_back();
      ans[d] = '(';
      ans[t.se] = ')';
    }
  }
  /* for(auto x:S) cout << x.se << ' '; */
  /* cout << '\n'; */
  for(a=0;a<len(S)/2;a++){
    ans[S[a].se] = ')';
  }
  for(;a<len(S);a++) ans[S[a].se] = '(';
  cout << ans;

	return 0;
}
