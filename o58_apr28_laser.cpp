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

pair<Point, Point> tab[230];

Point angle(int x, int di){

    if(di == 0) return tab[x].fi;
    if(di == 2) return tab[x].se;
    if(di == 1) return Point(tab[x].fi.x, tab[x].se.y);
    if(di == 3) return Point(tab[x].se.x, tab[x].fi.y);
}

bool chk_line(int x, Point A, Point B){
    int c[4], a;
    for(a=0;a<4;a++) c[a] = isLeft(A, B, angle(x, a));
    if(c[0] == c[1] and c[1] == c[2] and c[2] == c[3]){
		return 1;
    }
    else {
        if(A.x <= tab[x].fi.x and B.x <= tab[x].fi.x){
            return 1;
        }
        if(A.x >= tab[x].se.x and B.x >= tab[x].se.x){
            return 1;
        }
        if(A.y <= tab[x].fi.y and B.y <= tab[x].fi.y){
            return 1;
        }
        if(A.y >= tab[x].se.y and B.y >= tab[x].se.y){
            return 1;
        }
        return 0;
    }
}

int main(){
int a, b, c, d;
cin >> N >> M >> n >> K;
REP(i, n){
	scanf("%d %d %d %d", &a, &b, &c, &d);
    tab[i] = {{a, b}, {c, d}};
}
while(K--){
	scanf("%d %d", &c, &d);
	int can = 0;
	Point F(c, d);
	int chk = 1;
    REP(a, n){
		chk &= chk_line(a, Point(0, 0), F);
    }
	if(chk) can = 1;
    for(a=0;a<n;a++){
		for(b=0;b<4;b++){
            chk = 1;
            for(c=0; c<n; c++){
            	if(c == a) continue;
				chk &= chk_line(c, Point(0, 0), angle(a, b));
				chk &= chk_line(c, angle(a, b), F);
            }
			if(chk) can = 1;
		}
    }


    if(can) printf("YES\n");
    else printf("NO\n");
}


return 0;
}
