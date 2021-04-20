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

int s[2010], qs[2010];
int dp[2010];

int test(int lim){
	int a, sm=0, cnt=1;
    REP(a, N){
		sm += s[a];
        if(sm > lim){
			cnt++;
			sm = s[a];
        }
    }
    return cnt <= K;
}

int getans(int lim){
	int a, sm=0, ans=0;
    REP(a, N){
        sm += s[a];
        if(sm > lim){
            sm -= s[a];
            ans = (ans|sm);
            sm = s[a];
        }
    }
    ans = (ans|sm);
    return ans;
}

int main(){
int a, b, c, d;
cin >> N >> K;
int lo=0, hi, mi;
REP(a, N){
	scanf("%d", &s[a]);
	lo = max(s[a], lo);
	qs[a] = s[a];
	if(a) qs[a] = qs[a-1]+s[a];
}
hi = qs[N-1]+1;
while(lo < hi){
    mi = (lo+hi)/2;
    c = test(mi);
    if(c == 1){
		hi = mi;
    }
    else lo = mi+1;
}
cout << getans(lo);
return 0;
}
