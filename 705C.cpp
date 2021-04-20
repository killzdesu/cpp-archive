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
queue<int> s[300010];


int main(){
	int a, b, c, d;
	int T,t;
  cin >> N >> T;
  int all = 0, cnt=0;
  int mx_t=0;
  set<int> done;
  REPI(t, T){
    scanf("%d %d", &c, &d);
    if(c==1){
      cnt++;
      s[d].push(cnt);
      all++;
    }
    else if(c==2){
      while(!s[d].empty()){
        if(mx_t < s[d].front()){
          all--;
        }
        done.insert(s[d].front());
        s[d].pop();
      }
    }
    else if(c==3){
      d = min(d, cnt);
      if(d > mx_t){
        auto it = done.upper_bound(d);
        int r = d-mx_t-(distance(done.upper_bound(mx_t), it));
        all -= min(all, r);
        mx_t = max(mx_t, d);
      }
    }
    printf("%d\n", all);
  }



	return 0;
}
