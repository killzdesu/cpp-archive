#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin(), unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define dump(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

int i, n, k, N, M, K;

const ll mod = 1000000009;

struct tree{
	ll val;
	int lo, hi;
	int flag;
};

ll pow2[100010];
int P[20][80000];

struct segment_tree{
	tree m[80010*6];

	void inherit(int key){
		if(m[key].flag == 0)return ;
        m[key].val *= pow2[m[key].flag];
        m[key].val %= mod;
        if(m[key].lo == m[key].hi-1){
			m[key].flag = 0;
			return;
        }
        m[key*2].flag += m[key].flag;
        m[key*2+1].flag += m[key].flag;
        m[key].flag = 0;
	}

	void init(int key, int lo, int hi){
		m[key].lo = lo;
		m[key].hi = hi;
		m[key].flag = 0;
		if(lo == hi-1){
			m[key].val = 1;
			return ;
		}
		init(key*2, lo, (lo+hi)/2);
		init(key*2+1, (lo+hi)/2, hi);
		m[key].val = m[key*2].val + m[key*2+1].val;
		m[key].val %= mod;
	}

	void update(int key, int lo, int hi){
		inherit(key);
		if(m[key].lo >= hi or lo >= m[key].hi) return;
		if(lo <= m[key].lo and m[key].hi <= hi){
            m[key].flag++;
            inherit(key);
			return;
		}
		update(key*2, lo, hi);
		update(key*2+1, lo, hi);
		m[key].val = m[key*2].val + m[key*2+1].val;
        m[key].val %= mod;
	}

	int query(int key, int lo, int hi){
		if(m[key].hi <= lo or hi <= m[key].lo) return 0;
		if(lo <= m[key].lo and m[key].hi <= hi) return m[key].val;
		return (query(key*2, lo, hi) + query(key*2+1, lo, hi)) % mod;
	}
}sg;

vector<int> v[80010];
int cnum, chead[80010], cid[80010], cpos[80010];
int H[80010], stree[80010];

void dfs(int x, int par, int D){
    stree[x] = 1;
    H[x] = D;
    P[0][x] = par;
    for(int u: v[x]){
		if(u == par) continue;
        dfs(u, x, D+1);
        stree[x] += stree[u];
    }
}

void hld(int x, int par){
	if(chead[cnum] == -1) chead[cnum] = x;
    cid[x] = cnum;
    cpos[x] = i++;

    int mx = -1;
    for(int u: v[x]){
		if(u == par) continue;
        if(mx == -1 or stree[mx] < stree[u]){
			mx = u;
        }
    }

    if(mx != -1) hld(mx, x);

    for(int u: v[x]){
		if(u == par or u == mx) continue;
        cnum++;
        hld(u, x);
    }
}

int LCA(int p, int q){
    if(H[p] < H[q]) swap(p, q);
    int a;
    for(a=18;a>=0;a--){
        if(H[p]-(1<<a) >= H[q]) p = P[a][p];
    }
    if(p == q) return p;
    for(a=18;a>=0;a--){
        if(P[a][p] != -1 and P[a][p] != P[a][q]){
            p = P[a][p];
            q = P[a][q];
        }
    }
    return P[0][p];
}

void update(int p, int q){
	int cp, cq = cid[q];
    while(1){
		cp = cid[p];
        if(cp == cq){
			if(p == q) break;
			sg.update(1, cpos[q]+1, cpos[p]+1);
//			printf("update %d %d\n", q, p);
			return;
        }
        sg.update(1, cpos[chead[cp]], cpos[p]+1);
        p = P[0][chead[cp]];
    }
}

int main(){
int a, b, c, d;
pow2[0] = 1;
REPI(a, 100001) pow2[a] = (2*pow2[a-1]) % mod;
cin >> N;
REP(a, N-1){
	scanf("%d %d", &c, &d);
    v[c].pb(d);
    v[d].pb(c);
}
REP(a, N) P[0][a] = -1;
REP(a, N) chead[a] = -1;
sg.init(1, 0, N);

dfs(N/2, -1, 1);
hld(N/2, -1);

REPI(a, 18){
    REP(b, N){
		if(P[a-1][b] != -1){
			P[a][b] = P[a-1][P[a-1][b]];
		}
    }
}

//REP(a, N) printf("%2d ", a); EL;
//REP(a, N) printf("%2d ", cid[a]); EL;
//REP(a, N) printf("%2d ", chead[cid[a]]); EL;

cin >> M >> c;
M += c;
while(M--){
    scanf("%d", &c);
    if(c == 1){
		printf("%lld\n", sg.query(1, 0, N) % mod);
    }
    else {
		scanf("%d %d", &c, &d);
        b = LCA(c, d);
        sg.update(1, cpos[b], cpos[b]+1);
        update(c, b);
        update(d, b);
    }
}

return 0;
}
