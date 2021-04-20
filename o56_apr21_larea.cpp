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
int s[301][301];
int qs[301][301];
int qs2[301][301];
//int l_mx[301][301], r_mx[301][301], l_mn[301][301], r_mn[301][301], d_mx[301][301], u_mx[301][301];
int DL[301][301], DR[301][301], UL[301][301], UR[301][301], U_mn[301][301];

int QS(int x1, int y1, int x2, int y2){
    int s = qs[x2][y2];
    if(x1) s-=qs[x1-1][y2];
    if(y1) s-=qs[x2][y1-1];
    if(x1 && y1) s+=qs[x1-1][y1-1];
    return s;
}

int main(){
int a, b, c, d;
cin >> N >> M;
REP(a, N) REP(b, M) scanf("%d", &s[a][b]);
REP(a, N){
    REP(b, M){
        qs[a][b] = s[a][b];
        if(a)qs[a][b] += qs[a-1][b];
        if(b)qs[a][b] += qs[a][b-1];
        if(a && b)qs[a][b] -= qs[a-1][b-1];
    }
}
REP(a, N) REP(b, M) DR[a][b] = DL[a][b] = UR[a][b] = UL[a][b] = -2e8;
//printf("%d %d %d %d --- \n", qs[2][0], qs[1][0]);
REP(a, M){
    for(b=a;b<M;b++){
        int min_range = 0, min_at = 0;
        for(c=0;c<N;c++){
            if(c > 0){
                if(QS(min_at, a, c-1, b) < 0){
                    min_range += QS(min_at, a, c-1, b);
                    min_at = c;
                }
            }
            UR[c][a] = max(UR[c][a], QS(0, a, c, b)-min_range);
        }
    }
}

REP(a, M){
    for(b=0;b<=a;b++){
        int min_range = 0, min_at = 0;
        for(c=0;c<N;c++){
            if(c > 0){
                if(QS(min_at, b, c-1, a) < 0){
                    min_range += QS(min_at, b, c-1, a);
                    min_at = c;
                }
            }
            UL[c][a] = max(UL[c][a], QS(0, b, c, a)-min_range);
        }
    }
}

REP(a, M){
    for(b=a;b<M;b++){
        int min_range = 0, min_at = N-1;
        for(c=N-1;c>=0;c--){
            if(c < N-1){
                if(QS(c+1, a, min_at, b) < 0){
                    min_range += QS(c+1, a, min_at, b);
                    min_at = c;
                }
            }
            DR[c][a] = max(DR[c][a], QS(c, a, N-1, b)-min_range);
        }
    }
}

REP(a, M){
    for(b=0;b<=a;b++){
        int min_range = 0, min_at = N-1;
        for(c=N-1;c>=0;c--){
            if(c < N-1){
                if(QS(c+1, b, min_at, a) < 0){
                    min_range += QS(c+1, b, min_at, a);
                    min_at = c;
                }
            }
            DL[c][a] = max(DL[c][a], QS(c, b, N-1, a)-min_range);
        }
    }
}

int mx = 0;

REP(a, N) REP(b, M){
    if(b!=N-1)mx = max(mx, UL[a][b]+UR[a][b+1]);
    if(b!=N-1)mx = max(mx, DL[a][b]+DR[a][b+1]);
    if(a!=M-1)mx = max(mx, UL[a][b]+DL[a+1][b]);
    if(a!=M-1)mx = max(mx, UR[a][b]+DR[a+1][b]);
}
cout << mx;
return 0;
}
