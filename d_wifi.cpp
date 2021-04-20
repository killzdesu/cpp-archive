#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define pb push_back

using namespace std;

int i, n, k, N, M, K;
int P1, P2, SAM, EVE, D;
double prob;
char s1[100000];
char s2[100000];
int chk[1000];

void run(int x){
    if(x == i){
        int sm=0;
        for(int a=0;a<i;a++){
            sm+=chk[a];
        }
        if(sm == K)EVE++;
        SAM++;
        return;
    }
    chk[x] = -1;
    run(x+1);
    chk[x] = 1;
    run(x+1);
}

int main(){
int a, b, c, d;
scanf("%s", s1);
k = strlen(s1);
for(a=0;a<k;a++){
    if(s1[a] == '+')P1++;
    if(s1[a] == '-')P1--;
}
scanf("%s", s2);
for(a=0;a<k;a++){
    if(s2[a] == '+')P2++;
    else if(s2[a] == '-')P2--;
    else i++;
}
K = fabs((P1-P2));
if(i<K or (i-K)%2!=0){
    printf("0.00");
    return 0;
}
run(0);
//printf("> %d %d %d\n", EVE, SAM, K);
if(EVE == SAM) printf("1.0");
else printf("%.10lf", (double)EVE/(double)SAM);


return 0;
}
