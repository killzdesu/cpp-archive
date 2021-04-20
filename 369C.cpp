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
#define sz(_x) (int)_x.size()
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

int DBG=1;
int i, n, k, N, M, K;
vector<pii> v[200010];
int root[200010];
vector<int> ans;

int dfs(int x, int y){
    int a, c=0;
//    printf("%d ---------\n", x);
    REP(a, sz(v[x])){
        if(v[x][a].fi == root[x]){
            v[x].erase(v[x].begin()+a);
            a--;
            continue;
        }
        root[v[x][a].fi] = x;
        c += dfs(v[x][a].fi, v[x][a].se);
    }
    if(y == 2 and c == 0){
        ans.pb(x);
        return 1;
    }
    if(y == 2 and c != 0) return c;
    return c;
}

int main(){
int a, b, c, d;
cin >> N;
REP(a, N-1){
    scanf("%d %d %d", &c, &d, &i);
    v[c].pb(mp(d, i));
    v[d].pb(mp(c, i));
}
cout << dfs(1, 1) << "\n";
REP(a, sz(ans)){
    printf("%d ", ans[a]);
}
return 0;
}
