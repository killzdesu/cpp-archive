#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define all(x) x.begin(),x.end()
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()


using namespace std;

int i, n, k, N, M, K;

vector<int> v[10010];
int root[10010];
int mx1[10010], mx2[10010];

void dfs(int x, int prev){
    int a;
    REP(a, sz(v[x])){
        if(v[x][a] == prev) continue;
        dfs(v[x][a], x);
        if(mx1[x] < mx1[v[x][a]]){
            mx2[x] = mx1[x];
            mx1[x] = mx1[v[x][a]];
        }
        else if(mx2[x] < mx1[v[x][a]]){
            mx2[x] = mx1[v[x][a]];
        }
    }

    k = max(k, mx1[x]+mx2[x]);
    mx1[x] += 1;
}

int main(){
int a, b, c, d;
cin >> N;
REP(a, N-1){
    cin >> c >> d;
    v[c].pb(d);
    v[d].pb(c);
}
dfs(1, -1);
cout << k;
return 0;
}
