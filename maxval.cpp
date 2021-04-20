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

long long s[1000010];

int main(){
int a, b, c, d;
cin >> N >> K;
REPI(a, N){
    scanf("%d", &s[a]);
    s[a]+=s[a-1];
}
long long mx = -2e10;
for(a=K;a<=N;a++){
    mx = max(mx, s[a]-s[a-K]);
}
cout << mx;
return 0;
}
