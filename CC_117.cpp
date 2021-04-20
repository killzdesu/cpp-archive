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
int s[1010];
vector<int> v;
int S[100010];

int main(){
int a, b, c, d;
int T;
cin >> T;
REPI(d, T){
	cin >> N >> K;
	for(a=0;a<=K;a++) S[a] = 0;
	REP(a, N){
		scanf("%d", &s[a]);
	}
    v.clear();
    S[0] = 1;
    v.pb(0);
    REP(a, N){
        REP(b, v.size()){
        	c = (v[b]+s[a])%K;
            if(S[c] == 0){
                S[c] = 1;
                v.pb(c);
            }
        }
    }
    int mx = 0;
    i = K-1;
    while(S[i]==0) i--;
    printf("Case #%d: %d\n", d, i);
}



return 0;
}
