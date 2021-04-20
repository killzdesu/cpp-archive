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

using namespace std;

int i, n, k, N, M, K;

int main(){
int a, b, c, d;
int R;
cin >> R;
while(R--){
    scanf("%d/%d", &N, &M);
    while(N!=M){
        if(N>M){
            printf("R");
            N-=M;
            swap(N, M);
        }
        else {
            printf("L");
            swap(N, M);
            N--;
        }
    }
    printf("\n");
}



return 0;
}
