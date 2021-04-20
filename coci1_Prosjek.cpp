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

int i, n, k, N, M, K;

int main(){
int a, b, c, d;
int s[1000];
cin >> N;
REP(a, N){
    cin >> s[a];
    k = s[a]*(a+1);
    if(a) k-=s[a-1]*a;
    printf("%d ", k);}



return 0;
}
