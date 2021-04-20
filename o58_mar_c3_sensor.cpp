#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#define IT iterator
#define all(x) x.begin(),x.end()
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
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
#include<set>

using namespace std;

int i, n, k, N, M, K;

struct node{
    int x, y, id;
    bool operator < (const node &b) const{
        if(x!=b.x) return x < b.x;
        return y < b.y;
    }
    node(){}
    node(int a, int b, int c){
        x = a; y = b; id = c;
    }
};

struct edge{
    int x, y;
    ll w;
    bool operator < (const edge &b) const{
        return w < b.w;
    }
    edge(){}
    edge(int a, int b, int c){
        x = a; y = b; w = c;
    }
};

//ll dist(node a, node b){
//    return ((ll)a.x-b.x)*(ll)(a.x-b.x)+((ll)a.y-b.y)*(ll)(a.y-b.y);
//}

ll dist(pii a, pii b){
    return ((ll)a.fi-b.fi)*(ll)(a.fi-b.fi)+((ll)a.se-b.se)*(ll)(a.se-b.se);
}

vector<node> p[12];
double A[12], B[12], C[12];
int head[50010];

int fh(int x){
    if(head[x] != x) head[x] = fh(head[x]);
    return head[x];
}

vector<pii> P;
vector<edge> E;

ll mst(){
    ll sm = 0;
    int a, cnt=0;
    sort(E.begin(), E.end());
    a = 0;
    while(cnt < N-1 and a < E.size()){
        if(fh(E[a].x) == fh(E[a].y)){
            a++;
            continue;
        }
        head[fh(E[a].x)] = fh(E[a].y);
        cnt++;
//        printf("%lld - %lld\n", E[a].w, sm);
        sm += E[a].w;
    }
    return sm;
}

set<pii> S;
set<pii>::IT it;

int main(){
int a, b, c, d;
cin >> N >> M;
REP(a, M){
    cin >> i;
    while(i--){
        scanf("%d %d", &c, &d);
        p[a].pb(node(c, d, k++));
        P.pb(mp(c, d));
        if(a == 1){
            S.insert(mp(c, k-1));
        }
    }
}
if(N <= 1000){
    REPI(a, N) head[a] = a;
    REP(a, N){
        for(b=a+1;b<N;b++){
            E.pb(edge(a, b, dist(P[a], P[b])));
        }
    }
    cout << mst();
}
else {
    REPI(a, N) head[a] = a;
    REP(a, p[0].size()){
        if(a != 0) {
            E.pb(edge(p[0][a].id, p[0][a-1].id, dist(P[p[0][a].id], P[p[0][a-1].id])));
        }
        it = S.lower_bound(mp(p[0][a].x, -1));
        if(it != S.end()){
            E.pb(edge(p[0][a].id, it->se, dist(P[p[0][a].id], P[it->se])));
        }
        if(it!=S.begin()){
            it--;
            E.pb(edge(p[0][a].id, it->se, dist(P[p[0][a].id], P[it->se])));
        }

    }
//    return 0;
    cout << mst();
}

return 0;
}
