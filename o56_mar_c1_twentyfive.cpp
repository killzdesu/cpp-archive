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
vector<int> v[310];
int m[310][310];
int C[310];

int color(int x){
    int a, b, c, chk = 0;
    REPI(c, 4){
        chk = 0;
        REP(a, v[x].size()){
            if(C[v[x][a]] == c){
//                printf("for %d c[%d] found %d same\n",x , c, v[x][a]);
                chk = 1;
                break;
            }
        }
        if(chk) continue;
        C[x] = c;
        break;
    }
}

int main(){
int a, b, c, d;
cin >> N;
REPI(a, N){
    cin >> c;
    REP(b, c){
        scanf("%d", &d);
        m[a][d] = 1;
        m[d][a] = 1;
    }
}
REPI(a, N)REPI(b, N){
    if(m[a][b] == 0){
        if(a!=b);
        v[a].pb(b);
    }
}

REPI(a, N){
//    printf("color %d ----\n",a );
    color(a);
}
//REPI(a, N) printf("%d ", C[a]);
//printf("\n");

REPI(c, 4){
    d = 0;
    REPI(a, N){
        if(C[a] == c) d++;
    }
    if(d >= (double)N/4.0){
        break;
    }
}
printf("%d\n", d);
REPI(a, N) if(C[a] == c)printf("%d ", a);

return 0;
}
