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

vector<pii> v[100010];
int G[100010];
double sm;
int cnt[15];

void dfs(int x, int par, int c, double di){
    if(G[x] == c){
        sm += di;
//        k++;
    }
    for(auto u:v[x]){
        if(u.fi == par) continue;
        dfs(u.fi, x, c, (double)u.se+di);
    }
}

int main(){
int a, b, c, d;
cin >> N >> M;
REPI(a, N){
    scanf("%d", &G[a]);
    cnt[G[a]]++;
}
REPI(a, N-1){
    scanf("%d %d %d", &c, &d, &b);
    v[c].pb({d, b});
    v[d].pb({c, b});
}
cin >> M;
if(M <= 1000)goto sol100;
sol100:;
int passs;
while(M--){
    scanf("%d", &c);
    if(c == 1){
        scanf("%d", &c);
        if(cnt[c] <= 1){
            printf("%.9f\n", 0.0);
            continue;
        }
        sm = 0;
        REPI(a, N){
            if(G[a] != c) continue;
            dfs(a, -1, c, 0);
        }
        sm/=2.0;
        double xx = cnt[c]*(cnt[c]-1)/2;
        printf("%.9f\n", sm/xx);
//        cout << sm << "<\n";
    }
    else{
        scanf("%d %d", &c, &d);
        cnt[G[c]]--;
        G[c] = d;
        cnt[d]++;
    }
}
return 0;
}
