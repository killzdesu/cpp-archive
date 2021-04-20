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

int i, n, k, N, M, K, dis[1010];

vector<pii> v[1000];
priority_queue<pii, vector<pii>, greater<pii> > q;

int main()
{
    int a, b, c, d;
    char t1, t2;
    cin >> M;
    REP(a, M)
    {
        scanf(" %c %c %d", &t1, &t2, &d);
        v[t1].pb(mp(t2, d));
        v[t2].pb(mp(t1, d));
    }
    REP(a, 400) dis[a] = 2e9;
    dis['Z'] = 0;
    q.push(mp(0, 'Z'));
    pii tmp;
    while(!q.empty())
    {
        tmp = q.top();
        q.pop();
        c = tmp.se;
        d= tmp.fi;
        if(dis[c] > d) continue;
        REP(a, v[c].size()){
            if(dis[v[c][a].fi] > dis[c]+v[c][a].se){
                dis[v[c][a].fi] = dis[c]+v[c][a].se;
                q.push(mp(dis[v[c][a].fi], v[c][a].fi));
            }
        }

    }
    i = 0;
    for(a='A'; a<'Z'; a++)
    {
        if(dis[a] < dis[i])i = a;
    }
//printf("%d ", i);
    printf("%c %d", i, dis[i]);


    return 0;
}
