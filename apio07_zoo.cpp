#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<bitset>
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
int dp[10010][33], A[50010], Lm[50010], Hm[50010];
vector<int> L[50010], H[50010], kid[10010];

int mark(int i, int mask){
    int a, b, c, cnt=0, kidd;
    REP(a, kid[i].size()){
        kidd = kid[i][a];
        if((Lm[kidd]&mask) or (Hm[kidd]&(31-mask))) cnt++;
    }
    return cnt;
}

int main(){
int a, b, c, d;
cin >> N >> M;
REPI(a, M){
    scanf("%d %d %d", &A[a], &c, &d);
    kid[A[a]].pb(a);
    REP(b, c){
        scanf("%d", &i);
        if(i < A[a]) i+=N;
        H[a].pb(i);
        Hm[a]|=(1<<(i-A[a]));
    }
    REP(b, d){
        scanf("%d", &i);
        if(i < A[a]) i+=N;
        L[a].pb(i);
        Lm[a]|=(1<<(i-A[a]));
    }
}

k = 0;
for(int F=0;F<32;F++){
    for(a=0;a<32;a++)REPI(b, N) dp[b][a] = -2e9;
    dp[1][F] = mark(1, F);
    for(a=2;a<=N;a++){
        for(b=0;b<32;b++){
            dp[a][b] = max(dp[a-1][(b*2)%32], dp[a-1][(b*2+1)%32]);
            dp[a][b] += mark(a, b);
        }
    }
    for(a=0;a<32;a++){
        if(F%16 == a/2) k = max(k, dp[N][a]);
    }
}
cout << k;
return 0;
}
