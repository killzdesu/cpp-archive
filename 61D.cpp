#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define all(x) x.begin(),x.end()
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()


using namespace std;

int i, n, k, N, M, K;
int child[100100], par[100010], root[100010];
long long dist[100010], D;
vector<pii> v[100010];

void make_tree(int x, int prev, ll d){
    int a;
    root[x] = prev;
    child[x] = 1;
    dist[x] = 0;
    D += d;
    REP(a, sz(v[x])){
        if(v[x][a].fi == prev){
            v[x].erase(v[x].begin()+a);
            a--;
            continue;
        }
        make_tree(v[x][a].fi, x, ((ll)v[x][a].se+d));
        child[x] += child[v[x][a].fi];
    }
    par[x] = N-child[x];
//    child[x]--;
}

ll mn;

void dfs(int x, ll cost){
    int a;
    dist[x] = dist[root[x]]+par[x]*cost-child[x]*cost;
    mn = min(mn, dist[x]);
    REP(a, v[x].size()){
        dfs(v[x][a].fi, (ll)v[x][a].se);
    }
}

int main(){
int a, b, c, d;
cin >> N;
REP(a, N-1){
    scanf("%d %d %d", &c, &d, &b);
    v[d].pb(mp(c, b));
    v[c].pb(mp(d, b));
}
make_tree(1, 0, 0);
dist[0] = D;
mn = 2e17;
dfs(1, 0);
cout << mn;
return 0;
}
