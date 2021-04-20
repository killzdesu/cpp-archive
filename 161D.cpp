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

int i, n, k, N, M, K, j;
vector<int> v[50010];
int root[60010];
int D[60000];
int dp[60010][600];
int ln[60010];
ll cnt, tmp;

void dfs(int x, int y){
    int a, b;
    D[x] = y;
    dp[x][0] = 1;
    REP(a, v[x].size()){
        if(v[x][a] == root[x]){
            v[x].erase(v[x].begin()+a);
            a--;
            continue;
        }
        root[v[x][a]] = x;
        dfs(v[x][a], y+1);
        REP(b, 500){
            dp[x][b+1] += dp[v[x][a]][b];
        }
    }
//    printf("------------%d += %d\n", x, dp[x][K]);
    cnt += dp[x][K];
    tmp = 0;
    REP(b, v[x].size()){
        for(a=1;a<K;a++){
                i = dp[v[x][b]][a-1];
                j = dp[x][K-a]-dp[v[x][b]][K-a-1];
                tmp += (ll)i*(ll)j;
//            printf("%d|| %d %d: %d\n", v[x][b], K-a, a, i*j);
        }
    }
    cnt += tmp/2;
}

int main(){
int a, b, c, d;
cin >> N >> K;
REP(a, N-1){
    scanf("%d %d", &c, &d);
    v[c].pb(d);
    v[d].pb(c);
}
fill_n(root, N+1, -1);
dfs(1, 0);
//for(a=1;a<K;a++){
//    cnt += ((ll)dp[a]*dp[K-a])/2;
//}
cout << cnt;
return 0;
}
