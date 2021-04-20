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
int Q;

vector<int> prime;
map<int, int> pos;
int chkp[100010];

void gen_prime(){
	int a, b;
    for(a=2;a<=100000;a++){
        if(chkp[a]) continue;
        prime.pb(a);
        for(b=a;b<=100000;b+=a) chkp[a] = 1;
    }
}

int main(){
gen_prime();
int a, b, c, d;
cin >> M >> Q;
int chk = 1;
vector<int> st;
int mx = -2e9;
if(Q == 0) goto sol0;
if(Q == 1) goto sol1;
sol0:;
printf("0");
return 0;
sol1:;
k = 3;
while(M--){
	scanf("%d %d", &c, &d);
    maxa(k, d);
	st.pb(c-d+1);
}
compress(st);
if(st[0] == 1) st.erase(st.begin());
if(st.size() == 0){printf("-1"); return 0;}
int gcd = st[0]-1;
REPI(a, st.size()-1){
    gcd = __gcd(gcd, st[a]-1);
}
//dump(gcd);
while(gcd%2 == 0) gcd /= 2;
if(gcd >= k) i++;
for(a=3;a<=gcd/k+1;a+=2) if(gcd%a==0 and gcd/a >= k) i++;
//dump(i);
printf("%d\n", i);

return 0;
}
