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

struct node{
    int val, to, fr;
    bool operator < (const node &b) const{
        if(val != b.val) return val < b.val;
        return fr > b.fr;
    }
    node(){}
    node(int a, int b, int c){
        val = a; to = b; fr = c;
    }
};

int i, n, k, N, M, K;
priority_queue<node> Q;
int s[200010];
vector<pii> v[200010];
bool vs[200010];
int ice[200010];
int fr[200010];

int main(){
//freopen("ice.txt", "r", stdin);
int a, b, c, d;
cin >> N >> M;
REPI(a, N){
    scanf("%d", s+a);
}
REPI(a, M){
    scanf("%d %d %d", &c, &d, &b);
    v[c].pb(mp(d, b));
    v[d].pb(mp(c, b));
}
REPI(a, N){
    if(s[a]){
        Q.push(node(s[a], a, a));
    }
}
node t;
while(!Q.empty()){
    t = Q.top();
    Q.pop();
    if(vs[t.to]) continue;
    vs[t.to] = true;
    ice[t.to] = t.val;
    fr[t.to] = t.fr;
    REP(a, sz(v[t.to])){
        b = v[t.to][a].fi;
        if(vs[b]) continue;
        if(t.val > v[t.to][a].se)
            Q.push(node(t.val-v[t.to][a].se, b, t.fr));
    }
}

REPI(a, N){
    if(ice[t.to] == 0){
        printf("0 0\n");
    }
    else {
        printf("%d %d\n", fr[a], ice[a]);
    }
}

return 0;
}
