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

int i, n, k, N, M, K, z[3005][3005];
int m[3001][3001];

int sigma(int s[][3005], int H, int W, int x, int y){
    int sm = 0;
    sm = s[x+H-1][y+W-1];
    if(x) sm-=s[x-1][y+W-1];
    if(y) sm-=s[x+H-1][y-1];
    if(x and y) sm+=s[x-1][y-1];
    return sm;
}

int rectangle(int R, int C, int H, int W, int Q[3001][3001]){
    int a, b, c, d;

    int lo = 1, mi, hi = R*C+1;
    while(lo < hi){
        mi = (lo+hi)/2;
        REP(a, R)REP(b, C){
            if(Q[a][b] > mi) z[a][b] = 1;
            else if(Q[a][b] == mi) z[a][b] = 0;
            else z[a][b] = -1;
        }
        REP(a, R){
            REP(b, C){
                if(a)z[a][b]+=z[a-1][b];
                if(b)z[a][b]+=z[a][b-1];
                if(a and b)z[a][b]-=z[a-1][b-1];
            }
        }
        c = 2e9;
        REP(a, R-H+1) REP(b, C-W+1){
            c = min(sigma(z, H, W, a, b), c);
        }
        if(c == 0) return mi;
        if(c < 0){
            hi = mi;
        }
        else {
            lo = mi+1;
        }
    }
    return lo;
}

//int main(){
//int a, b, c, d, H, W;
//cin >> N >> M >> H >> W;
//REP(a, N){
//    REP(b, M){
//        cin >> m[a][b];
//    }
//}
//cout << rectangle(N, M, H, W, m);
//
//
//return 0;
//}
