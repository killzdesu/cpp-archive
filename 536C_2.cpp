#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin, unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;

int i, n, k, N, M, K;

struct Point{
    int x, y, id;
    Point(){};
    Point(int a, int b){
        x = a; y = b;
    }
    bool operator < (const Point &b) const{
        return y < b.y;
    }
} P[100010];

double getm(int a, int b){
    return (P[b].y-P[a].y+0.0000001)/(P[b].x-P[a].x+0.0000001);
}

bool cmp(Point a, Point b){
    return atan(((double)a.x-P[0].x+0.0000001)/((double)a.y-P[0].y+0.0000001)) < atan(((double)b.x-P[0].x+0.0000001)/((double)b.y-P[0].y+0.0000001));
}

int isLeft( Point p1, Point p2, Point p3 )
{
    return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
}

float sign (Point p1, Point p2, Point p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool PointInTriangle (Point pt, Point v1, Point v2, Point v3)
{
    bool b1, b2, b3;

    b1 = sign(pt, v1, v2) < 0.0f;
    b2 = sign(pt, v2, v3) < 0.0f;
    b3 = sign(pt, v3, v1) < 0.0f;

    return ((b1 == b2) && (b2 == b3));
}

double dist(Point a, Point b){
    double ss = (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    return sqrt(ss);
}

int H[100010], hc;
map<int, int> m[10004];

int main(){
int a, b, c, d;
cin >> N;
int smin=2e9, smax=-2e9;
REP(a, N){
    scanf("%d %d", &P[a].x, &P[a].y);
    P[a].id = a+1;
    smin = min(smin, P[a].x);
    smax = max(smax, P[a].x);
}
P[N] = Point(smin, 0);
P[N].id = -1;
P[N+1] = Point(smax, 0);
P[N+1].id = -1;
swap(P[N], P[0]);
sort(P+1, P+N+2, cmp);
H[hc++] = 0;
H[hc++] = 1;
for(a=2;a<N+2;a++){
    while(hc > 1 and isLeft(P[H[hc-2]], P[H[hc-1]], P[a])>0){ hc--; }
    H[hc++] = a;
}
vector<int> ans;
REP(a, hc){
    ans.pb(P[H[a]].id);
////    printf("%d\n", P[H[a]].id);

}
sort(ALL(ans));
REP(a, ans.size()){
    if(ans[a] > 0)
        printf("%d ", ans[a]);
}

return 0;
}
