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
    double x, y;
    Point(){};
    Point(double a, double b){
        x = a; y = b;
    };
};

int isleft(Point A, Point B, Point C){
    double k;
    k = (B.x-A.x)*(C.y-A.y);
    k -= (C.x-A.x)*(B.y-A.y);
    if(0.000001 > k and k > -0.000001) return 0;
    if(k > 0){
        return 1;
    }
    if(k < 0) return -1;
}

int onseg(Point p, Point q, Point r)
    {
        if(q.x <= max(p.x,r.x) and q.x >= min(p.x,r.x) and q.y <= max(p.y,r.y) and q.y >= min(p.y,r.y))
        {
            return 1;
        }

        return 0;
    }

int intersect(Point A1, Point A2, Point B1, Point B2){
    int dA1, dA2, dB1, dB2;
    dA1 = isleft(B1, B2, A1);
    dA2 = isleft(B1, B2, A2);
    dB1 = isleft(A1, A2, B1);
    dB2 = isleft(A1, A2, B2);

    if(dA1 == dA2 and dA1 == 0 and dB1 == dB2 and dB1 == 0){
        if(onseg(A1, B1, A2)) return 1;
        if(onseg(A1, B2, A2)) return 1;
        if(onseg(B1, A1, B2)) return 1;
        if(onseg(B1, A2, B2)) return 1;
        return 0;
    }
    return ((dA1 != dA2) and (dB1 != dB2));
}

int main(){
int a, b, c, d;


return 0;
}
