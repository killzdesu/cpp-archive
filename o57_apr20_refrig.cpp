#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#define DB if(DBG)printf
#define IT iterator
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

using namespace std;

int DBG=1;
int i, n, k, N, M, K;
ll s[100010];

bool check(ll x){
    int a;
    ll cnt=0;
    REP(a, N){
        if(s[a]-x < 1)cnt += x+1-s[a];
        if(cnt > x) return 0;
    }
    if(cnt > x) return 0;
    return 1;
}

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    scanf("%lld", &s[a]);
}

ll lo=0, hi=2000000000000000, mi;
while(lo < hi){
    mi = lo + (hi-lo+1)/2;
    c = check(mi);
    if(c) lo = mi;
    else hi = mi-1;
}
cout << lo+1;

return 0;
}
