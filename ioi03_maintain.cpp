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

struct edge{
    int x, y, w;
    bool operator < (const edge &b) const{
        return w < b.w;
    }
}E[6010];

int del;
vector<edge> m, ans;
int head[400];

int find_head(int x){
    if(head[x] != x){
        head[x] = find_head(head[x]);
    }
    return head[x];
}

int mst(){
    int a, sm = 0;
    sort(m.begin(), m.end());
    REPI(a, N){
        head[a] = a;
    }
    k = 0;
    del = -1;
    REP(a, m.size()){
        if(find_head(m[a].x) == find_head(m[a].y)){
            del = a;
            continue;
        }
        else {
            head[find_head(m[a].x)] = find_head(m[a].y);
            sm += m[a].w;
            k++;
        }
    }
    if(k!=N-1) return -1;
    return sm;
}

int main(){
int a, b, c, d;
cin >> N >> M;
REP(i, M){
    scanf("%d %d %d", &E[i].x, &E[i].y, &E[i].w);
    m.pb(E[i]);
    del = -1;
    printf("%d\n", mst());
    if(del != -1)m.erase(m.begin()+del);
}


return 0;
}
