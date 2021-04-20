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
int s[2000][2000];
int TP;

int qs(int x1, int y1, int x2, int y2){
    int TP = s[x2][y2];
    if(x1) TP -= s[x1-1][y2];
    if(y1) TP -= s[x2][y1-1];
    if(x1 and y1) TP += s[x1-1][y1-1];
    return TP;
}

int main(){
int a, b, c, d;
cin >> M >> N >> K;
REP(a, M){
    cin >> c >> d;
    s[c][d] = 1;
}
REP(a, N+1){
    REP(b, N+1){
        if(a) s[a][b] += s[a-1][b];
        if(b) s[a][b] += s[a][b-1];
        if(a and b) s[a][b] -= s[a-1][b-1];
    }
}
//REP(a, N){
//    REP(b, N){
//        DB("%d ", s[a][b]);
//    }
//    DB("\n");
//}

int mn = 2e9;
int lo, hi;
//DB(">> %d %d\n", s[3][1], qs(0, 1, 3, 1));
REP(a, N){
    lo = hi = 0;
    while(hi < N){
        while(lo < hi and qs(0, lo+1, a, hi) >= K) lo++;
//        if(a == 9 and hi < 4){
//            DB("%d %d: %d = %d\n", lo, hi, qs(0, lo, a, hi), (hi-lo+1)*(a+1));
//        }
        if(qs(0, lo, a, hi) >= K){
            mn = min(mn, (hi-lo+1)*(a+1));
        }
        hi++;
    }
}
cout << mn;

return 0;
}
