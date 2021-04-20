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

char s[100][100];
int chk[300];

int main(){
int a, b, c, d;
cin >> N >> M;
REP(a, N) cin >> s[a];
for(a=0;a<N-1;a++){
	for(b=0;b<M-1;b++){
		fill(chk, chk+300, 0);
		chk[s[a][b]] = 1;
		chk[s[a+1][b]] = 1;
		chk[s[a][b+1]] = 1;
		chk[s[a+1][b+1]] = 1;
		if(chk['f'] and chk['a'] and chk['c'] and chk['e']) k++;
	}
}
cout << k;


return 0;
}
