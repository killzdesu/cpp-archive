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
vector<int> prime, val;
//map<int, int> At;

int p[2000100], cnt[1000100];
ll tmp[1000000];

ll mul(int x){
    int a;
    tmp[1] = prime[x];
    for(a=2;a<=cnt[x];a*=2){
        tmp[a] = tmp[a/2]*tmp[a/2];
        tmp[a]%=M;
    }
    ll S=1;
    i = cnt[x];
    for(a/=2;a>0;a/=2){
        if(a >= i){
            S*=tmp[a];
            S%=M;
            i -= a;
        }
    }
    return S;
}

int main(){
int a, b, c, d;
cin >> N >> M;
for(a=2;a<=2*N;a++){
    if(p[a]) continue;
    prime.pb(a);
    for(b=a+a;b<=2*N;b+=a) p[b] = 1;
}
//cout << prime.size();
//for(a=0;a<prime.size();a++){
//    At[prime[a]] = a;
////    printf("%d\n", prime[a]);
//}

for(a=0;a<prime.size();a++){
    ll c = prime[a];
    ll tmp = prime[a];
//    printf("%d\n", prime[a]);
    while(c <= 2*N){
        d = (int)2*N/(int)c;
        cnt[a] += d;
//        printf("%d + %d = %d\n", prime[a], d, cnt[a]);
//        cnt[a]%=M;
        c*=tmp;
    }
    c = prime[a];
    while(c <= N){
        d = (int)2*(N/(int)c);
        cnt[a] -= d;
//        printf("%d - %d = %d\n", prime[a], d, cnt[a]);
//        cnt[a]%=M;
        c*=tmp;
    }
}
//
//for(a=0;a<prime.size();a++){
//    printf("%d:[%d]\n", prime[a], cnt[a]);
//}

ll X = 1;
ll Y = M;
for(a=0;a<prime.size();a++){
//    X*=mul(a);
    while(cnt[a]--){
        X*=prime[a];
        X%=M;
    }
}

//cout << X << "\n";

cout << (X*X)%Y;
return 0;
}
