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

int i, n, k, N, M, K, ef;

int s[70010];
int root[80010];
int last;

struct tree{
	int cnt;
	ll sm;
    int l, r;
    tree(){}
}v[2000010];

vector<int> z;
map<int, int> m;

int new_node(int x){
	last++;
	v[last] = v[x];
    return last;
}

int insert(int x, int t, int lo, int hi){
    if(t < lo or t >= hi) return x;
//    printf("Node %d: %d %d\n", x, lo, hi);
    x = new_node(x);
    if(t == lo and hi-lo == 1){
		v[x].cnt++;
        v[x].sm += z[t-1];
        return x;
    }
    int mi = lo+(hi-lo)/2;

    v[x].l = insert(v[x].l, t, lo, mi);
    v[x].r = insert(v[x].r, t, mi, hi);

	v[x].cnt = v[v[x].l].cnt + v[v[x].r].cnt;
	v[x].sm = v[v[x].l].sm + v[v[x].r].sm;
	return x;
}

int query(int l, int r, int k, int lo, int hi)
{
//	printf("%d %d %d\n", lo, hi, k);
//	char cc[100];
//	gets(cc);
    if(v[r].cnt-v[l].cnt == 1 and k == 1 and hi-lo == 1){
        return lo;
    }
    int mi = lo+(hi-lo)/2;
	int diff = v[v[r].l].cnt-v[v[l].l].cnt;
//	printf("> %d\n", diff);
    if(diff < k){
        return query(v[l].r, v[r].r, k-(diff), mi, hi);
    }
    else {
        return query(v[l].l, v[r].l, k, lo, mi);
    }
}

ll query_sum(int x, int t, int lo, int hi){
	int mi = lo+(hi-lo)/2;
    if(t <= lo) return 0;
    if(hi <= t) return v[x].sm;
    return query_sum(v[x].l, t, lo, mi) + query_sum(v[x].r, t, mi, hi);
}

int rev[100010];

ll qs[100010];

int main(){
int a, b, c, d;
cin >> N >> M >> ef;
//if(ef) return 0;
REP(a, N){
	scanf("%d", &s[a]);
	qs[a] = s[a];
	if(a) qs[a] += qs[a-1];
	z.pb(s[a]);
}
sort(ALL(z));
REP(a, z.size()){
    m[z[a]] = a+1;
}
for(a=0;a<N;a++){
	rev[s[a]] = a+1;
}

for(a=1;a<=N;a++){
    root[a] = insert(root[a-1], m[s[a-1]], 1, 100100);
//    printf("insert %d at %d\n", s[a], m[s[a-1]]);
}

ll pc = 0;

REP(i, M){
    scanf("%d %d", &c, &d);
    if(ef == 1){
		c ^= pc;
		d ^= pc;
    }
    c--;
    b = query(root[c], root[d], (d-c)/2+1, 1, 100100);
//    printf("%d: %d\n", b, z[b-1]);
//	dump(rev[b]);
    ll sm = 0;
//    ll sm2 = qs[d-1];
//    if(c!=0) sm2 -= qs[c-1];
    sm += query_sum(root[d], 100010, 1, 100100);
    sm -= query_sum(root[c], 100010, 1, 100100);
    sm -= query_sum(root[d], b, 1, 100100)*2;
    sm += query_sum(root[c], b, 1, 100100)*2;
//	dump(sm2);
    printf("%lld\n", sm);
    pc = sm;
}


return 0;
}
