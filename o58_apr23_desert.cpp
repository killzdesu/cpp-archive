#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin(), unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define dump(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

int i, n, k, N, M, K;
int W, H;
int s[400][400];
int qs[400][400];
int vs[310][310];

int qry(int x1, int y1, int x2, int y2){
    int T = qs[x2][y2];
    if(x1) T -= qs[x1-1][y2];
    if(y1) T -= qs[x2][y1-1];
    if(x1 and y1) T += qs[x1-1][y1-1];
    return T;
}

void solve(int x, int y){
    if(x < W or y < H or x > N or y > M) return;
    if(vs[x][y]) return ;
    if(qry(x-W+1, y-H+1, x, y) != 0) return ;
    vs[x][y] = 1;
//    printf("%d %d\n", x, y);
    int a, b;
    solve(x+1, y);
    solve(x-1, y);
    solve(x, y+1);
    solve(x, y-1);
}

int main(){
int a, b, c, d;
cin >> N >> M >> K;
REP(a, K) {
    scanf("%d %d", &c, &d);
    s[c+1][d+1] = 1;
}
REPI(a, 310) REPI(b, 310){
    qs[a][b] = s[a][b];
    qs[a][b] += qs[a-1][b];
    qs[a][b] += qs[a][b-1];
    qs[a][b] -= qs[a-1][b-1];
}
int lox, loy, hix, hiy, mix, miy;
lox = 1;
hix = N;
int mx = 0;
//while(lox < hix){
for(W = 1; W <= N; W++){
    loy = 1; hiy = M;
//    W = (lox+hix+1)/2;
    c = 0;
    while(loy < hiy){
        memset(vs, 0, sizeof(vs));
        H = (loy+hiy+1)/2;
        solve(W, H);
        if(vs[N][M]){
            mx = max(mx, W*H);
            loy = H;
            c = 1;
        }
        else {
            hiy = H-1;
        }
    }
    memset(vs, 0, sizeof(vs));
    H = loy;
    solve(W, H);
    if(vs[N][M]){
        mx = max(mx, W*H);
        c = 1;
    }
//    printf("W[%d] :%d\n", W, c);
//    if(c) lox = W;
//    else hix = W-1;
}
//W = lox;
//loy = 1; hiy = M;
//while(loy < hiy){
//    memset(vs, 0, sizeof(vs));
//    H = (loy+hiy+1)/2;
//    solve(W, H);
//    if(vs[N][M]){
//        mx = max(mx, W*H);
//        loy = H;
//        c = 1;
//    }
//    else {
//        hiy = H-1;
//    }
//}
//memset(vs, 0, sizeof(vs));
//H = loy;
//solve(W, H);
//if(vs[N][M]){
//    mx = max(mx, W*H);
//    c = 1;
//}

cout << mx;
return 0;
}
