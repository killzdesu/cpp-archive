#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin(), unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define dump(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;

int i, n, k, N, M, K;
int R, G;

int dp[2][1000010];
int can[1000];

int main(){
int a, b, c, d;
int now=0, next=1;
cin >> R >> G;
can[0] = 1;
dp[0][0] = 1;
for(i=0;;i++){
    if(!can[i]) break;
    REP(a, R+1) dp[next][a] = 0;
    c = i*(i+1)/2;

    for(a=0;a<=c;a++){
        if(dp[now][a] == 0) continue;
        if(a + i + 1 <= R){
            can[i+1] = 1;
            dp[next][a+i+1] += dp[now][a];
            dp[next][a+i+1] %= (int)(1e9+7);
        }
        if(c - a + i + 1 <= G){
            can[i+1] = 1;
            dp[next][a] += dp[now][a];
            dp[next][a] %= (int)(1e9+7);
        }
    }
    swap(now, next);
//    dump(i);
}
ll sm = 0;
i--;
dump(i);
REP(a, R+1){
    sm += dp[next][a];
}
cout << sm % 1000000007;

return 0;
}
