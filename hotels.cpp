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
#define mp make_pair
#define pii pair<int, int>
#define ll long long

using namespace std;

vector<int> v[30010];
int vs[30010],  L[30010], P[30010][20];
int i, N, M ,K, n, m, k;

void dfs(int x, int l, int p)
{
    if(vs[x]) return;
    vs[x] = 1;
    P[x][0] = p;
    L[x] = l;
    for(int a=0; a<v[x].size(); a++)
    {
        dfs(v[x][a], l+1, x);
    }
}

void process(int N)
{
    int i, j;
    int k = ceil(log2(N));

    REP(i, N+1) for(j = 1; j<=k; j++)
        P[i][j] = -1;

    for(j=1; j<=k; j++)
        for(i=1; i<=N; i++)
            if (P[i][j-1] != -1)
                P[i][j] = P[P[i][j-1]][j-1];
}

int find_head(int p, int q)
{
    int tmp, log, i;

    if (L[p] < L[q]) swap(p, q);

    log = floor(log2(L[p]));
//    for (log = 1; 1 << log <= L[p]; log++);
//      log--;

    for (i=log;i >= 0;i--)
        if (L[p]-(1 << i) >= L[q])
            p = P[p][i];

    if (p == q)
        return p;

    for (i = log;i >= 0; i--)
        if (P[p][i] != -1 and P[p][i] != P[q][i]){
            p = P[p][i];
            q = P[q][i];
        }

    return P[p][0];
}

int dis[5010][5010];
long long sm;
long long t1, t2, t3, t;
int cnt[5001];


int main()
{
    int a,b,c, d,ans=0;
    scanf("%d", &N);
    for(i=1; i<N; i++)
    {
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0, 1);
    process(N);
    int now = 1;

    REPI(a, N) for(b=a+1;b<=N;b++)
    {
        dis[a][b] = dis[b][a] = L[b]+L[a]-2*L[find_head(a, b)];
    }
    REPI(a, N){
        REP(b, N+1) cnt[b] = 0;
        REPI(b, N)
        {
            cnt[dis[a][b]]++;
        }
        REPI(b, N){
            t1 = cnt[b];
            sm += t1*(t1-1)*(t1-2)/6;
        }
    }
    cout << sm;

    return 0;
}
