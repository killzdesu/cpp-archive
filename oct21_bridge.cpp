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
int s[3010], m[3010], dp[3010];

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    scanf("%d", &c);
    s[c] = a;
}
REP(a, N){
    scanf("%d", &m[a]);
    d = 0;
    for(b=a-1;b>=0;b--){
        if(s[m[b]] < s[m[a]]) d = max(d, dp[b]);
    }
    dp[a] = d+1;
    k = max(k, dp[a]);
}
cout << k;
return 0;
}
