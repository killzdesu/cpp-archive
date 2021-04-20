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
#define ll long long

using namespace std;

int i, n, k, N, M, K;

struct Point{
    int x, y;
    Point(){};
    Point(int a, int b){
        x = a; y = b;
    }
    bool operator < (const Point &b) const{
        return y < b.y;
    }
} P[100010];;

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

    b1 = sign(pt, v1, v2) > 0.0f;
    b2 = sign(pt, v2, v3) > 0.0f;
    b3 = sign(pt, v3, v1) > 0.0f;

    return ((b1 == b2) && (b2 == b3));
}

int H[100010], hc;

int main(){
int a, b, c, d;
//cout << isLeft(Point(0,4), Point(2,4), Point(4, 4));
//cout << PointInTriangle(Point(3, 2), Point(5, 1), Point(1, 1), Point(3, 3));
cin >> N;
c = 2e9;
REP(a, N){
    scanf("%d %d", &P[a].x, &P[a].y);
    if(P[a].y < c){
        c = P[a].y;
        i = a;
    }
}
swap(P[i], P[0]);
sort(P+1, P+N, cmp);
H[hc++] = 0;
H[hc++] = 1;
for(a=2;a<N;a++){
    while(hc > 1 and isLeft(P[H[hc-2]], P[H[hc-1]], P[a])>=0){ hc--; }
    H[hc++] = a;
}
//while(hc > 1 and isLeft(P[H[hc-2]], P[H[hc-1]], P[0])>=0){ hc--; }
//cout << "----------------------\n";
//REP(a, hc){
//    printf("%d %d\n", P[H[a]].x, P[H[a]].y);
//}

//printf("%d %d\\  %d %d\\  %d %d\n", P[H[0]].x, P[H[0]].y, P[H[1]].x, P[H[1]].y, P[H[hc-1]].x, P[H[hc-1]].y);
//cout << "-------" << isLeft(P[H[0]], P[H[1]], P[H[hc-1]]) << "\n";
if(isLeft(P[H[0]], P[H[1]], P[H[hc-1]])==0){
    for(a=0;a<hc-1;a++){
        swap(H[a], H[a+1]);
    }
    hc--;
};

int mx = -2e9;
for(a=0;a<hc-2;a++){
    int cnt=0;
//    for(b=a;b<=H[a+2];b++){
        for(b=0;b<N;b++){
//        if(PointInTriangle(P[b], P[H[a]], P[H[a+1]], P[H[a+2]])){
        if(PointInTriangle(P[b], P[H[a+2]], P[H[a+1]], P[H[a]])){
            cnt++;
        }
    }
    mx = max(cnt, mx);
}
int cnt=1;
for(b=H[hc-2];b<N;b++){
    if(PointInTriangle(P[b], P[H[0]], P[H[a+1]], P[H[a]])){
        cnt++;
    }
}
mx = max(cnt, mx);

cnt=0;
for(b=0;b<N;b++){
    if(PointInTriangle(P[b], P[H[1]], P[H[0]], P[H[N-1]])){
        cnt++;
    }
}
mx = max(cnt, mx);

cout << mx;
return 0;
}
