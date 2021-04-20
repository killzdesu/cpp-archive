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
int dp[400][400];
int mx[400][400];

int main(){
int a, b, c, d;
cin >> N >> M;
REP(a, M){
    scanf("%d %d", &c, &d);
    dp[c][d]++;
    mx[c][d] = max(mx[c][d], dp[c][d]);
}
for(c=2;c<=N;c++){
    for(a=1;a+c-1<=N;a++){
        for(b=a+1;b<=a+c-1;b++){
            mx[a][a+c-1] = max(mx[a][a+c-1], mx[a][b-1]+mx[b][a+c-1]+dp[a][a+c-1]);
        }
        mx[a][a+c-1] = max(mx[a][a+c-1], mx[a+1][a+c-1]);
        mx[a][a+c-1] = max(mx[a][a+c-1], mx[a][a+c-2]);
    }
}
cout << M-mx[1][N];
return 0;
}
