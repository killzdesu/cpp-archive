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
freopen("test_newroads.in", "w", stdout);
int a, b, c, d;
N = 50; M = 1000;
printf("%d %d\n", N, M);
REP(a, N){
    REP(b, M)
        printf("1 ");
    printf("\n");
}


return 0;
}
