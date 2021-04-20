#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin, unique(ALL(x))));}
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

int s[1000];
int dp[101][101];
int chk[101][101];
int qs[1000];

int Q(int a, int b){
    return (qs[b]-(a?qs[a-1]:0))%100;
}

int solve(int lo, int hi){
    int a, b, c;
    if(chk[lo][hi]) return dp[lo][hi];
    chk[lo][hi] = 1;
    for(a=lo;a<hi;a++){
        c = solve(lo, a)+solve(a+1, hi)+Q(lo, a)*Q(a+1, hi);
        dp[lo][hi] = min(dp[lo][hi], c);
    }
    return dp[lo][hi];
}

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    scanf("%d", &s[a]);
    qs[a] = s[a];
    if(a) qs[a]+=qs[a-1];
}
REP(a, N) REP(b, N) dp[a][b] = 2e9;
REP(a, N){
    dp[a][a] = 0;
    chk[a][a] = 1;
}

cout << solve(0, N-1);

return 0;
}
