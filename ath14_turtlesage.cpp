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
int val[100010], L[100010], vs[100010], A[100010], mx;
vector<int> v[100010];

int dfs(int x){
    int a, b, c, d;
    vs[x] = 1;
    c = d = -2e9;
    REP(a, v[x].size()){
        if(vs[v[x][a]]) continue;
        c = dfs(v[x][a]);
        if(c==-2e9) continue;
        if(L[x] == -2e9) L[x] = c;
        else {
            mx = max(L[x]+c+val[x], mx);
            L[x] = max(L[x], c);
        }
    }
    if(A[x]){
        L[x] = max(val[x], L[x]+val[x]);
        mx = max(L[x], mx);
    }
    else {
        if(L[x] != -2e9)L[x] += val[x];
    }
    //printf("%d -- %d\n", x, L[x]);
    return L[x];
}

int main(){
int a, b, c, d, T;
cin >> T;
while(T--){
    REP(a, 100003){
        L[a] = -2e9;
        vs[a] = 0;
        mx = -2e9;
        v[a].clear();
    }
    cin >> N;
    REP(a, N-1){
        scanf("%d %d", &c, &d);
        v[c].pb(d);
        v[d].pb(c);
    }
    REPI(a, N) scanf("%d", &val[a]);
    REPI(a, N) scanf("%d", &A[a]);
    dfs(1);
    if(mx > 0)printf("%d\n", mx);
    else printf("Stay Home\n");
}



return 0;
}
