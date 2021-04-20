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

int i, n, k, N, M, K, T;
pii s[100010];

bool cmp(pii a, pii b){
    if(a.fi == b.fi) return a.se > b.se;
    return a.fi < b.fi;
}

int main(){
int a, b, c, d;
cin >> N >> T;
REP(a, N){
    scanf("%d %d", &c, &d);
    s[a].fi = c;
    s[a].se = c+d*T;
}
sort(s, s+N, cmp);
int mx = 0, mxi = -1;
int cnt = 1;
mx = s[0].se;
mxi = 0;
//printf("MX: %d\n", mx);
//printf("%d %d\n", s[0])
for(a=1;a<N;a++){
    if(s[a].se == mx){
        if(s[a].fi == s[mxi].fi){
            cnt++;
        }
    }
    else if(s[a].se > mx){
        mx = s[a].se;
        mxi = a;
        cnt++;
    }
}
cout << cnt;
return 0;
}
