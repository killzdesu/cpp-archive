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

pii s[200010];
bool cmp(pii a, pii b){
    return a.se < b.se;
}

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    scanf("%d %d", &c, &d);
    s[a].fi = c-d;
    s[a].se = c+d;
}
sort(s, s+N, cmp);
k = -2e9;
REP(a, N){
    if(s[a].fi >= k){
        i++;
        k = s[a].se;
    }
}
cout << i;
return 0;
}
