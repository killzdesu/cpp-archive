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

int i, n, k, N, M, K;

struct fenwick{
    int m[2*200010], N;

    void init(int n){
        N = n;
    }

    void update(int x, int val){
        while(x <= N){
            m[x] += val;
            x += (x&-x);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0){
            sum += m[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    int query_r(int idx, int idy) {
        return query(idy)-query(idx-1);
    }


};

vector<pii> v[200010];
int h[200010], dis[200010];

void dfs(int x, int val, int head){
//    printf("%d: %d\n", x, val);
    dis[x] = val;
    h[x] = head;
    for(int a=0;a<v[x].size();a++){
        dfs(v[x][a].fi, val+v[x][a].se, head);
    }
}

int main(){
int a, b, c, d;
fenwick f;
cin >> N >> K >> M;
f.init(K+2);
REPI(a, K){
    scanf("%d", &c);
    f.update(a, c);
}
for(;a<=N;a++){
    scanf("%d %d", &c, &d);
    v[c].pb(mp(a, d));
}
int r;

REPI(a, K){
//    printf("Add %d\n", a);
    dfs(a, 0, a);
}

//for(a=K+1;a<=N;a++){
//    printf("%d ", dis[a]);
//}printf(" --\n");
//for(a=K+1;a<=N;a++){
//    printf("%d ", h[a]);
//}printf(" --\n");

int A, B;

REP(r, M){
    scanf("%d %d %d", &b, &c, &d);
    if(b == 1){
        k = dis[c] + dis[d];
        if(h[c] == h[d]){
            k = fabs(dis[c]-dis[d]);
            printf("%d\n", k);
            continue;
        }
        c = h[c];
        d = h[d];
        if(c > d) swap(c, d);
//        printf("%d -> ", k);
        //k += min(f.query_r(c, d-1), 0*(f.query_r(d, N)+f.query_r(1, c-1)));
        A = f.query_r(c, d-1);
        B = f.query(K)-A;
//        printf("%d %d: ", A, B);
        k += min(A, B);
        printf("%d\n", k);
    }
    else {
        f.update(c, d-f.query_r(c, c));
    }
}

return 0;
}
