#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<list>
#include<cmath>
#include<stack>
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

pii p[200010];
bool u[200010], vs[100010];
int deg[100010], w[200010];
list<pii> v[100010];

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

int find(int x, int T){
    if(x == T) return 1;
    if(vs[x] == 1)return 0;
    vs[x] = 1;
    list<pii>::iterator it;
    for(it=v[x].begin(); it!=v[x].end(); it++){
        if(find(it->fi, T)) return 1;
    }
    return 0;
}

int main(){
int a, b, c, d;
cin >> N >> M;
REP(a, M){
    scanf("%d %d %d", &p[a].fi, &p[a].se, &c);
    deg[p[a].fi]++;
    deg[p[a].se]++;
    w[a] = c;
    v[p[a].fi].pb(mp(p[a].se, a));
    v[p[a].se].pb(mp(p[a].fi, a));
}
k = 0;
int num, id;
int sm = 0;
stack<int> Q;
//dfs(1);
int x;
list<pii>::iterator it;
x = 1;
Q.push(1);
int c1, c2;
while(k!=M){
    if(v[x].empty()) break;
    printf("Now :%d\n", x);
    it = v[x].begin();
    if(u[it->se] == 1){
        v[x].erase(it);
        continue;
    }
    a = it->fi;
    fill_n(vs, N+1, 0);
    a = it->fi;
    while(it!=v[x].end() and find(it->fi, x)==0) it++;
    if(it==v[x].end())it = v[x].begin();
    u[it->se] = 1;
    k++;
    if(p[it->se].fi != x){
        ans.pb(it->se);
    }
    v[x].erase(it);
    x = a;
}
printf("%d\n", ans.size());
REP(a, ans.size()){
    printf("%d\n", ans[a]+1);
}

return 0;
}
