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

int i, n, k, N, M, K, S, L;
ll dis[10010][60];

struct node{
    int x, y;
    ll dis;
    node() {}
    node(ll dis, int x, int y): dis(dis), x(x), y(y){}
    bool operator < (const node& b) const{
        return dis > b.dis;
    }
};

vector<pii> v[10010], s[10010];
priority_queue<node> Q;

int main(){
int a, b, c, d;
cin >> N >> M >> S >> L;
REP(a, M){
    scanf("%d %d %d", &c, &d, &b);
    v[c].pb(mp(d, b));
}
REP(a, S){
    scanf("%d %d %d", &c, &d, &b);
    s[c].pb(mp(d, b));
}
REP(a, 10005)REP(b, 55) dis[a][b] = 2e14;
dis[1][0] = 0;
Q.push(node(0, 1, 0));
node T;
while(!Q.empty()){
    T = Q.top();
    Q.pop();
    if(T.dis > dis[T.x][T.y]) continue;
    if(T.y > L) continue;
    REP(a, v[T.x].size()){
        if(dis[v[T.x][a].fi][T.y] > T.dis + v[T.x][a].se){
            dis[v[T.x][a].fi][T.y] = T.dis + v[T.x][a].se;
            Q.push(node(dis[v[T.x][a].fi][T.y], v[T.x][a].fi, T.y));
        }
    }
    REP(a, s[T.x].size()){
        if(dis[s[T.x][a].fi][T.y+1] > T.dis + s[T.x][a].se){
            dis[s[T.x][a].fi][T.y+1] = T.dis + s[T.x][a].se;
            Q.push(node(dis[s[T.x][a].fi][T.y+1], s[T.x][a].fi, T.y+1));
        }
    }
}
ll k = 2e14;
for(a=0;a<=L;a++){
    k = min(dis[N][a], k);
}
cout << k;

return 0;
}
