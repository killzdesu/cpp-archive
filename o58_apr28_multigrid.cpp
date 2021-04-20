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
vector<int> v[120000];
int ma[200][200];
int vs[200000];

int __buildin_ctz(int x){
	int a;
    for(a=0;a<=K;a++){
        if(((1<<a) & x) != 0) break;
    }
    return a;
}

void build_graph(int n){
    int a, b, c, d;
    i = 0;
    REP(a, n+1) REP(b, n+1) ma[a][b] = i++;
    REP(a, n+1) REP(b, n+1){
        for(c=0; c<=__buildin_ctz(a); c++){
			d = (1 << c);
            if(a-d >= 0) v[ma[a][b]].pb(ma[a-d][b]);
            if(a+d <= n) v[ma[a][b]].pb(ma[a+d][b]);
        }
        for(c=0; c<=__buildin_ctz(b); c++){
			d = (1 << c);
            if(b-d >= 0) v[ma[a][b]].pb(ma[a][b-d]);
            if(b+d <= n) v[ma[a][b]].pb(ma[a][b+d]);
        }
    }
}

typedef pair<int, pii> pip;

priority_queue<pii, vector<pii>, greater<pii> > Q;

map<pii, int> m;
int qq;

int main(){
int a, b, c, d;
cin >> K >> qq;
n = (1 << K);
if(K > 7) return 0;
build_graph(n);
pii t;
//REP(a, n+1){
//	REP(b, n+1){
//		printf("%d: ", ma[a][b]);
//		for(auto x: v[ma[a][b]]){
//			printf("%d ", x);
//		}EL;
//	}
//}
//return 0;
while(qq--){
	REP(a, 100000) vs[a] = 0;

	cin >> a >> b >> c >> d;

    while(!Q.empty()) Q.pop();

    Q.push(mp(0, ma[c][d]));

    while(!Q.empty()){
        t = Q.top();
		Q.pop();
        if(vs[t.se]) continue;
        vs[t.se] = 1;
        if(t.se == ma[a][b]) break;
        for(auto u: v[t.se]){
			Q.push({t.fi+1, u});
        }
    }
    printf("%d\n", t.fi);
}

return 0;
}
