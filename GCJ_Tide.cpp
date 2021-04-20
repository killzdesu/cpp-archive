#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#include<queue>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long

using namespace std;

int i, n, k, N, M, K, H;
double h[120][120], f[120][120];
double dis[120][120];

struct node{
    double dis;
    int x; int y;
    bool operator < (const node& b) const {
        return dis < b.dis;
    }
}tn;

node mn(double t, int x, int y){
    tn.dis = t;
    tn.x = x;
    tn.y = y;
    return tn;
}


priority_queue<node> Q;

int av(double t, int X, int Y, int x, int y){
    double hi = max(f[X][Y], H-t*10.0);
    //printf("%d %d - %d %d : %lf < %lf\n", X, Y, x, y, hi, h[x][y]);
    if(hi+50 > h[x][y]) return -1;
    if(h[X][Y]-50 < f[x][y]) return 0;
    if(f[x][y]+50 > h[x][y]) return 0;
    return 1;
}

void dfs(int x, int y){
    if(x < 1 or x > N or y < 1 or y > N) return;
    dis[x][y] = 0;
    Q.push(mn(0, x, y));
    if(av(0, x, y, x+1, y)<=0)dfs(x+1, y);
    if(av(0, x, y, x, y+1)<=0)dfs(x, y+1);
    if(av(0, x, y, x-1, y)<=0)dfs(x-1, y);
    if(av(0, x, y, x, y-1)<=0)dfs(x, y-1);
}

int main(){
int a, b, c, d, T;
double tim;
cin >> T;
while(T--){
    cin >> H >> N >> M;
    REPI(a, N+1) REPI(b, M+1) dis[a][b] = 2e9;
    REPI(a, N)REPI(b, M){
        scanf("%lf", &h[a][b]);
    }
    REPI(a, N)REPI(b, M){
        scanf("%lf", &f[a][b]);
    }
    REPI(a, N){
        REPI(b, M){
            printf("%.2lf ", f[a][b]);
        }
        printf("\n");
    }
    dfs(1, 1);
//    REPI(a, N){
//        REPI(b, M){
//            printf("%.2lf ", dis[a][b]);
//        }
//        printf("\n");
//    }
    node tp;
    while(!Q.empty()){
        tp = Q.top();
        Q.pop();
        if(tp.dis > dis[tp.x][tp.y]) continue;
        if(dis[tp.x][tp.y] > 1 and av(tp.dis, tp.x, tp.y, tp.x-1, tp.y)){
            tim = dis[tp.x][tp.y];
            if(f[tp.x]+20 > H-dis[tp.x][tp.y]*10.0) tim += 10;
            if(av(tp.dis, tp.x, tp.y, tp.x-1, tp.y) == -1){
                if(f[tp.x][tp.y]+50 > h[tp.x-1][tp.y]){
                    s
                }
            }
            if(dis[tp.x-1][tp.y] > dis[tp.x][tp.y]){

            }
        }
    }
}


return 0;
}
