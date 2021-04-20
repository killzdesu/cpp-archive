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

vector<pii> v;

int main(){
int a, b, c, d;
cin >> N >> M;
REP(a, M){
	scanf("%d", &c);
	scanf("%d", &d);
    v.pb(mp(c, d));
}
int mx = 0;
REP(a, v.size()-1){
    int df = abs(v[a+1].se-v[a].se);
    c = abs(v[a+1].fi-v[a].fi);
    if(c < df) {
		cout << "IMPOSSIBLE";
		return 0;
    }
    mx = max(mx, max(v[a+1].se, v[a].se) + (c-df)/2);
}
mx = max(mx, v[0].fi-1+v[0].se);
mx = max(mx, N-v[v.size()-1].fi+v[v.size()-1].se);
cout << mx;
return 0;
}
