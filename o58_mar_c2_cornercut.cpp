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
ll TP;

ll s[302][302];
ll UR[302][302], DR[302][302], UL[302][302], DL[302][302];
//ll UP[302][302][302];
//ll dpR[302][302][302];
ll dpL[310];
ll dpR[310];

ll qs(int x1, int y1, int x2, int y2){
    if(x1 > x2) swap(x1, x2);
    if(y1 > y2) swap(y1, y2);
    TP = s[x2][y2];
    if(x1) TP -= s[x1-1][y2];
    if(y1) TP -= s[x2][y1-1];
    if(x1 and y1) TP += s[x1-1][y1-1];
    return TP;
}

int main(){
freopen("asd.in", "r", stdin);
int a, b, c, d;
cin >> N >> M;
REP(a, N) REP(b, M){
    scanf("%lld", &s[a][b]);
    if(a) s[a][b] += s[a-1][b];
    if(b) s[a][b] += s[a][b-1];
    if(a and b) s[a][b] -= s[a-1][b-1];
}

ll tmp;
// ------------------UL
REP(a, N){
    REP(b, M){
        tmp = qs(0, 0, 0, 0);
        if(a) tmp = max(tmp, UL[a-1][b]);
        if(b) tmp = max(tmp, UL[a][b-1]);
        tmp = max(tmp, qs(0, 0, a, b));
        UL[a][b] = tmp;
    }
}
// ------------------UR
REP(a, N){
    for(b=M-1;b>=0;b--){
        tmp = qs(0, M-1, 0, M-1);
        if(a) tmp = max(tmp, UR[a-1][b]);
        if(b!=M-1) tmp = max(tmp, UR[a][b+1]);
        tmp = max(tmp, qs(0, b, a, M-1));
        UR[a][b] = tmp;
    }
}
// ------------------DL
for(a=N-1;a>=0;a--){
    REP(b, M){
        tmp = qs(N-1, 0, N-1, 0);
        if(a!=N-1) tmp = max(tmp, DL[a+1][b]);
        if(b) tmp = max(tmp, DL[a][b-1]);
        tmp = max(tmp, qs(a, 0, N-1, b));
        DL[a][b] = tmp;
    }
}
// ------------------DR
for(a=N-1;a>=0;a--){
    for(b=M-1;b>=0;b--){
        tmp = qs(N-1, M-1, N-1, M-1);
        if(a!=N-1) tmp = max(tmp, DR[a+1][b]);
        if(b!=M-1) tmp = max(tmp, DR[a][b+1]);
        tmp = max(tmp, qs(a, b, N-1, M-1));
        DR[a][b] = tmp;
    }
}
ll mx = -2e9;
//for(a=0;a<N-1;a++){
//    for(b=0;b<M-1;b++){
//        mx = max(mx, UL[a][b]+UR[a][b+1]+DL[a+1][b]+DR[a+1][b+1]);
//    }
//}
mx = -2e9;
REP(a, N-1) REP(c, N-1){
    fill(dpL, dpL+M+1, -2e9);
    fill(dpR, dpR+M+1, -2e9);
    REP(b, M-1){
        dpL[b] = UL[a][b]+UR[c][b+1];
        if(b) dpL[b] = max(dpL[b], dpL[b-1]);
    }
    for(b=M-2;b>=0;b--){
        dpR[b] = UL[a][b]+UR[c][b+1];
        if(b!=M-2) dpR[b] = max(dpR[b], dpR[b+1]);
    }
    for(d=0;d<M-1;d++){
        if(c > a){
            mx = max(mx, dpR[d]+DL[a+1][d]+DR[c+1][d+1]);
        }
        else if(a > c){
            mx = max(mx, dpL[d]+DL[a+1][d]+DR[c+1][d+1]);
        }
        else {
            mx = max(mx, dpL[d]+DL[a+1][d]+DR[c+1][d+1]);
            mx = max(mx, dpR[d]+DL[a+1][d]+DR[c+1][d+1]);
        }
//        if(mx == 28){
//            DB("%d %d %d\n", a, c, d);
//            DB("dpL[%d]\n", dpL[d]);
//        }
    }
}
cout << mx;
EL;
mx = -2e9;
REP(a, N-1) REP(b, M-1) REP(c, N-1) REP(d, M-1){
    if(c < a and d < b) continue;
    if(d > b and a < c) continue;
    mx = max(mx, UL[a][b]+UR[c][b+1]+DL[a+1][d]+DR[c+1][d+1]);
}

cout << mx;
return 0;
}
