#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#include<queue>
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

vector<int> sp;
queue<int> ans[1005];
pii m[1005];

void match(int x, int y){
    int a;
    for(a=0;a<m[y].fi;a++){
        ans[m[y].se].push(m[x].se);
//        printf("Push %d to %d\n", m[x].se, m[y].se);
    }
    for(;a<M;a++){
        ans[m[x].se].push(m[y].se);
//        printf("Push %d to %d\n", m[y].se, m[x].se);
    }
    m[x].fi -= (M-m[y].fi);
    m[y].fi = 0;
}

void bomb(int x){
    int a;
    for(a=0;a<m[x].fi;a++){
        ans[m[x].se].push(m[x].se);
//        printf("Push %d to %d\n", m[x].se, m[x].se);
    }
    m[x].fi -= M;
}

int s[1010];

int main(){
int a, b, c, d;
cin >> K >> N;
M = K/N;
REP(a, K){
    scanf("%d", &s[a]);
    if(s[a] == -1){
        s[a] = 1;
    }
    m[s[a]].fi++;
}
REPI(a, N) m[a].se = a;
k = N;
sort(m+1, m+N+1, greater<pii>());
//
//REPI(a, N){
//    printf("%d :: %d\n", m[a].se, m[a].fi);
//}

while(m[1].fi != 0){
//    printf(">> %d %d\n", m[k].se, m[k].fi);
    if(m[k].fi >= M){
//        printf("BOMB\n");
        bomb(k);
    }
    else {
//        printf("Match %d %d\n", 1, k);
        match(1, k);
    }
    if(m[k].fi == 0) k--;
    if(m[1].fi == 0) k--;
//    sort(m+1, m+N+1, greater<pii>());
    i = 1;
    while(m[i].fi < m[i-1].fi and i < ){
        swap(m[i])
    }
}
printf("Yes\n");
REP(a, K){
    if(a!=-1){
        printf("%d %d\n", s[a], ans[s[a]].front());
        ans[s[a]].pop();
    }
    else {
        s[a] = 1;
        printf("%d %d\n", s[a], ans[s[a]].front());
        ans[s[a]].pop();
    }
}

return 0;
}
