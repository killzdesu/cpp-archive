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
int a, b, c, d;
freopen("Hi.txt", "w", stdout);
N=30;
cout << 30 << endl;

//REPI(a, N-1) printf("%d %d\n", a, a+1);

for(a=1;a<=N;a++){
    if(a*2<=N) printf("%d %d\n", a, a*2);
    if(a*2+1<=N) printf("%d %d\n", a, a*2+1);
}



return 0;
}
