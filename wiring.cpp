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

using namespace std;

int i, n, k, N, M, K, err;
int up[100010], down[100010];
int post[100010];
bool vs[100010];
vector<int> v[100010];

void dfs(int x){
    if(err) return;
    if(vs[x]){
        if(!post[x]){
            err = 1;
            return;
        }
        return ;
    }
    vs[x] = true;
    for(int a=0;a<v[x].size() and !err;a++){
        dfs(v[x][a]);
    }
    post[x] = k++;
    return;
}

int main(){
int a, b, c, d;
int R, mx;
cin >> R;
while(R--){
    mx = 0;
    cin >> N;
    REPI(a, N){
        v[a].clear();
        post[a] = vs[a] = 0;
        scanf("%d", &c);
        mx = max(mx, c);
        if(!c) continue;
        up[c] = a;
    }
    REPI(a, N){
        scanf("%d", &c);
        if(!c) continue;
        down[c] = a;
    }
    REPI(a, mx){
        if(up[a] != down[a])
            v[up[a]].pb(down[a]);
    }
    k = 1;
    err = 0;
    REPI(a, mx) dfs(a);
    if(err) cout << "NO\n";
    else cout << "YES\n";
}



return 0;
}
