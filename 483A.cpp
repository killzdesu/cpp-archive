#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
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
ll N, M, K;
int a, b, c, d;
cin >> N >> M;
if(M-N < 2){
    cout << -1;
    return 0;
}
if(M-N==2 and N%2==1){
    cout << -1;
    return 0;
}
K = 2*((N+1)/2);
printf("%I64d %I64d %I64d", K, K+1, K+2);

return 0;
}
