#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iostream>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define pb push_back

using namespace std;

int i, n, k, N, M, K;

int main(){
int a, b, c, d;
int mx, my, nx, ny;
mx = my = 2e9;
nx = ny = 0;
cin >> N;
REP(a, N){
    cin >> c >> d;
    mx = min(mx, c);
    my = min(my, d);
    nx = max(nx, c);
    ny = max(ny, d);
}
cout << max((mx-nx)*(mx-nx), (my-ny)*(my-ny));


return 0;
}
