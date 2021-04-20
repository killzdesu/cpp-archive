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
vector<pii> v[100010];
int achild[100010], child[100010], apar[100010], par[100010];
ll sum;

int lucky(int x){
    while(x != 0){
        if(x % 10 != 7 and x % 10 != 4) return 0;
        x /= 10;
    }
    return 1;
}

void dfs(int x, int prev){
    int a;
    child[x] = 0;
    achild[x] = 0;
    REP(a, v[x].size()){
        if(v[x][a].fi == prev) continue;
        dfs(v[x][a].fi, x);
        if(v[x][a].se == 1){
            achild[x] += child[v[x][a].fi]+1;
        }
        else {
            achild[x] += achild[v[x][a].fi];
        }
        child[x] += child[v[x][a].fi]+1;
    }
    par[x] = N-child[x]-1;
}

void find_par(int x, int prev){
    int a;
    REP(a, v[x].size()){
        if(v[x][a].fi == prev) continue;
        int u = v[x][a].fi;
        if(v[x][a].se){
            apar[u] = par[u];
        }
        else {
            apar[u] += apar[x];
            apar[u] += achild[x]-achild[u];
        }
    }
    REP(a, v[x].size()){
        if(v[x][a].fi == prev) continue;
        find_par(v[x][a].fi, x);
    }
}

int main(){
//freopen("input.in", "r", stdin);
string S = ".txt";
string test;
stringstream ss;
n = 19;
ss << n;
test = "bridge/"+ss.str();
freopen((test+".in"+S).c_str(), "r", stdin);
freopen((test+".sol"+S).c_str(), "w", stdout);

int a, b, c, d;
cin >> N;
REP(a, N-1){
    scanf("%d %d %d", &c, &d, &b);
    v[c].pb(mp(d, lucky(b)));
    v[d].pb(mp(c, lucky(b)));
}
dfs(1, -1);
find_par(1, -1);
//REPI(a, N) printf("%2d ", a);EL;
//REPI(a, N) printf("%2d ", achild[a]);EL;
//REPI(a, N) printf("%2d ", apar[a]);EL;

REPI(a, N){
    sum += (ll)((ll)achild[a]*(achild[a]-1));
    sum += (ll)apar[a]*(ll)achild[a]*2;
    sum += (ll)((ll)apar[a]*(apar[a]-1));
}

cout << sum;

return 0;
}
