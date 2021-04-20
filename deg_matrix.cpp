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

double eps = 1e-14;

int main(){
int a, b, c, d;
double m1, M1, M2, m2, m3, M3, M4, m4;
double A, B, C, D;

double lo = 0, hi = 5e18, mi;

cin >> A >> B >> C >> D;

while(hi-lo > eps){
	mi = lo+(hi-lo)/2.0;
	m1 = A - mi;
	M1 = A + mi;
	m2 = B - mi;
	M2 = B + mi;
	m3 = C - mi;
	M3 = C + mi;

	m4 = min(min(min(M2*m3/m1, M2*m3/M1), min(M2*M3/m1, M2*M3/M1)), min(min(m2*m3/m1, m2*m3/M1),min(m2*M3/m1, m2*M3/M1)));
	M4 = max(max(max(m2*m3/M1, m2*m3/m1),max(m2*M3/m1, m2*M3/M1)), max(max(M2*M3/m1, M2*M3/M1), max(M2*m3/m1, M2*m3/M1)));

	if(M4 < D - mi || D + mi < m4){
		lo = mi;
	} else {
		hi = mi;
	}
}
printf("%.13lf", hi);

return 0;
}
