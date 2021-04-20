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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define dump(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;

int i, n, k, N, M, K;

ll s[100010];
ll t[100010];
int Q[100010];

ll dp[2][100010];
ll qt[100010];

ll getv(int d, int a, int b){
    return dp[d][a]-a*t[b]+qt[a]+b*t[b]-qt[b];
}

double fx(int d, int a, int b){
    return
    ((double)dp[d][a]+qt[a]-dp[d][b]-qt[b])/
    ((double)(-b)-(-a)); // --> a-b
}

void solve(int d, int lo, int hi, int l, int r){
    if(lo == hi) return;
    int mi = lo+(hi-lo)/2;
    ll mn = 2e15;
    int i;
    for(int a=l;a<=min(r, mi-1);a++){
        if(mn > getv(d^1, a, mi)){
            mn = getv(d^1, a, mi);
            i = a;
        }
    }
    dp[d][mi] = mn;
    if(lo == hi-1) return;
    solve(d, lo, mi, l, i);
    solve(d, mi+1, hi, i, r);
}

int main(){
int a, b, c, d;
cin >> N >> M >> K;
for(a=2;a<=N;a++){
    scanf("%I64d", s+a);
    s[a] += s[a-1];
}
REPI(a, M){
    scanf("%d %d", &c, &d);
    t[a] = d-s[c];
}
sort(t+1, t+M+1);
REPI(a, M){
    qt[a] = t[a];
    qt[a] += qt[a-1];
}
int i, j;
int now = 1, prev = 0;
REP(a, M+1) dp[0][a]  = 2e15;
dp[0][0] = 0;
REP(i, K){
//    REP(a, M+1) dp[now][a] = 2e9;
    dp[now][0] = 0;
//    printf("------ %d ------\n", i+1);
    solve(now, 1, M+1, 0, M);
    swap(now, prev);
}
ll sum = dp[prev][M];
cout << sum;
return 0;
}
