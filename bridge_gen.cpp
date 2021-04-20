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

vector<int> prime;
map<int, int> pos;
int chkp[100010];

void gen_prime(){
	int a, b;
    for(a=2;a<=100000;a++){
        if(chkp[a]) continue;
        prime.pb(a);
        for(b=a;b<=100000;b+=a) chkp[b] = 1;
    }
}

pair<ll, ll> gen(ll x){
	pair<ll, ll> A(-1, -1);
	ll a;
    while(1){
		ll fac = rand()%1000+1;
        A.fi = fac*x;
        for(a = (rand()%1000+1)*x;;a++){
            if(__gcd(A.fi, a) == x) break;
        }
        if(__gcd(A.fi, a) == x) break;
    }
    return {A.fi, a};
}

int lucky(int x){
    while(x != 0){
        if(x % 10 != 7 and x % 10 != 4) return 0;
        x /= 10;
    }
    return 1;
}

int head[100010];

int fh(int x){
	if(head[x] != x) head[x] = fh(head[x]);
    return head[x];
}

int main(){
for(i=11;i<=11;i++){
srand(time(0));
string S = ".txt";
string test;
stringstream ss;
n = 10;
ss << i;
test = "bridge/"+ss.str();
//freopen((test+S).c_str(), "r", stdin);
freopen((test+".in"+S).c_str(), "w", stdout);
int a, b, c, d;
gen_prime();
pair<ll, ll> p;
N = 100;
REPI(a, N) head[a] = a;
printf("%d\n", N);
REP(a, N-1){
    c = rand()%N+1;
    while(1){
		k = rand()%N+1;
		for(d=k; d<=N; d++){
			if(fh(d)!=fh(c)){
				goto BB;
			}
		}
		for(d=k; d>0; d--){
			if(fh(d)!=fh(c)){
				goto BB;
			}
		}
    }
    BB:;
    printf("%d %d ", c, d);
    head[fh(c)] = fh(d);
	b = rand()%2;
	if(b == 0) printf("4\n");
	else printf("1\n");
}

}
return 0;
}
