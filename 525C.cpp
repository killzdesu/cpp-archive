#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#define DB if(DBG)printf
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

int DBG=1;
int i, n, k, N, M, K;
int cnt[1000100];
int dp[1000100];
int m[1000100];

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    scanf("%d", &c);
    cnt[c]++;
}
REPI(a, 1000000){
    if(cnt[a]+cnt[a+1] >= 2) dp[a] = a;
}
for(a=1000000;a>0;a--){
    m[a] = max(dp[a], m[a+1]);
}
ll mx = 0;
//for(a=3;a<8;a++) printf("%d ", m[a]);EL;
REPI(a, 1000000){
    if(cnt[a]+cnt[a+1] < 2) continue;
    mx = max(mx, (ll)a*(ll)m[a+2]);
//    printf("%d: %d %d\n", a, mx, m[a+2]);
//    if(a < 8)printf("%d: %d\n", a, mx);
    if(cnt[a]+cnt[a+1] >= 2 and cnt[a+1]-max(2-cnt[a], 0)+cnt[a+2] >= 2) mx = max(mx, (ll)a*(ll)(a+1));
//    if(a < 8)printf("%d: %d\n", a, mx);
    if(cnt[a]+cnt[a+1] >= 4) mx = max(mx, (ll)a*(ll)a);
//    if(a < 8)printf("%d: %d\n", a, mx);
}
cout << mx;
return 0;
}
