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

struct qe{
    int x1, y1;
    int x2, y2;
    int turn;
    qe(){};
    qe(int a, int b, int c, int d, int t){
        x1 = a; y1 = b; x2 = c; y2 = d; turn = t;
    }
};

int i, n, k, N, M, K;
int dp[35][35][35][35];
int dist[35][35][35][35];
char m[40][40];
int t[40][40];

queue<pii> Q1;

int d1[4]={1, -1, 0, 0}, d2[4]={0, 0, 1, -1};
int dx1[4]={1, -1, 0, 0}, dy1[4]={0, 0, 1, -1};
int dx2[4]={-1, 1, 0, 0}, dy2[4]={0, 0, -1, 1};

void bfs(int X, int Y){
    int a, x, y;
    while(!Q1.empty()){
        x = Q1.front().fi;
        y = Q1.front().se;
        Q1.pop();
//        if(dist[X][Y][x][y]!=2e8) continue;
        REP(a, 4){
            if(x+d1[a] < 0 or x+d1[a]>=N or y+d2[a]<0 or y+d2[a]>=M) continue;
            if(m[x+d1[a]][y+d2[a]] == '#') continue;
            if(dist[X][Y][x+d1[a]][y+d2[a]] != 2e8) continue;
            if(dist[X][Y][x+d1[a]][y+d2[a]] < dist[X][Y][x][y]+1) continue;
            dist[X][Y][x+d1[a]][y+d2[a]] = dist[X][Y][x][y]+1;
            Q1.push(mp(x+d1[a], y+d2[a]));
        }
    }
}

queue<qe> Q;

int main(){
int a, b, c, d;
cin >> M >> N;
REP(a, N) scanf("%s", m[a]);
REP(a, N) REP(b, M){
    REP(c, N) REP(d, M) dist[a][b][c][d] = 2e8;
    dist[a][b][a][b] = 0;
    Q1.push(mp(a, b));
    bfs(a, b);
//    REP(c, N) REP(d, M) dist[a][b][c][d] = t[c][d];
}
int x1, y1, x2, y2;
REP(a, N) REP(b, M){
    if(m[a][b] == 'A'){x1 = a; y1 = b;}
    if(m[a][b] == 'B'){x2 = a; y2 = b;}
    REP(c, N) REP(d, M) dp[a][b][c][d] = 2e8;
}
Q.push(qe(x1, y1, x2, y2, 0));
qe T;
while(!Q.empty()){
    T = Q.front();
    Q.pop();
    if(dp[T.x1][T.y1][T.x2][T.y2] <= T.turn) continue;
//    printf("(%d, %d)  (%d, %d)\n", T.x1, T.y1, T.x2, T.y2);
    dp[T.x1][T.y1][T.x2][T.y2] = T.turn;
    REP(a, 4){
        x1 = T.x1+dx1[a];
        y1 = T.y1+dy1[a];
        x2 = T.x2+dx2[a];
        y2 = T.y2+dy2[a];
        if(x1 < 0 or y1 < 0 or x1 >= N or y1 >= M or m[x1][y1]=='#'){x1 = T.x1; y1 = T.y1;}
        if(x2 < 0 or y2 < 0 or x2 >= N or y2 >= M or m[x2][y2]=='#'){x2 = T.x2; y2 = T.y2;}
        Q.push(qe(x1, y1, x2, y2, T.turn+1));
    }
}
int mn = 2e8, TT=2e8;

REP(a, N) REP(b, M) REP(c, N) REP(d, M){
    if(dp[a][b][c][d] != 2e8){
        if(mn > dist[a][b][c][d]){
            mn = dist[a][b][c][d];
            TT = dp[a][b][c][d];
        }
        else if(mn == dist[a][b][c][d]){
            TT = min(TT, dp[a][b][c][d]);
        }
    }
}

if(mn < 2e8){
    printf("%d %d", mn, TT);
}
else printf("-1 0");
//cout << dp[0][0][2][3];

return 0;
}
