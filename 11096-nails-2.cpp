#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ull long long

using namespace std;

struct Point {
    double x, y;
    Point(){};
    Point(double a, double b){
        x = a; y = b;
    };
    double cross(Point a, Point b) {
        return (this->x - a.x)*(b.y - a.y) - (this->y - a.y)*(b.x - a.x);
    }

    bool right(Point a, Point b) {
        return cross(a, b) > 0;
    }

    bool left(Point a, Point b) {
        return cross(a, b) < 0;
    }

    double dist(Point b) {
        return sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y));
    }

    bool operator <(const Point& p) const {
        if (this->x != p.x) return this->x < p.x;
        return this->y < p.y;
    }
};

int convexHull(Point* P, int n, Point* S) {
    sort(P, P+n);

    int m=0;
    for(int i=0; i<n; i++) {
        while(m >= 2 and S[m-1].left(S[m-2], P[i])) m--;
        S[m++] = P[i];
    }
    m--;

    for(int i=n-1, k=m; i >= 0; i--) {
        while(m >= k+2 and S[m-1].left(S[m-2], P[i])) m--;
        S[m++] = P[i];
    }
    m--;

    return m;
}


Point P[120], S[120];

int main() {
//    cout << Point(5, 5).right(Point(1, 1), Point(2, 2));
    int tt, a; cin >> tt;
    while(tt--) {
        double r, sm=0;
        int n;
        cin >> r >> n;
        REP(a, n){
            cin >> P[a].x >> P[a].y;
        }
        int m = convexHull(P, n, S);
        REP(a, m){
            sm += S[a].dist(S[(a+1)%m]);
        }
        printf("%.5lf\n", max(sm, r));
    }
}
