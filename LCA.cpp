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
const int LN = 12;

int h[1010];
int P[LN][1010];
vector<int> v[1010];

void dfs(int x, int d){
    h[x] = d;
    for(int a=0;a<v[x].size();a++){
//        if(P[0][x] == v[x][a]) continue;
//        P[0][v[x][a]] = x;
        dfs(v[x][a], d+1);
    }
}

int LCA(int p, int q){
    int a;
    if(h[p] < h[q]) swap(p, q);
    for(a=LN-1;a>=0;a--){
//        printf("%d:: [%d %d] -- hp[%d] hq[%d] up_to[%d]\n", a, p, q, h[p], h[q], 1<<a);
        if(h[p]-(1<<a) >= h[q]) p = P[a][p];
    }
//    printf(">> %d %d\n", p, q);
    if(p == q) return p;
    for(a=LN-1;a>=0;a--){
        if(P[a][p] != -1 and P[a][p] != P[a][q]){
            p = P[a][p];
            q = P[a][q];
        }
    }
    return P[0][p];
}

int LCAA(int u, int v) {
	if(h[u] < h[v]) swap(u,v);
	int diff = h[u] - h[v];
	for(int i=0; i<LN; i++) if( (diff>>i)&1 ) u = P[i][u];
	if(u == v) return u;
	for(int i=LN-1; i>=0; i--) if(P[i][u] != P[i][v]) {
		u = P[i][u];
		v = P[i][v];
	}
	return P[0][u];
}

int main(){
int a, b, c, d;
int T, R;
cin >> T;
REPI(R, T){
    printf("Case %d:\n", R);
    cin >> N;
    REPI(a, N) REP(b, LN){
        v[a].clear();
        h[a] = 1;
        P[b][a] = -1;
    }
    REPI(a, N){
        scanf("%d", &d);
        REP(b, d){
            scanf("%d", &c);
            v[a].pb(c);
            P[0][c] = a;
//            v[c].pb(a);
        }
    }
    REPI(a, N) if(P[0][a] == -1) break;
    dfs(a, 1);
    for(a=1;a<LN;a++){
        for(b=1;b<=N;b++){
            if(P[a-1][b] != -1){
                P[a][b] = P[a-1][P[a-1][b]];
//                printf("P[%d][%d] = %d\n", a, b, P[a-1][P[a-1][b]]);
            }
        }
    }
//    REPI(a, N){
//        printf("%d:%d ", a, h[a]);
//    }printf("\n");
//    cout << P[1][13];
    cin >> M;
    while(M--){
        scanf("%d %d", &c, &d);
        printf("%d\n", LCA(c, d));
    }
}

return 0;
}
