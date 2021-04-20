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

int root[100010];
ll up[100010];
ll down[100010];
ll node[100010];
vector<int> v[100010];

int dfs(int x, int r){
    root[x] = r;
    for(int a=0;a<v[x].size();a++){
        if(v[x][a] == r) continue;
        dfs(v[x][a], x);
    }
}

int find_node(int x){
    int a, s=1;
    REP(a, v[x].size()){
        if(v[x][a] == root[x]) continue;
        s += find_node(v[x][a]);
    }
    node[x] = s;
    return s;
}

int find_down(int x){
    int a, s=0;
    REP(a, v[x].size()){
        if(v[x][a] == root[x]) continue;
        s += find_down(v[x][a])+node[v[x][a]];
    }
    down[x] = s;
    return s;
}

int find_up(int x){
    int a, s=0;
    up[x] = 0;
    if(root[x]!=-1){
//        up[x] += up[root[x]]+down[root[x]]+node[root[x]]-2*node[x]-down[x]+N-node[root[x]];
        up[x] += down[root[x]]-down[x]-node[x]+node[root[x]]-node[x]+up[root[x]]+N-node[root[x]];
    }
    REP(a, v[x].size()){
        if(v[x][a] == root[x]) continue;
        find_up(v[x][a]);
    }
    return up[x];
}

int main(){
int a, b, c, d;
cin >> N;
REP(a, N-1){
    scanf("%d %d", &c, &d);
    v[c].pb(d);
    v[d].pb(c);
}
dfs(1, -1);
find_node(1);
find_down(1);
find_up(1);
//cout << up[3];
ll mn = 2e12;
for(a=1;a<=N;a++){
//    printf("%d: [%lld %lld] ^ %lld\n", a, node[a], down[a], up[a]);
    mn = min(mn, up[a]+down[a]);
}

cout << mn;

return 0;
}
