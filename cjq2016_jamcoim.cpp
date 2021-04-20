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
unordered_map<ll, ll> p;

ll change_base(ll x, ll y){
	if(x == 10) return y;
	ll tmp = 0, m = 1;
	while(y != 0){
		tmp += (y%10)*m;
		m *= x;
		y/=10;
	}
	return tmp;
}

int main(){
int c, d;
ll a, b;
cin >> M;
printf("Case #1: \n");
cin >> N >> K;
int cnt = 0;
return 0;
for(a=2;a<=1111111111111111;a++){
	if(p[a] > 0) continue;
    p[a] = -1;
    for(b=a+a;b<=1111111111111111;b+=a){
        p[b] = a;
    }
}
printf("done prime");
for(a=1000000000000001; cnt != 50; a+=10){
    int chk = 1;
    if(p[a] == -1) continue;
    for(b = 2; b <= 9; b++){
        if(p[change_base(b, a)] == -1){
            chk = 0;
            break;
        }
    }
    if(chk){
        cnt++;
        printf("%lld", a);
        for(b=2;b<=10;b++){
            printf(" %lld", p[change_base(b, a)]);
        }
        printf("\n");
    }
}


return 0;
}
