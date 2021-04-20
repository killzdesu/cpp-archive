#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#define DB if(DBG)printf
#define IT iterator
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

using namespace std;

int DBG=0;
int i, n, k, N, M, K, R;

int root[6010];
vector<int> v[6010];
int vs[6010];
int s[6010];

int dfs(int x, int cnt, int sm){
    if(k <= cnt) return 0;
    vs[x] = R;
    int a;
    sm += s[x];
    if(sm >= K) return 1;
    REP(a, v[x].size()){
        if(vs[v[x][a]] == R) continue;
        if(dfs(v[x][a], cnt+1, sm)) return 1;
    }
    return 0;
}

bool check(int mi){
    k = mi;
    R = 0;
    fill(vs, vs+N+1, 0);
    REP(i, N){
        R++;
        if(dfs(i, 0, 0)) return 1;
    }
    return 0;
}

int main(){
int a, b, c, d;
cin >> N >> K;
REP(a, N){
    scanf("%d", &s[a]);
}
REP(a, N-1){
    scanf("%d %d", &c, &d);
    v[c].pb(d);
    v[d].pb(c);
}
int lo=2, mi, hi=N;
while(lo < hi){
    mi = lo+(hi-lo)/2;
    if(check(mi)) hi = mi;
    else lo = mi+1;
//    printf(":: %d %d\n", lo, hi);
}
if(check(lo)) cout << lo-1;
else printf("-1");
return 0;
}
