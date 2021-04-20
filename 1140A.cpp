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
int s[10010];

int main(){
	int a, b, c, d;
	int T;
  int cnt = 0;
  cin >> N;
  int mx = 0;
  REPI(a, N){
    scanf("%d", s+a);
    mx = max(mx, s[a]);
    if(a >= mx){
      mx = 0;
      cnt++;
    }
  }
  cout << cnt;


	return 0;
}
