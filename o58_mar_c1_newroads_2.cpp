#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<set>
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

pii p[200010], e[200010];
int cnt[200010], deg[100010], w[200010], u[200010];
list<pii> v[100010];

set<int> S;
stack<int> Q;

vector<int> ans;

void dfs(int x){
    if(k == M){
        return;
    }
//    printf("Now : %d\n", x);
    int a;
    list<pii>::iterator it;
    while(!v[x].empty()){
        it = v[x].begin();
        if(u[it->se] == 1){
            v[x].erase(it);
            continue;
        }
        u[it->se] = 1;
        k++;
        if(p[it->se].fi != x){
            ans.pb(it->se);
        }
        a = it->fi;
        v[x].erase(it);
        dfs(a);
    }
}

int main(){
int a, b, c, d;
cin >> N >> M;
REP(a, M){
    scanf("%d %d %d", &p[a].fi, &p[a].se, &e[a].fi);
    deg[p[a].fi]++;
    deg[p[a].se]--;
    e[a].se = a;
    w[a] = e[a].fi;
    v[p[a].fi].pb(mp(p[a].se, a));
    v[p[a].se].pb(mp(p[a].fi, a));
}

REPI(a, N) S.insert(a);
k = 0;
int num, id;
int sm = 0;

Q.push(1);

//dfs(1);
int x=0;
while(!Q.empty()){
//    printf("Now : %d   has %d\n", x, v[x].size());
    x = Q.top();
    Q.pop();
    if(v[x].size() == 0){
        continue;
    }
    int a;
    list<pii>::iterator it;
    while(!v[x].empty()){
        it = v[x].begin();
        if(u[it->se] == 1){
            v[x].erase(it);
            continue;
        }
        u[it->se] = 1;
        k++;
        if(p[it->se].fi != x){
            ans.pb(it->se);
        }
        a = it->fi;
        v[x].erase(it);
        Q.push(x);
        Q.push(a);
        break;
    }

}

printf("%d\n", ans.size());
REP(a, ans.size()){
    printf("%d\n", ans[a]+1);
}

return 0;
}
