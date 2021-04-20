#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#define DB if(DBG)printf
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
#include "maxflow.h"

using namespace std;

int DBG=1;
int i, n, k, N, M, K;

typedef long long LL;

int E[1010], H[1010], F[1010][1010], C[1010][1010];
vector<int> v[1010];

int push_relabel(int S, int T){
    int p, a, b, mn, q, c;
    queue<int> Q;
    REP(a, N) H[a] = 0;
    H[S] = N;

    REP(a, sz(v[S])){
        E[v[S][a]] += C[S][v[S][a]];
        E[S] -= C[S][v[S][a]];
        F[S][v[S][a]] += C[S][v[S][a]];
        F[v[S][a]][S] -= C[S][v[S][a]];
        if(v[S][a] != T) Q.push(v[S][a]);
    }
    int df;
    while(!Q.empty()){
        p = Q.front();
        c = 0;
        mn = 2e9;
        REP(a, sz(v[p])){
            if(E[p] <= 0) break;
            q = v[p][a];
            if(H[q] < H[p]){
                df = min(E[p], C[p][q]-F[p][q]);
                F[p][q] += df;
                F[q][p] -= df;
                E[p] -= df;
                E[q] += df;
                if(q != T and E[q] > 0){
                    Q.push(q);
                }
                if(df != 0) c = 1;
            }
            else {
                mn = min(mn, H[q]);
            }
        }
        if(c==0 and E[p] > 0){
            H[p]=mn + 1;
        }
        if(E[p] <= 0){
            Q.pop();
        }
    }
    return E[T];
}

//struct Edge{int w, u, v;};

int maxflow(int n, int m, int s, int t, Edge *e, int *f){
    int a, b;
    N = n;
    M = m;
    REP(a, N) REP(b, N) C[a][b] = F[a][b]= 0;
    REP(a, N){
        v[a].clear();
        E[a] = 0;
    }
    REP(a, M){
        C[e[a].v][e[a].w] = e[a].u;
        v[e[a].v].pb(e[a].w);
    }
    b = push_relabel(s, t);
    REP(a, M){
        f[a] = F[e[a].v][e[a].w];
    }
    return b;
}
//
//int main() {
//    int a, b, c, d;
//    int graph[6][6] = { {0, 16, 13, 0, 0, 0},
//                        {0, 0, 10, 12, 0, 0},
//                        {0, 4, 0, 0, 14, 0},
//                        {0, 0, 9, 0, 0, 20},
//                        {0, 0, 0, 7, 0, 4},
//                        {0, 0, 0, 0, 0, 0} };
//    N = 6;
//    REP(a, 6) REP(b, 6){
//        if(graph[a][b]){
//            C[a][b] = graph[a][b];
//            v[a].pb(b);
//            v[b].pb(a);
//        }
//    }
//    cout << push_relabel(0, 5);
//
//    return 0;
//}
