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

class MaxMatchingEdmonds {

    int lca(vector<int> &match, int base[], int p[], int a, int b) {
        bool used[match.size()];
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

    void markPath(vector<int> &match, int base[], bool blossom[], int p[], int v, int b, int children) {
        for (; base[v] != b; v = p[match[v]]) {
            blossom[base[v]] = blossom[base[match[v]]] = true;
            p[v] = children;
            children = match[v];
        }
    }

    int findPath(vector<vector<int> > &graph, vector<int> &match, int p[], int root) {
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
                    int curbase = lca(match, base, p, v, to);
                    bool blossom[n];
                    markPath(match, base, blossom, p, v, curbase, to);
                    markPath(match, base, blossom, p, to, curbase, v);
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

    int maxMatching(vector<vector<int> > graph) {
        int n = graph.size();
        vector<int> match(n, -1);
//        fill(match, match+n, -1);
        int p[n];
        for (int i = 0; i < n; ++i) {
            if (match[i] == -1) {
                int v = findPath(graph, match, p, i);
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
    public: void main() {
        int n = 4;
        vector<vector<int> > g;
        vector<int> TT;
        for (int i = 0; i < n; i++) {
            g.pb(TT);
        }
        g[0].pb(1);
        g[1].pb(0);
        g[1].pb(2);
        g[2].pb(1);
        g[2].pb(3);
        g[3].pb(2);
        g[0].pb(3);
        g[3].pb(0);
//        System.out.println(2 == maxMatching(g));
        cout << maxMatching(g);
    }
}mm;

int main() {
    int a, b, c, d;
    mm.main();



    return 0;
}
