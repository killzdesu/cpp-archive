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
map<ll, int> m;
int getg(ll x){
    x++;
    while(x!=1 and x%2 == 0){
		x/=2;
    }
    return (x!=1?(int)log2(x):0);
}

int main(){
//cout << getg(7);
int a, b, c, d;
cin >> K;
ll x;
while(K--){
	cin >> N;
	d = 0;
	REP(a, N){
		scanf("%lld", &x);
		for(c = 0; ; c++){
			if(getg(x-1) != c and getg(x) != c) break;
		}
        d ^= c;
	}
	printf("%d\n", (d!=0));
}



return 0;
}
