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
char q[10];
int head[100010];

int find_head(int x){
    if(head[x] != x){
        head[x] = find_head(head[x]);
    }
    return head[x];
}

int main(){
int a, b, c, d;
cin >> N >> M;
REPI(a, N) head[a] = a;
while(M--){
    scanf("%s %d %d", q, &c, &d);
    if(q[0] == 'q'){
        if(find_head(c) != find_head(d)) printf("no\n");
        else printf("yes\n");
    }
    else {
        head[find_head(d)] = find_head(c);
    }
}


return 0;
}
