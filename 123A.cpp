#include "bits/stdc++.h"
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(x,y) for(x=0;x<(int)y;x++)
#define REPI(x,y) for(x=1;x<=(int)y;x++)
#define pii pair<int,int>
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define len(x) int((x).size())

using namespace std;

int i, N, M, K, k;
pair<int, char> p[26];
vector<int> Prime;
bool chk[1010];

void build_prime(){
  Prime.pb(2);
  for(int i=3;i<=1000;i+=2){
    if(chk[i]) continue;
    Prime.pb(i);
    for(int j=i;j<=1000;j+=i){
      chk[j] = 1;
    }
  }
}

bool v[10010];
char s[10010];

int main(){
	int a, b, c, d;
	int T;
  cin >> s;
  N = strlen(s);
  build_prime();
  REP(a, N){
    char x = s[a];
    p[x-'a'].fi++;
  }
  REP(a, 26) p[a].se = a+'a';
  sort(p, p+26, greater<pair<int, char> >());
  /* for(auto x: p) printf("%d %c\n", x.fi, x.se); */
  int cnt = 0;
  for(auto x:Prime){
    if(x*2 > N) break;
  }
  for(auto x: Prime){
    if(x*2 > N) break;
    for(a=x;a<=N;a+=x) v[a-1] = 1;
  }
  REP(a, N) if(v[a]) cnt++;
  /* REP(a, N) printf("%d ", v[a]); */
  /* printf("\n"); */
  if(p[0].fi < cnt){
    puts("NO");
    exit(0);
  }
  REP(a, N){
    if(v[a]) s[a] = p[0].se, p[0].fi--;
  }
  i = 0;
  REP(a, N){
    while(p[i].fi == 0) i++;
    if(!v[a]) s[a] = p[i].se, p[i].fi--;
  }
  puts("YES");
  cout << s;

	return 0;
}
