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
char s1[200010], s2[200010];
int u1[1010], u2[1010];


int main(){
int a, b, c, d;
cin >> N;
cin >> s1 >> s2;
int cnt = 0;
REP(a, N){
    if(s1[a] != s2[a]){
        u1[s1[a]] = 1;
        u2[s2[a]] = 1;
        cnt++;
//        printf("%d")
    }
}
REP(a, 500){
    if(u1[a] and u2[a]){
        K = a;
        k++;
    }
}
if(k == 0 or cnt < 2){
    printf("%d\n", cnt);
    printf("-1 -1");
    return 0;
}
if(k == 1)goto jui1;
if(k >= 2)goto jui2;
jui1:;
printf("%d\n", cnt-1);
i = -1;
REP(a, N) if(s1[a]!=s2[a] and s1[a] == K) break;
REP(b, N) if(s1[b]!=s2[b] and s2[b] == K) break;
printf("%d %d\n", a+1, b+1);

return 0;
jui2:;
i = 0;
int k1, k2;
k = 0;
printf("%d\n", cnt-2);
REP(a, 500){
    if(u1[a] and u2[a]){
        k++;
        if(k == 1)k1 = a;
        if(k == 2)k2 = a;
    }
    if(k == 2)break;
}
//printf("%c %c\n", k1, k2);
REP(a, N){
    if(s1[a] == k1 and s2[a] == k2) break;
}
printf("%d ", a+1);
REP(a, N){
    if(s1[a] == k2 and s2[a] == k1) break;
}
printf("%d", a+1);
return 0;
}
