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
string s;

int main(){
		freopen("C:\\Users\\Jui\\Downloads\\B-large.in", "r", stdin);
	freopen("B-out.out", "w", stdout);
int a, b, c, d;
cin >> M;
REPI(d, M){
	cin >> s;
	int cnt = 0;
    REP(a, s.length()-1){
        if(s[a]!=s[a+1]) cnt++;
    }
    if(s[s.length()-1] == '-') cnt++;
	printf("Case #%d: %d\n", d, cnt);
}



return 0;
}
