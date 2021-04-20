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
vector<int> mod[100010];
int s[100010];
int dp[100010];
int *p;

int main(){
int a, b, c, d;
cin >> M >> N;
REP(a, N){
    scanf("%d", &s[a]);
    mod[s[a]%M].pb(a);
}
int st;
k = 0;
int now;
now = M+1;
REP(a, N){
    if(s[a] < now){
        continue;
    }
    else {
        k++;
        while(s[a] >= now) now+=M;
    }
}
dp[1] = k;
i = k;
for(st=2;st<=M;st++){
    k = dp[st-1];
    for(a=0;a<mod[st-1].size();a++){
        c = s[mod[st-1][a]];
        if(mod[st-1][a]==0 or s[mod[st-1][a]-1]<c-M+1){
            k++;
//            printf("@%d  add %d\n", st, c);
        }
        if(mod[st-1][a]==N-1 or s[mod[st-1][a]+1]>c+M-1){
            k--;
//            printf("@%d  remove %d\n", st, c);
        }
//        else if(mod[st-1][a]!=0 and s[mod[st-1][a]-1]>=c-M+1 and mod[st-1][a]!=N-1 and s[mod[st-1][a]+1]==c+M){
////            printf("@%d  remove* %d\n", st, c);
//            k--;
//        }
    }
    dp[st] = k;
    i = min(i, k);
}
printf("%d\n", i);
REPI(a, M){
    if(dp[a] == i) printf("%d ", a);
}

return 0;
}
