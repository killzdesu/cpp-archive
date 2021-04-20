#include<cstdio>
#include<stack>
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

using namespace std;

int i, n, k, N, M, K;

pair<int, int> z[100010], s[100010];

void bf(){
    int c;
    for(int a=0;a<N;a++){
        c = -2e8;
        for(int b=0;b<N;b++){
            c = max(c, z[b].se+s[a].se-(int)fabs(z[b].fi-s[a].fi));
        }
        printf("%d\n", c);
    }
}

int A[100010], B[100010];

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    scanf("%d %d", &s[a].fi, &s[a].se);
}
REP(a, N){
    scanf("%d %d", &z[a].fi, &z[a].se);
}
if(N <= 5000){
    bf();
    return 0;
}
//return 0;
//sort(s, s+N);
//sort(z, z+N);
for(a=0;a<N;a++){
    A[a] = z[a].fi+z[a].se;
    if(a) A[a] = max(A[a], A[a-1]);
//    printf("%d ", A[a]);
}
//printf("\n");
for(a=N-1;a>=0;a--){
    B[a] = z[a].se-z[a].fi;
    if(a!=N-1) B[a] = max(B[a], B[a+1]);
//    printf("%d ", B[a]);
}
//printf("\n");
b=0;
REP(a, N){
    for(;b<N and z[b].fi<=s[a].fi;b++);
    if(b == 0) c = 0;
    else c = s[a].se-s[a].fi+A[b-1];
    if(b >=N) d = 0;
    else d = s[a].se+s[a].fi+B[b];
    //S.push(max(c, d));
    //printf(" Choose %d : %d\n", c, d);
    printf("%d\n", max(c, d));
}
return 0;
}
