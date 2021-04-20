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

const double eps = 1e-15;
const double pi = acos(-1);

struct Point{
    ll x, y;
    Point(){}
    Point(int a, int b){x=a; y=b;}

    Point operator - (const Point &b) const{
        return Point(x-b.x, y-b.y);
	}
	ll operator * (const Point &b) const
	{
		return x*b.y-y*b.x;
	}
}p[2010];

ll isLeft(Point a, Point b, Point c){
	return (b-a)*(c-a);
}

vector<int> v[2010];
int cnt;
deque<Point> Q;
int turn;

int chk_line(Point a, Point b, Point c){
    if(isLeft(a, b, c) != 0) return 1;
    if(b.x-a.x > 0 and c.x-a.x < 0) return 0;
    if(b.x-a.x < 0 and c.x-a.x > 0) return 0;
    if(b.y-a.y > 0 and c.y-a.y < 0) return 0;
    if(b.y-a.y < 0 and c.y-a.y > 0) return 0;
    return 1;
}

void dfs(int x, int par, int inv){
    int a, c, pushed = 0;
    c = Q.size();
    if(Q.size() < 2 or inv*isLeft(Q[c-2], Q[c-1], p[x]) >= 0){
		Q.pb(p[x]);
		c++;
		pushed = 1;
    }
    else {
		return;
    }
    if(Q.size() >= 3 and pushed){
		c = Q.size();
		if(inv*isLeft(Q[c-3], Q[c-2], Q[c-1]) > 0) turn++;
        if(inv*isLeft(Q[c-2], Q[c-1], Q[0]) >= 0 and inv*isLeft(Q[c-1], Q[0], Q[1]) >= 0 and turn > 0
//			and chk_line(Q[c-2], Q[c-1], Q[0]) and chk_line(Q[c-1], Q[0], Q[1])
		){
            cnt++;
        }
        else {
            Q.pop_back();
            return;
        }
    }
    for(auto u : v[x]){
    	if(u == par) continue;
		dfs(u, x, inv);
    }
    if(pushed){
		c = Q.size();
		if(c >= 3 and inv*isLeft(Q[c-3], Q[c-2], Q[c-1]) > 0) turn--;
        Q.pop_back();
    }
}

int main(){
int a, b, c, d;
cin >> N;
REPI(a, N){
	scanf("%lld %lld", &p[a].x, &p[a].y);
}
REP(a, N-1){
	scanf("%d %d", &c, &d);
    v[c].pb(d);
    v[d].pb(c);
}

REPI(a, N){
	b = cnt;
	turn = 0;
	Q.clear();
    dfs(a, -1, 1);
//    printf("%d: %d\n", a, cnt-b);
//    dfs(a, -1, -1);
}
cout << cnt;
return 0;
}
