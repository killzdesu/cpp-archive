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

int i, n, k, N, M, K;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
int m[30][30];
int dis[30][30][30];
bool warp[30][30];
pii wap[30][30];

struct node{
    int dis, x, y, z;
    node() {}
    node(int dis, int x, int y, int z): dis(dis), x(x), y(y), z(z) {}
    bool operator < (const node& b) const{
        return dis > b.dis;
    }
};

priority_queue<node> Q;

int main(){
int a, b, c, d;
cin >> N >> M >> K;
REP(a, N)REP(b, N){
    scanf("%d", &m[a][b]);
}
REP(a, 21) REP(b, 21) REP(c, 21) dis[a][b][c] = 2e9;
dis[0][0][0] = 0;
REP(a, M){
    scanf("%d %d %d %d", &c, &d, &i, &k);
    warp[c][d] = 1;
    wap[c][d] = mp(i, k);
}
Q.push(node(0, 0, 0, 0));
node T;
int x2, y2;
while(!Q.empty()){
    T = Q.top();
    Q.pop();
    if(T.dis > dis[T.x][T.y][T.z]) continue;
    if(T.z > K) continue;
//    printf("%d %d %d: %d\n", T.x, T.y, T.z, dis[T.x][T.y][T.z]);
    REP(a, 4){
        x2 = T.x+dx[a];
        y2 = T.y+dy[a];
        if(x2 < 0 or y2 < 0 or x2 >= N or y2 >= N) continue;
        if(dis[x2][y2][T.z] > dis[T.x][T.y][T.z] + m[x2][y2]){
            dis[x2][y2][T.z] = dis[T.x][T.y][T.z] + m[x2][y2];
            Q.push(node(dis[x2][y2][T.z], x2, y2, T.z));
        }
    }
    if(warp[T.x][T.y]){
        x2 = wap[T.x][T.y].fi;
        y2 = wap[T.x][T.y].se;
        if(dis[x2][y2][T.z+1] > dis[T.x][T.y][T.z]){
            dis[x2][y2][T.z+1] = dis[T.x][T.y][T.z];
            Q.push(node(dis[x2][y2][T.z+1], x2, y2, T.z+1));
        }
    }
}
k = 2e9;
for(a=0;a<=K;a++){
    k = min(k, dis[N-1][N-1][a]);
}
cout << k;
return 0;
}
