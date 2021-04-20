#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(x,y) for(x=0;x<(int)y;x++)
#define REPI(x,y) for(x=1;x<=(int)y;x++)
#define pii pair<int,int>
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define len(x) (x).size()

using namespace std;

int i, N, M, K, k;
char s[100010];
int z[100010];

int main(){
	int a, b, c, d;
	int T;
  cin >> N;
  scanf("%s", s);
  REP(a, N) z[a] = s[a]-'0';
  ll cnt = 0;
  ll ev = 1, od = 0;
  REP(a, N){
    if(z[a]%2 == 0) cnt += a+1;
  }

  cout << cnt;

	return 0;
}
