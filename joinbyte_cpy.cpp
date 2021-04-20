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

vector<vector<int> > graph;
vector<int> TT;

struct MaxMatchingEdmonds {
    int match[1005];

    int lca(int base[], int p[], int a, int b) {
        bool used[1001];
        while (true) {
            a = base[a];
            used[a] = true;
            if (match[a] == -1) break;
            a = p[match[a]];
        }
        while (true) {
            b = base[b];
            if (used[b]) return b;
            b = p[match[b]];
        }
    }

    void markPath(int base[], bool blossom[], int p[], int v, int b, int children) {
        for (; base[v] != b; v = p[match[v]]) {
            blossom[base[v]] = blossom[base[match[v]]] = true;
            p[v] = children;
            children = match[v];
        }
    }

    int findPath(int p[], int root) {
        int n = graph.size();
        bool used[n];
        fill(p, p+n, -1);
        int base[n];
        for (int i = 0; i < n; ++i)
            base[i] = i;

        used[root] = true;
        int qh = 0;
        int qt = 0;
        int q[n];
        for(int i=0;i<n;i++) q[i] = 0;
        q[qt++] = root;
        while (qh < qt) {
            int v = q[qh++];

            for (int a=0;a<graph[v].size();a++) {
                int to = graph[v][a];
                if (base[v] == base[to] || match[v] == to) continue;
                if (to == root || match[to] != -1 && p[match[to]] != -1) {
                    int curbase = lca(base, p, v, to);
                    bool blossom[n];
                    markPath(base, blossom, p, v, curbase, to);
                    markPath(base, blossom, p, to, curbase, v);
                    for (int i = 0; i < n; ++i)
                        if (blossom[base[i]]) {
                            base[i] = curbase;
                            if (!used[i]) {
                                used[i] = true;
                                q[qt++] = i;
                            }
                        }
                } else if (p[to] == -1) {
                    p[to] = v;
                    if (match[to] == -1)
                        return to;
                    to = match[to];
                    used[to] = true;
                    q[qt++] = to;
                }
            }
        }
        return -1;
    }

    int maxMatching() {
        int n = graph.size();
//        match = vector<int>(n, -1);
        fill(match, match+n, -1);
        int p[n];
        for (int i = 0; i < n; ++i) {
            if (match[i] == -1) {
                int v = findPath(p, i);
                while (v != -1) {
                    int pv = p[v];
                    int ppv = match[pv];
                    match[v] = pv;
                    match[pv] = v;
                    v = ppv;
                }
            }
        }

        int matches = 0;
        for (int i = 0; i < n; ++i)
            if (match[i] != -1)
                ++matches;
        return matches / 2;
    }

    // Usage example
    int main() {
        return maxMatching();
    }
}mm;

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
//freopen("input.in", "r", stdin);
int a, b, c, d;
int TR;
while(cin >> N){
graph.clear();
for (int i = 0; i < N; i++) {
    graph.pb(TT);
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
//            printf("%d -> %d\n", b, a);
            graph[b].pb(a);
            graph[a].pb(b);
        }
    }
}
cout << N-mm.main() << "\n";
}
return 0;
}
