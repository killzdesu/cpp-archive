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
int last[1010];
ll dp[1010];
ll dp2[1010];
pii E[1000010];
pii path[1000010];
vector<int> v[1010];

void update(int x, int y){
    for(;x<y;x++){
        dp[path[E[x].se].fi] = max(dp[path[E[x].se].fi], dp2[path[E[x].se].fi]);
        dp[path[E[x].se].se] = max(dp[path[E[x].se].se], dp2[path[E[x].se].se]);
    }
}

int main(){
int a, b, c, d, j;
cin >> N >> M;
REP(a, M){
    scanf("%d %d %d", &c, &d, &b);
    E[a] = mp(b, a);
    path[a] = mp(c, d);
}
sort(E, E+M);
int DPC, DPD, DPD2, DPC2;
k = -1;
j = 0;
REP(i, M){
    c = path[E[i].se].fi;
    d = path[E[i].se].se;
//    printf("%d-%d :: %d\n", c, d, E[i].fi);
//    DPC=dp[c]; DPD=dp[d];
//    DPC2=dp2[c]; DPD2=dp2[d];
    if(E[i].fi != k){
        update(j, i);
        j = i;
        k = E[i].fi;
    }
    dp2[c] = max(dp[c], dp[d]+(ll)E[i].fi);
    dp2[d] = max(dp[d], dp[c]+(ll)E[i].fi);
//    REPI(a, N){
//        printf("%d ", max(dp[a], dp2[a]));
//    }printf("\n");
}
update(0, M);
ll mx = -2e9;
REPI(a, N){
    mx = max(mx, dp[a]);
}
cout << mx;
return 0;
}
