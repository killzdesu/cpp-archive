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
int L, W;
int s[100010];

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    cin >> s[a];
    if(s[a] == 10){
        L++;
        if(a!=0 and s[a-1]==13){
            W++;
        }
    }
    if(s[a] == 13){
        M++;
    }
}
W++; L++; M++;
printf("%d %d %d", W, L, M);

return 0;
}
