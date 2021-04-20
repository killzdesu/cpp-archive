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

ll P[200010];
vector<pii> v[200010];
ll T, SUM;
ll dp[200010][2][2];

ll now[2][2], tmp[2][2];

void dfs(int x, int D, int par){
    int a, b;
    REP(a, v[x].size()){
        auto u = v[x][a];
        if(u.fi == par) continue;
        if(u.se%2){
            swap(now[0][0], now[1][0]);
            swap(now[0][1], now[1][1]);
        }
        dfs(u.fi, u.se, x);
        if(u.se%2){
            swap(now[0][0], now[1][0]);
            swap(now[0][1], now[1][1]);
        }
    }
    if(P[x] > 0){
        SUM += P[x]*now[0][0];
        SUM += P[x]*now[1][1];
    }
    else {
        SUM += -P[x]*now[0][1];
        SUM += -P[x]*now[1][0];
    }
//    printf("------ %d p[%lld] d[%d] -----\n", x, P[x], D);

    now[0][(P[x]<0)] += abs(P[x]);

    {
//    for(int i=0;i<2;i++) for(int j=0;j<2;j++) tmp[i][j] = now[i][j];
//    if(D%2==0 and P[x] > 0){
//        now[0][0] += P[x];
//    }
//    else if(D%2==0 and P[x] <= 0){
//        now[0][1] += -P[x];
//    }
//    else if(D%2 and P[x] > 0){
//        swap(now[0][0], now[1][0]);
//        swap(now[0][1], now[1][1]);
//        now[1][0] += P[x];
//    }
//    else if(D%2 and P[x] <= 0){
//        swap(now[0][0], now[1][0]);
//        swap(now[0][1], now[1][1]);
//        now[1][1] += -P[x];
//    }
//    now[D%2][(P[x]>0)] += (P[x]>0?P[x]:-P[x]);
    }

//    REP(a, 2)REP(b, 2) cout << now[a][b] << " \n"[b==1];
//    REP(b, 2)REP(a, 2) cout << now[a][b] << " \n"[a==1];
}

int main(){
int a, b, c, d;
cin >> N;
cin >> P[0];
REPI(a, N-1){
    scanf("%lld %d %d", &P[a], &c, &d);
    v[c].pb({a, d});
    v[a].pb({c, d});
}
dfs(N/2, 0, -1);
cout << SUM;
return 0;
}
