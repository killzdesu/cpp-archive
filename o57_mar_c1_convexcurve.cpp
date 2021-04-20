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

int dp1[5005][5005];
int dp2[5005][5005];
int s[5005];

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    dp1[a][a] = dp2[a][a] = 1;
    cin >> s[a];
}
for(a=0;a<N-2;a++){
    for(b=a+1;b<N-1;b++){
        dp1[a][b] = 1;
        for(c=b+1;c<N;c++){
            dp1[a][b] = 1;
        }
    }
}


return 0;
}
