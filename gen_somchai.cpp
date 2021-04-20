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

const ll mod = 1000000007;

int i, n, m, k, N, M, K;
char s[1010][1010];
int vs[1010][1010];
pii tr[100010];
pii tar;
ll cnt;


void dfs(int x, int y, int C){
    if(x < 1 or y < 1 or x > n or y > m) return;
    if(vs[x][y]) return;
    vs[x][y] = 1;
    tr[C] = mp(x, y);
    if(tar == mp(x, y)){
		if(C == n*m-1){
//			printf("-----------\n");
//			for(int a=0;a<n*m;a++) printf("%d %d\n", tr[a].fi, tr[a].se);
			cnt++;
			cnt %= mod;
		}
		vs[x][y] = 0;
		return;
    }
    dfs(x-1, y, C+1);
    dfs(x+1, y, C+1);
    dfs(x, y-1, C+1);
    dfs(x, y+1, C+1);
    vs[x][y] = 0;
}

struct node{
	int n, m;
	int x, y;
	int tx, ty;
};

pii nx;

vector<pii> F;

node fp(int x, int y){
    int l, r, l2, r2;
    int w, h;
    int a, b, c;
    int mx, mn;
    // find l
    mx = x;
    for(l = y-1; s[x][y] != '#'; l--){
        int c = 0;
        for(h = x; s[h][l] != '#'; h++){
			for(a=l;a<=y;a++) if(s[h][a] == '#') break;
			if(a <= y) break;
        }
        h--;
        if(mx <= h) mx = h;
        else break;
    }
    l++;
    // find r
    for(r = y+1; s[x][y] != '#'; r++){
        for(h = x; s[h][r] != '#'; h++){
			for(a=y;a<=r;a++) if(s[h][a] == '#') break;
			if(a <= r) break;
        }
        h--;
        if(mx <= h) mx = h;
        else break;
    }
    r--;

    mn = x;
    for(l2 = y-1; s[x][y] != '#'; l2--){
        int c = 0;
        for(h = x; s[h][l] != '#'; h--){
			for(a=l2;a<=y;a++) if(s[h][a] == '#') break;
			if(a <= y) break;
        }
        h++;
        if(mn >= h) mn = h;
        else break;
    }
    l2++;
    // find r
    for(r2 = y+1; s[x][y] != '#'; r2++){
        for(h = x; s[h][r] != '#'; h--){
			for(a=y;a<=r2;a++) if(s[h][a] == '#') break;
			if(a <= r2) break;
        }
        h++;
        if(mn >= h) mn = h;
        else break;
    }
    r2--;

	l = -2e9, r = 2e9;
	for(h = mn;h <= mx; h++){
		for(a=y;;a--){
			if(s[h][a] == '#') break;
		}
        a++;
        l = max(l, a);
        for(a=y;;a++){
			if(s[h][a] == '#') break;
		}
        a--;
        r = min(r, a);
	}

    for(a=y;a<=r;a++){
		for(b=y;b<=a;b++){
            if(s[mn-1][b]=='.' or s[mx+1][a]=='.') break;
		}
        if(b <= a) break;
    }
    r = a-1;

    for(a=y;a>=l;a--){
		for(b=y;b>=a;b--){
            if(s[mn-1][b]=='.' or s[mx+1][a]=='.') break;
		}
        if(b >= a) break;
    }
    l = a+1;


//    dump(mn);
//    dump(mx);
//    dump(l);
//    dump(r);

	F.clear();
    for(a=l;a<=r;a++) if(s[mn-1][a] == '.') F.pb({mn-1, a});
    for(a=l;a<=r;a++) if(s[mx+1][a] == '.') F.pb({mx+1, a});
    for(a=mn;a<=mx;a++) if(s[a][l-1] == '.') F.pb({a, l-1});
    for(a=mn;a<=mx;a++) if(s[a][r+1] == '.') F.pb({a, r+1});
    pii out;

//    printf("***: ");
//    for(auto q: F) printf("[%d, %d] ", q.fi, q.se);EL;
    if(F.size() == 1) out = {-1, -1};
	else {
		b = 0;
		c = abs(F[0].fi-x)+abs(F[0].se-y);
		if(c == 1) b = 1;
		nx = F[b];
        if(F[b].fi < mn) F[b].fi = mn;
        if(F[b].fi > mx) F[b].fi = mx;
        if(F[b].se < l) F[b].se = l;
        if(F[b].se > r) F[b].se = r;
        out = {F[b].fi-mn+1, F[b].se-l+1};
	}
    node T = {r-l+1, mx-mn+1, x-mn+1, y-l+1, out.fi, out.se};
    return T;
}

int main(){
freopen("somchai/1.txt", "r", stdin);
int a, b, c, d;
cin >> N >> M;
REP(a, N) cin >> s[a];
//n = 4, m = 4;
//tar = {4, 3};
//dfs(1, 1, 0);
//dump(cnt);
//auto T = fp(1, 3);
int x, y;
x = 1, y = 3;
ll sm = 1;
node T;
while(1){
    T = fp(x, y);

	printf("%d %d : %d %d -> %d %d\n", T.n, T.m, T.x, T.y, T.tx, T.ty);
	printf("%d %d\n", nx.fi, nx.se);
	if(T.tx == -1 or T.ty == -1) break;
    tar = {T.tx, T.ty};
    n = T.n; m = T.m;
    cnt = 0;
    dfs(T.x, T.y, 0);
    sm *= cnt;
    sm %= mod;
    x = nx.fi;
    y = nx.se;
}
cout << sm;

return 0;
}
