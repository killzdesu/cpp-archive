#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
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
int cnt[1000], vs[1000];
int dp[40][40][40][40], u[40][40][40][40];
int m[40][40];

int run(int x, int y, int x2, int y2){
    if(u[x][y][x2][y2]) return dp[x][y][x2][y2];
    if(x == x2 or y == y2){
        i++;
        int a, b, c=0;
        REP(a, K+10) vs[a] = 0;
        for(a=x;a<=x2;a++) for(b=y;b<=y2;b++){
//            if(vs[m[a][b]] != i){
//                c++;
//                vs[m[a][b]] = i;
//            }
            vs[m[a][b]]++;
        }
        REPI(a, K){
            if(vs[a] == cnt[a]) c++;
//            if(x == 0 and y == 0 and x2 == 1 and y2==3)printf("%d:%d-%d ", a, vs[a], cnt[a]);
        }//printf("\n");
        dp[x][y][x2][y2] = c;
        u[x][y][x2][y2] = 1;
        return dp[x][y][x2][y2];
    }
    int a;
    dp[x][y][x2][y2] = 0;
    for(a=x;a<x2;a++){
        dp[x][y][x2][y2] = max(dp[x][y][x2][y2], run(x, y, a, y2)+run(a+1, y, x2, y2));
    }
    for(a=y;a<y2;a++){
        dp[x][y][x2][y2] = max(dp[x][y][x2][y2], run(x, y, x2, a)+run(x, a+1, x2, y2));
    }
    u[x][y][x2][y2] = 1;
    return dp[x][y][x2][y2];
}

int main(){
int a, b, c, d;
cin >> N >> M >> K;
REP(a, N)REP(b, M){
    scanf("%d", &m[a][b]);
    cnt[m[a][b]]++;
}
cout << run(0, 0, N-1, M-1);


return 0;
}
