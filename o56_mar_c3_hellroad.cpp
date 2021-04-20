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
#define all(x) x.begin(),x.end()
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()
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

pair<int, pii> E[600000];
pair<int, pii> *it;

int head[1010];

int fh(int x){
    if(x!=head[x]) head[x] = fh(head[x]);
    return head[x];
}

int mst(int B){
    int a, sm=0, c=0;
    a = B;
    while(a < M and c!=N-1){
        if(fh(E[a].se.fi) == fh(E[a].se.se)){
            a++;
            continue;
        }
        head[fh(E[a].se.fi)] = fh(E[a].se.se);
        c++;
        sm += E[a].fi;
        if(sm > K) return 0;
        a++;
    }
    if(c == N-1) return 1;
    return 0;
}

int main(){
int a, b, c, d;
cin >> N >> K;
M = N*(N-1)/2;
REP(a, M){
    scanf("%d %d %d", &b, &c, &d);
    E[a] = mp(d, mp(b, c));
}
sort(E, E+M);
int lo = 0, hi = M-1, mi;
while(lo < hi){
//    printf("%d %d\n", lo, hi);
    mi = lo+(hi-lo+1)/2;
    REPI(a, N) head[a] = a;
    if(mst(mi) == 0){
        hi = mi-1;
    }
    else {
        lo = mi;
    }
}
cout << E[lo].fi;

return 0;
}
