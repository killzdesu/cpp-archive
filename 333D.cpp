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

int s[1010][1010];
int dp[1010][1010];

int main(){
int a, b, c, d;
cin >> N >> M;
int mn = -2e9;
REP(a, N) REP(b, M){
    scanf("%d", &s[a][b]);
}
REP(b, M) REP(a, N){
    dp[a][b] = s[a][b];
    if(a)dp[a][b] = min(dp[a][b], dp[a-1][b]);
}
for(a=1;a<N;a++) for(b=1;b<M;b++){
    dp[a][b] = max(dp[a][b], dp[a-1][b]);
    mn = max(dp[a][b], mn);
}
cout << mn;

return 0;
}
