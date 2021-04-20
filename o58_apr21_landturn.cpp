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

int s[302][302];
int dpu[302][302], dpd[302][302], dpl[302][302], dpr[302][302];
int QS[302][302];

int qry(int x1, int y1, int x2, int y2){
    int T = QS[x2][y2];
    if(x1) T -= QS[x1-1][y2];
    if(y1) T -= QS[x2][y1-1];
    if(x1 and y1) T += QS[x1-1][y1-1];
    return T;
}

int main(){
int a, b, c, d;
cin >> N >> M >> K;
int mx = 0;
REP(a, N) REP(b, M){
    scanf("%d", &s[a][b]);
    QS[a][b] = s[a][b];
    if(a) QS[a][b] += QS[a-1][b];
    if(b) QS[a][b] += QS[a][b-1];
    if(a and b) QS[a][b] -= QS[a-1][b-1];
}
//REP(a, N) REP(b, M){
//    cout << QS[a][b] << " \n"[b==M-1];
//}

REP(a, N){
    int mn = 0;
    int qs = 0;
    REP(b, M){
        qs += s[a][b];
        maxa(dpl[a][b], qs-mn);
        mina(mn, qs);
    }
    mn = qs = 0;
    for(b=M-1;b>=0;b--){
        qs += s[a][b];
        maxa(dpr[a][b], qs-mn);
        mina(mn, qs);
    }
}

REP(b, M){
    int mn = 0;
    int qs = 0;
    REP(a, N){
        qs += s[a][b];
        maxa(dpd[a][b], qs-mn);
        mina(mn, qs);
    }
    mn = qs = 0;
    for(a=N-1;a>=0;a--){
        qs += s[a][b];
        maxa(dpu[a][b], qs-mn);
        mina(mn, qs);
    }
}

if(K == 0) goto runK0;
if(K == 1) goto runK1;
if(K == 2) goto runK2;
runK2:;
REP(a, N){
    for(b=0;b<M;b++){
        for(c=b+1;c < M;c++){
            int T = qry(a, b, a, c);
            if(a!=N-1 and c-b >= 2)maxa(mx, T+dpu[a+1][b]+dpu[a+1][c]);
            if(a and a!=N-1)maxa(mx, T+dpd[a-1][b]+dpu[a+1][c]);
            if(a and a!=N-1)maxa(mx, T+dpu[a+1][b]+dpd[a-1][c]);
            if(a and c-b >= 2)maxa(mx, T+dpd[a-1][b]+dpd[a-1][c]);
//            if(mx == 85 and !i){
//                dump(T);
//                printf("%d %d %d %d\n", a, b, a, c);
//                i = 1;
//            }
        }
    }
}
REP(a, M){
    for(b=0;b<N;b++){
        for(c=b+1;c < N;c++){
            int T = qry(b, a, c, a);
            if(a and c-b >= 2)maxa(mx, T+dpl[b][a-1]+dpl[c][a-1]);
            if(a and a!=M-1)maxa(mx, T+dpl[b][a-1]+dpr[c][a+1]);
            if(a and a!=M-1)maxa(mx, T+dpr[b][a+1]+dpl[c][a-1]);
            if(a!=M-1 and c-b >=2)maxa(mx, T+dpr[b][a+1]+dpr[c][a+1]);
        }
    }
}
runK1:;
REP(a, N){
    int sm = 0;
    int t;
    REP(b, M){
        sm += s[a][b];
        t = sm;
        maxa(mx, sm);
        maxa(mx, sm+dpu[a+1][b]);
        maxa(mx, sm+dpd[a-1][b]);
        sm = max(0, sm);
    }
}
runK0:;
REP(a, N){
    int sm = 0;
    REP(b, M){
        sm += s[a][b];
        maxa(mx, sm);
        sm = max(0, sm);
    }
}
REP(b, M){
    int sm = 0;
    REP(a, N){
        sm += s[a][b];
        maxa(mx, sm);
        sm = max(0, sm);
    }
}
cout << mx;

return 0;
}
