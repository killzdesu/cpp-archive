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
int C[100010];

vector<int> v[100010];

void g42(int x){

}

int dc[100010];

int dfs(int x, int y){
    if(dc[x]!=0){
        if((y-dc[x])%2==1){
            return 0;
        }
        return 1;
    }
    dc[x] = y;
    for(int a=0;a<v[x].size();a++){
        if(dfs(v[x][a], y+1) == 0) return 0;
    }
    return 1;
}

int main(){
int a, b, c, d;
cin >> N >> M;
REP(a, M){
    scanf("%d %d", &c, &d);
    v[c].pb(d);
    v[d].pb(c);
}
REP(a, N-1){
    v[a].pb(a+1);
    v[a+1].pb(a);
}
if(dfs(1, 1) == 0){
    printf("3\n");
}
else {
    printf("2\n");
}

return 0;
}
