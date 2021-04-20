#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

int dp[100010], n, k, N;

int main(){
int a, r, b, c, s;
cin >> N;
for(r=0;r<N;r++){
    for(a=0;a<=60000;a++) dp[a] = 0;
    dp[0] = 1;
    s = 0;
    scanf("%d", &n);
    for(b=0;b<n;b++){
        scanf("%d", &c);
        s+=c;
        for(a=50000-c;a>=0;a--){
            if(dp[a]){
                dp[a+c] = 1;
            }
        }
    }
    b = 2e8;
    for(a=0;a<=s;a++){
        if(dp[a]==0) continue;
        //printf("%d %d\n", s, a);
        c = s-a-a;
        if(c<0) c*=-1;
        b = min(b, c);
    }
    printf("%d\n", b);
}


return 0;
}
