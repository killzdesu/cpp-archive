#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
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
map<pii, int> m;
vector<int> v[100010], p[100010];
int die[100010], ced[100010];

void call(int x){
    int a, b;
    if(ced[x]) return;
    REP(a, v[x].size()){
        if(m[mp(x, v[x][a])]!=1){
            printf("%d\n", v[x][a]);
        }
    }
    ced[x] = 1;
    REP(b, p[x].size()){
        call(p[x][b]);
    }
}

void mark_del(int x, int val){
    int a;
    REP(a, p[x].size()){
        m[mp(p[x][a], val)]=1;
        mark_del(p[x][a], val);
    }
}

int main(){
int a, b, c, d;
cin >> N >> M;
REPI(a, N){
    scanf("%d", &c);
    REP(b, c){
        scanf("%d", &d);
        v[a].pb(d);
    }
}
int r;
REPI(r, M){
    scanf("%d %d %d", &b, &c, &d);
    if(b == 1){
        if(die[c]) continue;
        m[mp(c, d)]=1;
        mark_del(c, d);
    }
    else {
        p[c].pb(d);
        die[d] = 1;
    }
}
i = 1;
while(die[i]) i++;
int cnt = 0;
REPI(a, N){
    if(!die[a]) call(a);

}

return 0;
}
