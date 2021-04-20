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

int main(){
    freopen("C:\\Users\\Jui\\Downloads\\jan_tiling-input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

int a, b, c, d;
double x, y;
int T;
cin >> T;
while(T--){
    cin >> x >> y;
    x = floor(sqrt(x));
    y = floor((y-4)/4.0);
    if(y <= 0 or x <= 0) printf("0\n");
    else printf("%.0lf\n", max(min(x, y)+2, 0.0));

}



return 0;
}
