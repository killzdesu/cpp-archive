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
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

int i, n, k, N, M, K;

int s[30010];
vector<int> z;
pii q[30010];

map<int, int> m;

struct Tree{
	int val;
	int lo, hi;
};


struct segment_tree{
	Tree m[100010 * 6];

	void init(int key, int lo, int hi){
		m[key].val = 2e9;
		m[key].lo = lo;
		m[key].hi = hi;
		if(lo == hi-1){
			return;
		}
		init(key*2, lo, (lo+hi)/2);
		init(key*2+1, (lo+hi)/2, hi);
	}

	void update(int key, int t, int val){
		if(m[key].lo > t or t >= m[key].hi) return;
		if(m[key].lo == m[key].hi-1){
			m[key].val = val;
			return;
		}
		update(key*2, t, val);
		update(key*2+1, t, val);
		m[key].val = min(m[key*2].val, m[key*2+1].val);
	}

	int query(int key, int lo, int hi){
		if(m[key].hi <= lo or hi <= m[key].lo) return 2e9;
		if(lo <= m[key].lo and m[key].hi <= hi) return m[key].val;
		return min(query(key*2, lo, hi), query(key*2+1, lo, hi));
	}
}sg;

typedef tree<
int, null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update> oset;

oset S;

int main(){
int a, b, c, d;
cin >> N >> K >> M;
REP(a, N) {
	scanf("%d", &s[a]);
    z.pb(s[a]);
}
REP(a, M){
	scanf("%d %d", &c, &d);
    q[a] = {c, d};
    z.pb(d);
}
compress(z);
REP(a, z.size()){
	m[z[a]] = a;
}
sg.init(1, 0, z.size());
int id;
REP(a, N){
    S.insert(s[a]);
    if(S.size() >= K){
        i = S.order_of_key(s[a]);
        for(b = max(i, K-1); b < min((int)S.size(), i+K); b++){
			c = *S.find_by_order(b);
            int val = c - *S.find_by_order((b-K+1));
            sg.update(1, m[c], val);
        }
    }
}
REP(a, M){
	if(q[a].fi == 1){
        S.insert(q[a].se);
		if(S.size() >= K){
			i = S.order_of_key(q[a].se);
			for(b = max(i, K-1); b < min((int)S.size(), i+K); b++){
				c = *S.find_by_order(b);
				int val = c - *S.find_by_order((b-K+1));
				sg.update(1, m[c], val);
			}
		}
	}
	else {
        sg.update(1, m[q[a].se], 2e9);
        i = S.order_of_key(q[a].se);
        for(b = max(i+1, K-1); b < min((int)S.size(), i+K); b++){
			c = *S.find_by_order(b);
			int val;
			if(b-K < 0) val = 2e9;
			else val = c - *S.find_by_order((b-K));
			sg.update(1, m[c], val);
        }
        S.erase(S.find(q[a].se));
	}
//    printf(":");
//    for(auto x: S) printf("%d ", x); EL;
	c = sg.query(1, 0, z.size());
	if(c > 1e9) printf("-1\n");
	else printf("%d\n", c);
}

return 0;
}
