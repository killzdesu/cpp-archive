#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#include<ctime>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back

using namespace std;

int i, n, k, N, M, K;
double cnt;

int main(){
int a, b, c, d;
//srand(2);
d=100000;
k = d;
while(d--){
    a = b = -1;
    c = 0;
    while(a!=6 or a != b){
        b = a;
        a = rand()%6+1;
        c++;
    }
    cnt += c;
}
cnt/=k;
cout << cnt;

return 0;
}
