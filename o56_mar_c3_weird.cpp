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
#include<cassert>
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
        if(y!=b.y) return y < b.y;
        return x < b.x;
    }
} P[100010], T[100010];

ll isLeft( Point p1, Point p2, Point p3 )
{
    return ((ll)p2.x - p1.x)*((ll)p3.y - p1.y) - ((ll)p2.y - p1.y)*((ll)p3.x - p1.x);
}


int H[100010], hc;
int A1, A2;
vector<int> ans;
map<Point, int> m;

int main(){
int a, b, c, d;
//cout << isLeft(Point(0,0), Point(1,0), Point(2, -1));
//cout << PointInTriangle(Point(3, 2), Point(5, 1), Point(1, 1), Point(3, 3));
cin >> N;
c = 2e9;
REP(a, N){
    scanf("%d %d", &P[a].x, &P[a].y);
}
for(a=0;a<N-2;a++){
    if(isLeft(P[a], P[a+1], P[a+2]) <=0){
        ans.pb(a+1);
    }
}

pii tmp;
int ba, aa;
if(ans.size() == 1){
    A1 = ans[0];
    int B, A;
    if(A1 == 0){
        B = N-1;
        A = 1;
    }
    else if(A1 == N-1){
        B = N-2;
        A = 0;
    }
    else {
        B = A1-1;
        A = A1+1;
    }
    for(a=0;a<N;a++){
        if(A1 == a or B == a or A == a) continue;
        if(isLeft(T[B], T[A1], T[a]) >= 0 and isLeft(T[a], T[A1], T[A]) >= 0) break;
    }
    printf("%d %d", min(A1, a)+1, max(A1, a)+1);
}
else if(ans.size() == 0){
    cout << "1 3";
}
else {
    A1 = ans[0];
    A2 = ans[1];
    if(A1 > A2) swap(A1, A2);
    printf("%d %d", A1+1, A2+1);
}
//cout << hc;

return 0;
}
