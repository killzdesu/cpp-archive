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
char s[105][105];int len[105];
int vs[300], p[300];
vector<int> v[300];
vector<pii> sa;

void dfs(int x){
    if(vs[x] == 1){
        if(p[x] == 0) i = -1;
        return;
    }
    vs[x] = 1;
    for(int a=0;a<v[x].size();a++){
        dfs(v[x][a]);
    }
    k++;
    sa.pb(mp(k, x));
    p[x] = k;
}

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    scanf("%s", s[a]);
    len[a] = strlen(s[a]);
}

REP(a, N-1){
    for(b=0;b<min(len[a], len[a+1]);b++){
        if(s[a][b] != s[a+1][b]){
            v[(int)s[a+1][b]].pb((int)s[a][b]);
//            printf("%c -> %c\n", (int)s[a][b], (int)s[a+1][b]);
            break;
        }
    }
    if(b == min(len[a], len[a+1]) and len[a] > len[a+1]) i = -1;
}

for(a='a';a<='z';a++){
    if(vs[a]==0) dfs(a);
}

sort(sa.begin(), sa.end());
if(i == -1){
    cout << "Impossible";
    return 0;
}
for(a=0;a<sa.size();a++){
    printf("%c", sa[a].se);
}

return 0;
}
