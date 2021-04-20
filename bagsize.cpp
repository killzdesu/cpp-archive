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

int s[10010];

int main(){
int a, b, c, d, A, B;
cin >> N >> A >> B;
int mx = 0, mn = 2e9;
REP(a, N){
    cin >> s[a];
    mx = max(mx, s[a]);
}
for(a=max(A, mx);a<=B;a++){
    int cnt = 0, u = 0, left = 0;
    REP(b, N){
        if(u + s[b] > a){
            cnt++;
            left += a-u;
            u = s[b];
        }
        else {
            u += s[b];
        }
    }
    if(left < mn){
        mn = left;
        i = a;
    }
}

printf("%d", i);

return 0;
}
