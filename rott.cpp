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

int s[1000][1000];

pii run(pii p){
    int x = p.fi, y = p.se;
    if((x+y) % 2 == 1){
        if(y == 1)x++;
        else {
            x++;
            y--;
        }
    }
    else {
		if(x == 1) y++;
		else {
			y++;
			x--;
		}
    }
    return {x, y};
}

int main(){
freopen("may_rationalnum-input.txt", "r", stdin);
freopen("dd.txt", "w", stdout);
int a, b, c, d;
int x, y;
int R, T;
cin >> T;

x = 1; y = 1;
c = 1;
while(x != 1 or y != 601){
    if(__gcd(x, y) == 1) s[x][y] = c++;
    pii t = run({x, y});
    x = t.fi; y = t.se;
}

REPI(R, T){
	cin >> x >> y;
	printf("%d\n", s[x][y]);
}



return 0;
}
