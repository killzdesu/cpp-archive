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

int i, n, k, N, K;
ll M;

vector<ll> l[2], L;
vector<pair<ll, int> > s[2];

int main(){
int a, b, c, d;
ll t, sm;
cin >> N >> M;
REP(a, N){
    scanf("%I64d %d", &t, &c);
    l[c].pb(t);
    s[c].pb(mp(t, a));
    L.pb(t);
}
REP(a, 2) sort(l[a].begin(), l[a].end(), greater<ll>());
REP(a, 2) sort(s[a].begin(), s[a].end(), greater<pair<ll, int> >());
sort(L.begin(), L.end(), greater<ll>());

int lo=0, hi=L.size()+1, mi;
while (lo < hi){
    mi = lo + (hi-lo)/2;
//    printf("%d %d\n", lo, hi);
    sm = 0;
    REP(a, mi){
        sm += L[a];
    }
    if (sm >=  M){
        hi = mi;
    }
    else{
        lo = mi+1;
    }
}
//printf("%d", hi);
k = lo;

sm = 0;
ll sm2=0;
int i, j;
REP(a, l[1].size()){
    if(a) l[1][a]+=l[1][a-1];
}

if(l[1].size() < k){
    i = l[1].size();
    j = k-i;
}
else {
    i = k;
    j = 0;
}
//printf(">>> %d\n", j);
REP(a, j){
    sm2 += l[0][a];
}
while((i>0?l[1][i-1]:0) + sm2 < M){
    i--; j++;
    sm2 += l[0][j-1];
}

printf("%d %d", k, i);
//printf(" %d", j);
printf("\n");
for(a=0;a<i;a++){
    printf("%d ", s[1][a].se+1);
}
for(a=0;a<j;a++){
    printf("%d ", s[0][a].se+1);
}

return 0;
}
