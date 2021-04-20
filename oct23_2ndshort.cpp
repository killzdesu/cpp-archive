#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
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
#define mp make_pair
#define pii pair<int, int>
#define ll long long

using namespace std;

int i, n, k, N, M, K;

vector<pii> v[10010];
priority_queue<pii, vector<pii>, greater<pii> > Q;
int s[100010], dis[10010], dis2[10010], vs[10010];

int main(){
int a, b, c, d, S, T;
cin >> N >> M;
cin >> S >> T;
REP(a, M){
    scanf("%d %d %d", &c, &d, &b);
    v[c].pb(mp(d, b));
}
REP(a, 10005) dis[a] = dis2[a] = 2e9;
dis[S] = dis2[S] = 0;
pii t;
Q.push(mp(0, S));
while(!Q.empty()){
    t = Q.top();
    Q.pop();
//    if(vs[t.se] == 3) continue;
//    vs[t.se]++;
    REP(a, v[t.se].size()){
        if(dis[v[t.se][a].fi] > t.fi + v[t.se][a].se){
            dis2[v[t.se][a].fi] = dis[v[t.se][a].fi];
            dis[v[t.se][a].fi] = t.fi + v[t.se][a].se;
            Q.push(mp(dis[v[t.se][a].fi], v[t.se][a].fi));
            Q.push(mp(dis2[v[t.se][a].fi], v[t.se][a].fi));
        }
        else if(dis[v[t.se][a].fi] == t.fi + v[t.se][a].se){;}
        else if(dis2[v[t.se][a].fi] > t.fi + v[t.se][a].se){
            dis2[v[t.se][a].fi] = t.fi + v[t.se][a].se;
            Q.push(mp(dis2[v[t.se][a].fi], v[t.se][a].fi));
        }
    }
}
printf("%d", dis2[T], dis[T]);


return 0;
}
