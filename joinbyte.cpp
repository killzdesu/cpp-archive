#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(all(x));(x).resize(distance((x).begin, unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()


using namespace std;

int i, n, k, N, M, K;

int vs[2010];
vector<int> v[2010];
int G[2010][2010];
int rG[2010][2010];

int dfs_cap(int x, int T, int flow, int cap){
    if(vs[x]) return 0;
    vs[x] = true;
    printf("AUG %d\n", x);
    if(x == T) return flow;
    int F;
    for(int a=0; a<v[x].size(); a++){
        int u = v[x][a];
        if(rG[x][u] < cap) continue;
        F = dfs_cap(u, T, min(flow, rG[x][u]), cap);
        if(F){
            rG[x][u] -= F;
            rG[u][x] += F;
            return F;
        }
    }
    return 0;
}

int maxflow_cap(int s, int t, int N){
    int a, b;
//    REP(a, N) REP(b, N) {
//        rG[a][b] = G[a][b];
//    }
    int cap=2, flow=32, max_flow=0;
    while(cap > 0){
        fill(vs, vs+N+1, 0);
        while(flow = dfs_cap(s, t, (int)2e9, cap)){
            max_flow += flow;
            fill(vs, vs+N+1, 0);
        }
        cap/=2;
    }
    return max_flow;
}

char S[1010][1010];
char ST[2010];

int chk_palin(char ST[2010]){
    int N = strlen(ST);
    for(int a=0;a<=N/2;a++){
        if(ST[a] != ST[N-1-a]) return 0;
    }
    return 1;
}

int main(){
int a, b, c, d;

cin >> N;
v[2004].clear();
v[2005].clear();
REP(a, 2006) REP(b, 2006) G[a][b] = 0;
REP(a, 2006){
    v[a].clear();
}
REP(a, N){
    scanf("%s", S[a]);
    REP(b, a){
        strcpy(ST, S[a]);
        strcat(ST, S[b]);
        c = chk_palin(ST);
        if(c == 0){
            strcpy(ST, S[b]);
            strcat(ST, S[a]);
            c = chk_palin(ST);
        }
        if(c) {
            printf("%d -> %d\n", b, a);
            v[b].pb(a+N);
            rG[b][a+N] = 1;
        }
    }
    v[2004].pb(a);
    rG[2004][a] = 1;
    v[a+N].pb(2005);
    rG[a+N][2005] = 1;
}
cout << maxflow_cap(2004, 2005, 2005);

return 0;
}
