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

int i, n, k, N, M, K, H, L;

int s[5010];

int main(){
int a, b, c, d;
cin >> H >> L >> N;
REP(a, N){
    cin >> c;
    s[c]++;
}
i=0;
for(a=0;a<=H;a++){
    if(s[L+a] > i) i = s[L+a];
}
cout << i;
return 0;
}
