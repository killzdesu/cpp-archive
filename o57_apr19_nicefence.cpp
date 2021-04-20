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
char s[6][120];
ll dp[104][1200];
int v[6][120];

//int rec(int x)

int main(){
int a, b, c, d;
cin >> M >> N;
REP(a, N) scanf("%s", s[a]);
REP(a, N){
    REP(b, M){
        if(s[a][b] == '\\'){
            v[a+1][b+1] += 1;
        }
        if(s[a][b] == '/'){
            v[a][b+1] += 2;
        }
    }
}

N++;
int MX = (1<<(2*N));
int cn[6], cp[6], chk, ma;
vector<int> u;
REP(a, MX){
    chk = 1;
    REP(c, N){
        cn[c] = ((a>>(2*c)))%4;
    }
    REP(c, N-1){
        if(cn[c]==cn[c+1])chk = 0;
    }
    if(chk)u.pb(a);
}

REP(a, u.size()) dp[0][u[a]] = 1;

int mA, mB;

REPI(i, M){
//    printf("--------------------%d\n", i);
        REP(a, MX){
        mA = a;
        chk = 1;
        REP(c, N){
            cn[c] = ((mA>>(2*c)))%4;
            if(c) if(cn[c] == cn[c-1]){
                chk = 0;
            }
        }
        if(chk == 0)continue;
        REP(b, MX){
            mB = b;
            chk = 1;
//            printf("AT %d FROM %d\n", mA, mB);
            REP(c, N){
                cp[c] = ((mB>>(2*c)))%4;
                if(c) if(cp[c] == cp[c-1]){
                    chk = 0;
                    break;
                }
            }
            REP(c, N){
                if(cp[c] == cn[c]){
                    chk = 0;
                    break;
                }
                if(v[c][i]&1 and cp[c-1] == cn[c]){
                    chk = 0;
                    break;
                }
                if(v[c][i]&2 and cp[c+1] == cn[c]){
                    chk = 0;
                    break;
                }
            }
            if(chk == 0) continue;
            dp[i][mA] += dp[i-1][mB];
            dp[i][mA] %= 135211;
//            printf("+= %d\n", dp[i-1][mB]);
        }
//        printf("sum %d\n", dp[i][mA]);
    }
}
ll sm = 0;
REP(a, u.size()){
    sm += dp[M][u[a]];
    sm %= 135211;
}
cout << sm;
return 0;
}
