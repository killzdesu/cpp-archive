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
int s[500];
char h[100010];

int main(){
int a, b, c, d;
cin >> N;
cin >> h;
REP(a, N){
    if(h[a] == 'A')s[0]++;
    if(h[a] == 'C')s[1]++;
    if(h[a] == 'G')s[2]++;
    if(h[a] == 'T')s[3]++;
}
REP(a, 4){
    k = max(s[a], k);
}
REP(a, 4){
    if(s[a] == k) i++;
}
ll P = 1;
REP(a, N){
    P*=i;
    P%=1000000007;
}
cout << P;
return 0;
}
