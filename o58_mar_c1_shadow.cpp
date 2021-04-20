#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long

using namespace std;

int i, n, k, N, M, K;
int C[3010], D[3010], tmp;
int dp[2000];

int qryC(int x, int y){
    if(y < x) return 0;
    tmp = C[y];
    if(x) tmp-=C[x-1];
    return tmp;
}

int qryD(int x, int y){
    if(y < x) return 0;
    tmp = D[y];
    if(x) tmp-=D[x-1];
    return tmp;
}

vector<pii> p;

int main(){
int a, b, c, d;
cin >> N >> M;
REP(a, N){
    scanf("%d", &C[a]);
    if(a) C[a] += C[a-1];
}
REP(a, N){
    scanf("%d", &D[a]);
    if(a) D[a] += D[a-1];
}
REP(a, M){
    scanf("%d %d", &c, &d);
    p.pb(mp(c, d));
}
p.pb(mp(0, 0));
p.pb(mp(N-1, N-1));

sort(p.begin(), p.end());
p.resize(distance(p.begin(), unique(p.begin(), p.end())));
REP(a, p.size())dp[a] = 2e9;
dp[0] = 0;
int dist, sh;
for(a=1;a<p.size();a++){
    k = 2e9;
    for(b=0;b<a;b++){
        sh = N-p[a].fi-1;
        dist = qryC(p[b].se+1, min(sh-1, p[a].se));
        dist += qryD(max(p[b].se+1, sh), p[a].se);
        k = min(k, dist+dp[b]);
    }
    dp[a] = k;
//    printf("dp[%d] = %d\n", a, k);
}
cout << dp[p.size()-1];

return 0;
}
