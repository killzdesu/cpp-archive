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
vector<int> s[100], t[100];
long long x[1000100];

int main(){
const int mod = 57885161;
int a, b, c, d;
int T, R;
ll A, B, C;
freopen("may_compareword2-input.txt", "r", stdin);
freopen("compr.txt", "w", stdout);
cin >> T;
REP(R, T){
	cin >> N;
	cin >> A >> B >> C;
	REP(a, 52) s[a].clear();
	REP(a, 52) t[a].clear();
	for(a=0;a<N;a++){
		if(a == 0){
			x[a] = C;
		}
		else {
			x[a] = (x[a-1]*A+B) % mod;
		}
        c = x[a]%52;
        s[c].pb(a);
	}
	cin >> M;
	cin >> A >> B >> C;
	for(a=0;a<M;a++){
		if(a == 0){
			x[a] = C;
		}
		else {
			x[a] = (x[a-1]*A+B) % mod;
		}
        c = x[a]%52;
        t[c].pb(a);
	}
    ll sum = 0;
    for(a=0;a<52;a++){
		for(i=0;i<t[a].size();i++){
			sum += distance(s[a].begin(), upper_bound(ALL(s[a]), N-M+t[a][i]));
			sum -= distance(s[a].begin(), lower_bound(ALL(s[a]), t[a][i]));
		}
    }
    cout << sum << "\n";
}



return 0;
}
