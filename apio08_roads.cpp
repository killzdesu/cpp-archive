#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<ctime>
#include<map>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<list>
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

struct edge{
    int x, y, w;
    edge(){}
    edge(int a, int b, int c){
        x = a; y = b; w = c;
    }
    bool operator < (const edge &b) const{
        return w < b.w;
    }
};

int del;
vector<pii> E[2];
list<pii> v[100010];
int head[20010];

int find_head(int x){
    if(head[x] != x){
        head[x] = find_head(head[x]);
    }
    return head[x];
}

vector<edge> ans;
int tmp[100010];

int main(){
int a, b, c, d;
srand(time(NULL));
cin >> N >> M >> K;
REP(a, M){
    scanf("%d %d %d", &b, &c, &d);
    E[d].pb(mp(b, c));
}
REPI(a, N) head[a] = a;
k = 0;
REP(a, E[1].size()){
    if(find_head(E[1][a].fi) == find_head(E[1][a].se)) continue;
    head[find_head(E[1][a].fi)] = find_head(E[1][a].se);
    k++;
    ans.pb(edge(E[0][a].fi, E[0][a].se, 1));
    if(k == N-1) break;
}
int cnt=0;
REPI(a, N){
    if(tmp[find_head(a)] == 0){
        cnt++;
    }
    tmp[find_head(a)] = 1;
}

if(cnt > K){
    cout << "no solution";
    return 0;
}

REP(a, E[0].size()){
    if(find_head(E[0][a].fi) == find_head(E[0][a].se)) continue;
    head[find_head(E[0][a].fi)] = find_head(E[0][a].se);
    k++;
    ans.pb(edge(E[0][a].fi, E[0][a].se, 0));
    if(k == K) break;
}
if(k!=K){
    printf("no solution");
    return 0;
}
if(k!=N-1){
    printf("no solution");
    return 0;
}

REP(a, ans.size()){
    printf("%d %d %d\n", ans[a].x, ans[a].y, ans[a].w);
}

return 0;
}
