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

int m[2000][2000];
vector<pii> p;
int ch[100010];
int pick[100010];

int run(int x){
    if(x == p.size()) return 1;
    if(ch[p[x].fi] and ch[p[x].se]) return 0;
    int c = rand()%2;
    if(ch[p[x].se] or ch[p[x].fi]) return run(x+1);
    else {
		if(c){
			ch[p[x].fi] = 1;
		}
		else {
			ch[p[x].se] = 1;
		}
		return run(x+1);
    }
}

int main(){
int a, b, c, d;
srand(time(0));
N = 10;
M = 20;
REP(a, M){
	c = rand()%N;
	d = rand()%N;
	while(m[c][d] or m[d][c]) c = rand()%N, d = rand()%N;
    p.pb({c, d});
    m[c][d] = m[d][c] = 1;
}
while(1){
	memset(ch, 0, sizeof(ch));
    c = run(0);
    if(c == 1) break;
}

return 0;
}
