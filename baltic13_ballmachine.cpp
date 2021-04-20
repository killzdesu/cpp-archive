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

int i, n, k, N, M, K;
const int LN  = 19;
int P[LN][100010], mn[100010], num[100010], ord[100010], u[100010], rnk[100010];
vector<int> v[100010];
priority_queue<pii, vector<pii>, greater<pii> > Q;

void dfs(int x){
    int a;
    int m=x;
    num[x] = 1;
    mn[x] = x;
    REP(a, v[x].size()){
        dfs(v[x][a]);
        num[x]+=num[v[x][a]];
        mn[x] = min(mn[x], mn[v[x][a]]);
    }
//    mn[x] = m;
}

void dfs_ans(int x, int lo, int hi){
    int a, b, cnt=0;
    REP(a, v[x].size()){
        dfs_ans(v[x][a], lo+cnt, lo+cnt+num[v[x][a]]-1);
        cnt+=num[v[x][a]];
    }
    ord[k++] = x;
    rnk[x] = k-1;
}

bool cmp(int a, int b){
    return mn[a] < mn[b];
}

int main(){
//freopen("ballmachine.in", "r", stdin);
//freopen("ballmachine.out", "w", stdout);
int a, b, c, d;
cin >> N >> M;
REPI(a, N)REP(b, LN){
    P[b][a] = -1;
}
int root;
REPI(a, N){
    scanf("%d", &P[0][a]);
    if(P[0][a] == 0){
        P[0][a] = -1;
        root = a;
    }
    v[P[0][a]].pb(a);
}
for(a=1;a<LN;a++){
    REPI(b, N){
        if(P[a-1][b] != -1){
            P[a][b] = P[a-1][P[a-1][b]];
        }
    }
}

dfs(root);

REPI(a, N){
    sort(v[a].begin(), v[a].end(), cmp);
}

dfs_ans(root, 0, N-1);

REPI(a, N){
    Q.push(mp(rnk[a], a));
}
//REPI(a, N){
//    printf("%d: %d\n", a, mn[a]);
//}

int zxc;
REP(zxc, M){
    scanf("%d %d", &c, &d);
    if(c == 1){
        for(a=0;a<d;a++){
            b = Q.top().se;
            Q.pop();
            u[b] = 1;
        }
        printf("%d\n", b);
    }
    else {
        int cnt = 0;
        for(a=LN-1;a>=0;a--){
            if(P[a][d]!=-1 and u[P[a][d]] == 1){
                d = P[a][d];
                cnt+= (1<<a);
            }
        }
        u[d] = 0;
        Q.push(mp(rnk[d], d));
        printf("%d\n",cnt);
    }
}


return 0;
}
