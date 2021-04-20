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

pii p[100010], i;
vector<ll> Lup, Ldown, Rup, Rdown;

bool cmp2(pii a, pii b){
    return a.se < b.se;
}

int main(){
int a, b, c, d;
int T;
ll sm, mx;
ll l, r;
cin >> T;
while(T--){
    cin >> N >> M >> K;

    sm = 0;

    REP(a, K){
        scanf("%d %d", &p[a].fi, &p[a].se);
    }
    sort(p, p+K, cmp2);

    Lup.clear();
    Ldown.clear();
    Rup.clear();
    Rdown.clear();


    sm += mx;
    printf("%d\n", sm);
}

return 0;
}
