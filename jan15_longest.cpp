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
int dp[19][1<<20], dist[21][21];
int vs[1<<20];

queue<int> Q;

int main(){
int a, b, c, d;
int mx;
cin >> N;
mx = 1 << (N-2);
REP(a, N){
    REP(b, N){
        scanf("%d", &dist[a][b]);
    }
}
for(a=0;a<N-2;a++){
    dp[a][1<<a] = dist[0][a+1];
    Q.push(1<<a);
}
int r;
while(!Q.empty()){
    c = Q.front();
    Q.pop();
//    printf(">> in %d\n", c);
    for(b=0;b<N-2;b++){
        d = (1<<b);
        if(c&d == 0) continue;
        for(a=0;a<N-2;a++){
            d = (1<<a);
            if(c&d) continue;
            dp[a][c|d] = max(dp[a][c|d], dp[b][c]+dist[b+1][a+1]);
//            printf("%d-%d [%d] :: %d\n", b+1, a+1, c|d, dp[a][c|d]);
            if(vs[c|d]==0)Q.push(c|d);
            vs[c|d] = 1;

        }
    }
}

//for(a=0;a<N-2;a++){
//    printf("%d %d\n", dp[a][(1<<(N-2))-1]);
//}

int ans = -2e9;
for(a=1;a<N-1;a++){
    ans = max(ans, dp[a-1][(1<<(N-2))-1]+dist[a][N-1]);
}
cout << ans;

return 0;
}
