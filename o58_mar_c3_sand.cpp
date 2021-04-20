#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#define IT iterator
#define all(x) x.begin(),x.end()
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()
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

using namespace std;

int i, n, k, N, M, K;
ll dp[4000][4000];

const int SHF = 552;

int main(){
//freopen("sand.txt", "r", stdin);
//freopen("asd.in", "r", stdin);
int a, b, c, d, x, y, v;
int Q;
//REP(a, 2390) REP(b, 2390) dp[a][b] = 0;

cin >> N >> M >> Q;
while(M--){
    scanf("%d %d %d %d", &y, &x, &v, &d);
    x+=SHF;
    y+=SHF;
    for(a=0;a<d;a++){
        ll k = v;
        K = min(K, x+y-a);
        K = min(K, x+y+a+2);
        dp[x][y-a] += k;
        dp[x-1-a][y+1] -= k;
        dp[a+x+1][y+1] -= k;
        dp[x][a+y+2] += k;
        if(a!=0){
            i = a-1;
            K = min(K, x+y-i);
            K = min(K, x+y+i+2);
            dp[x][y-i] += k;
            dp[x-1-i][y+1] -= k;
            dp[x+1+i][y+1] -= k;
            dp[x][y+2+i] += k;
        }
    }
//break;
}
// 505 502
//i = 4;
//dp[505][502-i] = 1;
//dp[505-1-i][502+1] = -1;
//dp[i+505+1][502+1] = -1;
//dp[505][i+502+2] = 1;

//for(a=0;a<=N;a++){
//    for(b=0;b<N;b++){
//        printf("%lld ", dp[a+SHF][b+SHF]);
//    }EL;
//}

for(c=0;c<4000;c++){
    for(b=0;b<=c;b++){
        a = c-b;
        dp[a][b] = dp[a][b];
        if(a and b) dp[a][b] += dp[a-1][b-1];
        if(b) dp[a][b] += dp[a+1][b-1];
        if(b>=2) dp[a][b] -= dp[a][b-2];
    }
}

//for(a=0;a<=N;a++){
//    for(b=0;b<N;b++){
//        printf("%lld ", dp[a+SHF][b+SHF]);
//    }EL;
//}

while(Q--){
    scanf("%d %d", &d, &c);
    printf("%lld\n", dp[c+SHF][d+SHF]);
}

return 0;
}
