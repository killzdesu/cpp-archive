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

using namespace std;

int DBG=0;
int i, n, k, N, M, K, G;
char plate[10010];
int pdfs[10010];
int g[10010];
bool vs[10010];
vector<int> grp[10010];
vector<int> vt[10010], v[10010];

void dfst(int x){
//    DB("dfst:: %d\n", x);
    if(vs[x]) return;
    vs[x] = true;
    int a;
    REP(a, vt[x].size()){
        dfst(vt[x][a]);
    }
    pdfs[x] = k++;
}

void dfs(int x){
    if(vs[x]) return;
//    DB("DFS %d\n", x+1);
    vs[x] = true;
    int a;
    REP(a, v[x].size()){
        dfs(v[x][a]);
    }
    g[x] = k;
    grp[k].pb(x);
}

int ord[10010];
vector<char> pg[10010];
vector<int> V[10010];

bool by_pdfs(int a, int b){
    return pdfs[a] > pdfs[b];
}

string PG[10010];
string SM[10010];
pii e[500010];
string TP;

void solve(int x){
    if(vs[x]) return;
    vs[x] = true;
    int a, c;
    REP(a, vt[x].size()){
        c = vt[x][a];
//        printf("%d -> %d\n", x+1, c+1);
        if(SM[c].length() < PG[c].length() + SM[x].length()){
            SM[c] = PG[c]+SM[x];
        }
        else if(SM[c].length() == PG[c].length() + SM[x].length()){
            TP = SM[x]+PG[c];
            SM[c] = min(SM[c], TP);
        }
    }
}

int main(){
int a, b, c, d;
cin >> N >> M;
cin >> plate;
REP(a, M){
    scanf("%d %d", &c, &d);
    c--; d--;
    v[c].pb(d);
    vt[d].pb(c);
    e[a] = mp(c, d);
}
REP(a, N) dfst(a);
fill_n(vs, N+5, 0);
REP(a, N) ord[a] = a;
sort(ord, ord+N, by_pdfs);
k = 0;
REP(a, N){
    c = ord[a];
    if(!vs[c]){
        dfs(c);
        k++;
    }
}
K = k;
REP(a, K){
    REP(b, grp[a].size())
        pg[a].pb(plate[grp[a][b]]);
    sort(pg[a].begin(), pg[a].end());
    REP(b, pg[a].size()){
        PG[a].push_back(pg[a][b]);
    }
    SM[a] = PG[a];
    DB("%d : %s\n", a+1, PG[a].c_str());
}
fill_n(vs, K+2, 0);
REP(a, N) vt[a].clear();

REP(a, e.size()){
    e[a].fi = grp[e[a].fi];
    e[a].se = grp[e[a].se];
}
sort(e.begin(), e.end());
e.resize(distance(e.begin(), unique(e.begin(), e.end())));

REP(a, M){
    if(e[a].fi == e[a].se) continue;
    vt[e[a].fi].pb(e[a].se);
}

REP(a, K) dfst(a);
REP(a, K) ord[a] = a;
sort(ord, ord+K, by_pdfs);
fill_n(vs, K+2, 0);
REP(a, K){
    c = ord[a];
    solve(c);
}
i = -1;
REP(a, K){
    i = max(i, (int)SM[a].length());
}
TP = "";
REP(a, K){
    if(SM[a].length() == i){
        if(TP.length() == 0) TP = SM[a];
        else TP = min(TP, SM[a]);
    }
}
cout << TP;
return 0;
}
