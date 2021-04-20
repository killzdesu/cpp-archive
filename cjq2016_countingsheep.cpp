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

int i, n, k, M, K, cnt;
ll N;
int chk[20];

int main(){
	freopen("C:\\Users\\Jui\\Downloads\\A-large.in", "r", stdin);
	freopen("A-s-out.out", "w", stdout);
int b, c, d;
ll a;
char S[100];
cin >> M;
REPI(d, M){
	cin >> N;
	REP(b, 10) chk[b] = 0;
	cnt = 0;
	ll lim = N*100000;
    for(a=N;cnt != 10 and a < lim ;a+=N){
        sprintf(S, "%lld", a);
        for(b=0;b<strlen(S);b++){
			if('0' <= S[b] and S[b] <= '9' and chk[S[b]-'0'] == 0){
				chk[S[b]-'0'] = 1;
				cnt++;
			}
        }
    }
    a-=N;
	printf("Case #%d: ", d);
	if(cnt == 10) printf("%lld", a);
    else printf("INSOMNIA");
	printf("\n");
}



return 0;
}
