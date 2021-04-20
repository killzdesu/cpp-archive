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
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define pb push_back

using namespace std;

char S[1000010], ss;
int cnt[1000010][30];
int i, n, k, N, M, K;

int main(){
int a, b, c, d;
unsigned long long N, M, C, D, E, K;
cin >> N;
scanf("%s", S);
K = strlen(S);
REP(a, K){
    cnt[a][S[a]-'A']++;
}
cin >> M;
REP(i, M){
    scanf("%I64u %c", &C, &ss);
    D = C-1;
    C %= K;
    D %= K;
    C = C*D/2;
    C %= K;
    printf("> %I64u\n", C);
}


return 0;
}
