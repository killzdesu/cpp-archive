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
int s[100010], chk[10];

int main(){
int a, b, c, d;
cin >> N;
fill_n(s, N+10, 2e8);
s[N] = 0;
for(;N>1;N--){
    d = N;
    fill_n(chk, 8, 0);
    while(d){
        chk[d%10]=1;
        d/=10;
    }
    for(a=2;a<6 and a<N;a++){
        if(N%a==0 or chk[a]) continue;
        s[N-a] = min(s[N-a], s[N]+1);
    }
}
if(s[1] < 2e7) cout << s[1];
else cout << -1;


return 0;
}
