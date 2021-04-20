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
k = 2e9;
cin >> N >> M;

    for(a=0;a<N;a++){
        b = N-a*2;
        if(b < 0) break;
        if((a+b)%M == 0) k =min(k, a+b);
    }
if(k > 2e8)printf("-1");
else cout << k;


return 0;
}
