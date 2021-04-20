#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#define fi first
#define se second

using namespace std;

int i, n, k, N, M, K;

int main(){
int a, b, c, d;
int x=0, y=0;
char s[1000];
scanf("%s", s);
k = strlen(s);
for(a=0;a<k;a++){
    if(s[a] == 'N') y++;
    if(s[a] == 'E') x++;
    if(s[a] == 'W') x--;
    if(s[a] == 'S') y--;
    if(s[a] == 'Z') x=y=0;
}
printf("%d %d", x, y);

return 0;
}
