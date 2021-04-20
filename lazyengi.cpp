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
vector<pair<int, pii> > v[1010];
int dist[2][1010];
int vs[1010];
//int od[1010][1010];

priority_queue<pair<int, pii>, vector<pair<int, pii> >, greater<pair<int, pii> > > Q;

void dijk(int lim){
	while(!Q.empty()) Q.pop();
	int a;
    REP(a, 1001) dist[0][a] = dist[1][a] = 2e8;
    REP(a, 1001) vs[a] = 0;
    Q.push(mp(0,mp(1,1)));
    while(!Q.empty()){
		pair<int, pii> T = Q.top(), u;
		Q.pop();
//        if(vs[T.se.fi]) continue;
		if(dist[T.se.se%2][T.se.fi] <= T.fi) continue;
        vs[T.se.fi] = 1;
        dist[T.se.se%2][T.se.fi] = T.fi;
        if(dist[0][N] < 2e8) break;
        for(a=0;a<v[T.se.fi].size();a++){
			u = v[T.se.fi][a];
			if(u.se.se > lim) continue;
            Q.push(mp(T.fi+u.se.fi, mp(u.fi, T.se.se+1)));
        }
    }
}

int main(){
int a, b, c, d;
cin >> N >> M;
REP(a, M){
    scanf("%d %d %d", &c, &d, &b);
    v[c].pb(mp(d,mp(b, a+1)));
    v[d].pb(mp(c,mp(b, a+1)));
}
dijk(M);
k = dist[0][N];
int lo = 1, hi = M, mi;
while(lo < hi){
	mi = (lo+hi)/2;
	dijk(mi);
	if(dist[0][N] == k){
        hi = mi;
	}
    else lo = mi+1;
}
printf("%d %d", lo, k);

return 0;
}
