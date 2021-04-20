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
vector<int> v[400];
int s[400];
int D[400], root[400];
int dp[310][310][310];
int mx[310][310];

void dfs(int x, int y){
    int a;
    D[x] = y;
    jui:;
    REP(a, v[x].size()){
        if(v[x][a] == root[x]){
            v[x].erase(v[x].begin() + a);
            goto jui;
            continue;
        }
        root[v[x][a]] = x;
        dfs(v[x][a], y+1);
    }
}

void rec(int x){
    int i, a, b, c, ch;
    REP(i, v[x].size()){
        ch = v[x][i];
        if(v[x][i] == root[x]) continue;
        root[ch] = x;
        rec(ch);
    }
//    printf("--------------------%d\n", x);
    REP(i, v[x].size()){
        REP(a, K){
            REP(b, K-a){
                c = mx[v[x][i]][b];
                if(i) c += dp[x][i-1][a];
                dp[x][i][a+b] = max(dp[x][i][a+b], c);
//                printf("dp[%d] + [%d] = %d\n", a, b, c);
            }
        }
    }
    REPI(a, K){
        if(a)mx[x][a] = dp[x][v[x].size()-1][a-1]+s[x];
//        printf("mx[%d] = %d\n", a, mx[x][a]);
    }
}

int path(int x, int y){
    if(D[x] > D[y]) swap(x, y);
    int sm = 0, cnt=0;
    while(D[y] != D[x]){
        sm += s[y];
        y = root[y];
        cnt++;
    }
    if(x == y){
        cnt++;
        if(cnt > K) return -1;
        return sm+s[x];
    }
    while(x != y){
        sm += s[x]+s[y];
        x = root[x];
        y = root[y];
        cnt+=2;
    }
    cnt++;
    sm += s[x];
    if(cnt > K) sm = -1;
    return sm;
}

pii p[100010];

int main(){
int a, b, c, d;
cin >> N >> K;
REPI(a, N){
    cin >> s[a];
    root[a] = -1;
    p[a].fi = s[a];
    p[a].se = a;
}
REP(a, N-1){
    scanf("%d %d", &c, &d);
    v[c].pb(d);
    v[d].pb(c);
}
dfs(1, 0);
rec(1);

//REPI(a, N){
//    printf("%d: %d\n", a, mx[a][K]);
//}

REPI(a, N) k = max(k, mx[a][K]);

cout << k;
return 0;
}
