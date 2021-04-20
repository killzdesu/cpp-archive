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

using namespace std;

int i, N, M, K, k;
set<int> S;
int cnt[10010];

double cal(double x, double y){
  return (x/y)+(y/x);
}

int main(){
	int a, b, c, d;
  double Min = 2e9;
  int s1, s2;
	int T;
  cin >> T;
  while(T--){
    S.clear();
    REP(a, 10009) cnt[a] = 0;
    Min = 2e14;
    scanf("%d", &N);
    REP(a, N){
      scanf("%d", &c);
      cnt[c]++;
      if(cnt[c] >= 2){
        if(!S.empty()){
          auto it = S.begin();
          it = S.lower_bound(c);
          if(it == S.begin()){
            d = *it;
          }
          else if(it == S.end()){
            it--; d = *it;
          }
          else {
            auto jt = it;
            jt--;
            if( cal(*jt, c) < cal(*it, c) ) d = *jt;
            else d = *it;
          }
          if(cal((double)c, (double)d) < Min){
            s1 = c, s2 = d;
            Min = cal((double)c, (double)d);
          }
        }
        S.insert(c);
      }
      if(cnt[c] == 4 and 16 < Min){
        Min = 16;
        s1 = s2 = c;
      }
    }
    printf("%d %d %d %d\n", s1, s1, s2, s2);
  } 


	return 0;
}
