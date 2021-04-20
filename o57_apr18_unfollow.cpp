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
int vs[310];
int m[310][310];

int dfs(int x, int T){
    if(x == T) return 1;
    for(int a=T;a<x;a++){
        if(m[x][a]){
            if(dfs(a, T) == 1) return 1;
        }
    }
    return 0;
}

int main(){
int a, b, c, d;
cin >> N >> M >> K;
REP(a, M){
    scanf("%d %d", &c, &d);
    m[c][d] = 1;
}
int r;
REP(r, K){
    scanf("%d %d %d", &i, &c, &d);
    if(i == 1){
        m[c][d] = 0;
    }
    else {
        d = 1 + (k+d)%N;
        b = dfs(d, c);
        if(b){
            k++;
            printf("y\n");
        }
        else {
            printf("n\n");
        }
    }
}


return 0;
}
