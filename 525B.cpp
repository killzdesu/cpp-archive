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
char s[200010];
int t[200020];

int main(){
int a, b, c, d;
scanf("%s", s+1);
N = strlen(s+1);
cin >> M;
while(M--){
    scanf("%d", &c);
    t[c]+=1;
    t[N-c+2]-=1;
}
REPI(a, N+2) t[a] += t[a-1];
REPI(a, N){
    if(t[a]%2==1){
        printf("%c", s[N-a+1]);
    }
    else printf("%c", s[a]);
}


return 0;
}
