#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
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
vector<int> v[5010], vt[5010];
stack<int> order, S;
queue<int> Q;
bool m[5005][5005];
bool vs[5010];
int g[5010], z[5010];

void dfst(int x){
    if(vs[x]) return;
    vs[x] = 1;
    for(int a=0;a<vt[x].size();a++){
        dfst(vt[x][a]);
    }
    order.push(x);
}

void dfsp(int x){
    if(vs[x]) return;
    vs[x] = 1;
    g[x] = k;
    for(int a=0;a<v[x].size();a++){
        dfsp(v[x][a]);
    }
}

void topo(int x){
    if(vs[x]) return;
    vs[x] = 1;
    for(int a=0;a<=k;a++){
        if(m[x][a])topo(a);
    }
    S.push(x);
}

void dfsl(int x, int val){
    if(vs[x]) return;
    vs[x] = 1;
    z[x] = max(z[x], val);
    for(int a=0;a<=k;a++){
        if(m[x][a]) dfsl(a, z[x]+1);
    }
}

int val[5010];

int main(){
int a, b, c, d, r, mx;
cin >> N >> M;
REP(a, M){
    scanf("%d %d", &c, &d);
    v[c].pb(d);
    vt[d].pb(c);
}

REP(a, N) dfst(a);

fill_n(vs, N+1, 0);

while(!order.empty()){
    if(vs[order.top()]==0){
        k++;
        dfsp(order.top());
    }
    order.pop();
}

REP(a, N){
    //printf("%d: %d\n", a, g[a]);
    REP(b, v[a].size()){
        if(g[v[a][b]] != g[a])
            m[g[a]][g[v[a][b]]] = 1;
    }
}

fill_n(vs, k+1, 0);

REPI(a, N) topo(a);

fill_n(vs, k+1, 0);

while(!S.empty()){
    c = S.top();
    S.pop();
    //z[c] = max(z[c], 0);
    for(a=0;a<=k;a++){
        if(m[c][a]) z[a] = max(z[a], z[c]+1);
    }
}

mx = 0;
REP(a, N){
    //printf("%d\n", z[g[a]]);
    val[z[g[a]]]++;
    mx = max(mx, z[g[a]]);
}
REP(a, mx+1){
    printf("%d ", val[a]);
}
return 0;
}
