#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin(), unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define dump(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

int i, n, k, N, M, K;

vector<int> v[100010];
int vs[100010];
int art[100010];
int dx[100010];
int dist[100010];
int can[100010];
int h[100010];
vector<int> V[100010];
deque<int> path;

queue<pair<pii, int> > Q;

void dfs(int x, int D, int par){
    vs[x] = 1;
    dx[x] = D;
    h[x] = D;
//    printf("to %d from %d\n", x, par);
    int a = -1;
    for(auto u: v[x]){
        if(u == par) continue;
        if(!vs[u]){
            dfs(u, D+1, x);
            dx[x] = min(dx[u], dx[x]);
            if(dx[u] >= h[x]) art[x] = 1;
        }
        else mina(dx[x], h[u]);
    }
//    printf("> %d h[%d] dx[%d]\n", x, h[x], dx[x]);
//    if(dx[x] >= D){
//        art[x] = 1;
//        i++;
//    }
}

void dfs2(int x, int par){
    for(auto u: V[x]){
        if(u == par) continue;
        dfs2(u, x);
        can[x] |= can[u];
    }
    if(can[x]) path.push_front(dist[x]);
}

int main(){
//freopen("in_hike.txt", "r", stdin);
int a, b, c, d;
cin >> N >> M >> K;
REP(a, M){
    scanf("%d %d", &c, &d);
    v[c].pb(d);
    v[d].pb(c);
}
can[N] = 1;
dfs(1, 1, -1);
art[1] = 1;
art[N] = 1;
can[1] = 1;

fill(vs, vs+N+2, 0);
Q.push({{1, 0}, 0});
while(!Q.empty()){
    auto t = Q.front();
    Q.pop();
    if(vs[t.fi.fi]) continue;
    vs[t.fi.fi] = 1;
    dist[t.fi.fi] = t.se;
    if(art[t.fi.fi]){
        V[t.fi.se].pb(t.fi.fi);
//        printf("%d -> %d\n", t.se, t.fi);
        t.fi.se = t.fi.fi;
    }
    for(auto u: v[t.fi.fi]){
        Q.push({{u, t.fi.se}, t.se+1});
    }
}
dfs2(1, -1);

//REPI(a, N) printf(" %2d", a); EL;
//REPI(a, N) printf(" %2d", art[a]); EL;
//REPI(a, N) printf(" %2d", can[a]); EL;
//for(auto x: path) printf("%d ", x); EL;
int cnt = 0;
K *= 2;
int last = 0;
path.pop_front();
path.pop_back();
for(auto x: path){
    if(x > last){
        cnt++;
        last = x+K;
    }
}
cout << cnt;
return 0;
}
