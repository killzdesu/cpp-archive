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

pii px[100010];
pii py[100010];
pii t[100010];

bool cmp(pii x, pii y){
    return x.se < y.se;
}

ll diff(pii p[], int x, int y){
    return ((long long)(p[x].fi-p[y].fi)*(p[x].fi-p[y].fi))+((long long)(p[x].se-p[y].se)*(p[x].se-p[y].se));
}

ll cp(int lo, int hi){
    int mi = lo+(hi-lo)/2;
    if(lo == hi-1){
        return (ll)2e17;
    }
    if(lo == hi-2){
        if(py[lo].se > py[lo+1].se) swap(py[lo], py[lo+1]);
        return (ll)diff(px, lo, lo+1);
    }
    ll d = min(cp(lo, mi), cp(mi, hi));

    //sort(py+lo, py+hi, cmp);
    int i=lo, j=mi, cnt=0;
    while(i < mi and j < hi){
        if(py[i].se < py[j].se){
            t[cnt++] = py[i++];
        }
        else {
            t[cnt++] = py[j++];
        }
    }
    while(i < mi){
        t[cnt++] = py[i++];
    }
    while(j < hi){
        t[cnt++] = py[j++];
    }
    for(i=lo;i<hi;i++) py[i] = t[i-lo];


    for(int a=lo;a<hi;a++){
        for(int b=1;b<=5 and a+b < hi;b++){
            d = min(diff(py, a, a+b), d);
        }
    }
    return d;
}

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    scanf("%d %d", &px[a].fi, &px[a].se);
}
sort(px, px+N);
REP(a, N) py[a] = px[a];
cout << cp(0, N);
return 0;
}
