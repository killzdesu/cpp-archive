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
int h[10010];
pii E[100010];

struct node{
    int dis, x, y;
    node(){}
    node(int dis, int x, int y): dis(dis), x(x), y(y){}
    bool operator < (const node& b) const{
        return dis < b.dis;
    }
}e[100010];

int find_head(int x){
    if(h[x] != x) h[x] = find_head(h[x]);
    return h[x];
}

int main(){
int a, b, c, d, Q;
cin >> N >> M >> Q;
REP(a, N) h[a] = a;
REP(a, M){
    scanf("%d %d %d", &e[a].x, &e[a].y, &e[a].dis);
}
sort(e, e+M);
//REP(a, M){
//    printf("%d\n", e[a].dis);
//}
K = N;
REP(a, M){
    if(find_head(e[a].x) != find_head(e[a].y)){
//        printf(">> %d %d\n", e[a].x, e[a].y);
        K--;
        h[find_head(e[a].x)] = find_head(e[a].y);
    }
    E[a].fi = K;
    E[a].se = e[a].dis;
}

sort(E, E+M);
//REP(a, M){
//    printf("%d %d\n", E[a].fi, E[a].se);
//}


pii *p;
REP(a, Q){
    scanf("%d", &c);
    p = lower_bound(E, E+M, mp(c, (int)-2e8));
    printf("%d\n", p->se);
}


return 0;
}
