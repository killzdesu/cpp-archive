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

int i, n, k, N, M, K, mn;

vector<int> ans, A;
int deg[10010];
pii e[100010];
int u[100010];
int ps[10010];
vector<int> v[10010];

int rec(int x, int cnt){
    int a, b, c;
    if(x == M+1){
        if(cnt <= K){
            if(cnt < mn){
                mn = cnt;
                A.clear();
                REPI(a, N){
                    if(ps[a])A.pb(a);
                }
            }
            return 1;
        }
        return 0;
    }
    if(ps[e[x].fi] or ps[e[x].se])return rec(x+1, cnt);

    if(cnt == mn) return 0;

    ps[e[x].fi] = 1;
    c = rec(x+1, cnt+1);
    ps[e[x].fi] = 0;

    ps[e[x].se] = 1;
    c = rec(x+1, cnt+1);
    ps[e[x].se] = 0;
//    return c;
}

int main(){
int a, b, c, d;
K = 20;
scanf("%d %d", &N, &M);
REPI(a, M){
    scanf("%d %d", &c, &d);
    e[a] = mp(c, d);
    deg[c]++;
    deg[d]++;
}
mn = K+1;
for(a=1;a<=N;a++){
    if(deg[a] > K){
        ans.pb(a);
        ps[a] = 1;
    }
}

rec(1, (int)ans.size());
printf("%d\n", A.size());
//REP(a, ans.size()){
//    printf("%d\n", ans[a]);
//}
REP(a, A.size()){
    printf("%d\n", A[a]);
}

return 0;
}
