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

int main(){
freopen("may_jetpack-input.txt", "r", stdin);
freopen("jet.txt", "w", stdout);
int a, b, c, d;
int R, T;
cin >> T;
REPI(R, T){
	cin >> N >> K;
	REP(a, N){
		scanf("%d", &s[a]);
	}
	int p = 0;
    REP(a, N){
    	i = s[a];
		s[a] = s[a]-p;
		p = i;
    }
    sort(s, s+N, greater<int>());
    int cnt = 0;
    int can = s[0];
    a=0;
    while(a < N){
        while(a!= N-1 and s[a] == s[a+1]){
			a++;
        }
        a++;
        if(a <= K) can = s[a];
        else break;
    }
    can = max(0, can);
    printf("%d\n", can);

}



return 0;
}
