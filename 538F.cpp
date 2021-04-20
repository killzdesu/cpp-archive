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

struct fenwick{
	int m[2*200010];

	void update(int x, int val){
		while(x <= 200010){
			m[x] += val;
			x += (x&-x);
		}
	}

	int query(int idx) {
		int sum = 0;
		while (idx > 0){
			sum += m[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}
}F;

pii s[200010];
map<int, int> m;
vector<int> z;
vector<int> p[200010];

int ans[200010];

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    scanf("%d", &s[a].fi);
	s[a].se = a;
}

sort(s, s+N);
int lo, hi;
REP(a, N){
	int v = s[a].se+1;
    for(k=1;k<=N-1;k++){
        lo = k*(v-1)+2;
        hi = k*(v)+1;
        if(hi > N) hi =N;
        if(lo > N) break;
        ans[k] += F.query(hi) - F.query(lo-1);
    }
    F.update(s[a].se+1, 1);
//    REPI(b, N) printf("%d ", F.m[b]); EL;
}
REPI(a, N-1) printf("%d ", ans[a]);
return 0;
}
