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
int C[200010];
vector<int> v[200010], av;

void color(int x){
    int a;
    av.clear();
    for(int a=0; a<v[x].size();a++){
        if(C[v[x][a]] == -1) continue;
        else av.pb(C[v[x][a]]);
    }
    sort(av.begin(), av.end());
    av.resize(distance(av.begin(), unique(av.begin(), av.end())));
    for(a=0;a<av.size();a++){
        if(av[a] != a+1){
            C[x] = a+1;
            return;
        }
    }
    C[x] = a+1;
    return;
}

int main(){
int a, b, c, d;
cin >> N >> K;
REPI(a, N) C[a] = -1;
while(1){
    scanf("%d %d", &c, &d);
    v[c].pb(d);
    v[d].pb(c);
    if(c == -1 && d == -1) break;
}

REPI(a, N){
    color(a);
}
REPI(a, N){
    printf("%d\n", C[a]);
}
return 0;
}
