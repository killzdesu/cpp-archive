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

int i, n, k, N, M, K;
int root[100010];
vector<int> v[100010];

int mod(ll x){
    return ((x%9907)+9907)%9907;
}

void make_tree(int x){
    int a;
//    printf("%d", x);
    REP(a, sz(v[x])){
        if(v[x][a] == root[x]){
            v[x].erase(v[x].begin()+a);
            a--;
            continue;
        }
        root[v[x][a]] = x;
        make_tree(v[x][a]);
    }
}

int X[100010], Y[100010], Z[100010];
ll sumchild[100010], val2child[100010], sumsqparentchild[100010], valmerge[100010], valparent[100010], sumsqchild[100010], sumparentchild[100010];

ll SUM, SQ, SUMCH;

void dfs(int x){
    int a;
    REP(a, sz(v[x])){
        sumchild[x] += X[v[x][a]];
        sumsqchild[x] += X[v[x][a]]*X[v[x][a]];
//        sumsqchild[x] = mod(sumsqchild[x]);
//        sumchild[x] = mod(sumchild[x]);
    }

    sumparentchild[x] = sumchild[x];
    sumsqparentchild[x] = sumsqchild[x];
    if(root[x]!=-1){
        sumparentchild[x] += X[root[x]];
        sumsqparentchild[x] += X[root[x]]*X[root[x]];
    }

    REP(a, sz(v[x])) dfs(v[x][a]);

    SUM = 0; SQ = 0;
    REP(a, sz(v[x])){
        SUM += sumchild[v[x][a]];
        SQ += sumsqchild[v[x][a]];
    }
    val2child[x] = (SUM*SUM)-SQ;
    if(val2child[x]%2!=0)val2child[x] += 9907;
    val2child[x] /= 2;
    val2child[x] = mod(val2child[x]);

    SUMCH = SUM;
    SUM = 0;
    if(root[x]!=-1){
        SUM = sumparentchild[root[x]]-X[x];
        SQ = sumsqparentchild[root[x]]-X[x]*X[x];
        valparent[x] = SUM*SUM-SQ;
        if(valparent[x]%2!=0)valparent[x] += 9907;
        valparent[x] /= 2;
        valparent[x] = mod(valparent[x]);
    }


    valmerge[x] = SUM*SUMCH;
    valmerge[x] = mod(valmerge[x]);

}

int main(){
freopen("asd.in", "r", stdin);
int a, b, c, d;
cin >> N;
REP(a, N-1){
    scanf("%d %d", &c, &d);
    v[c].pb(d);
    v[d].pb(c);
}
int R = (N+1)/2;
root[R] = -1;
make_tree(R);
REPI(a, N){
    scanf("%d %d %d", X+a, Y+a, Z+a);
//    X[a] = mod(X[a]);
    Y[a] = mod(Y[a]);
    Z[a] = mod(Z[a]);
}
dfs(R);
//REPI(a, N) printf("%2d ", a);EL;
//REPI(a, N) printf("%2d ", val2child[a]);printf("\tval2child");EL;
//REPI(a, N) printf("%2d ", valparent[a]);printf("\tvalparent");EL;
//REPI(a, N) printf("%2d ", valmerge[a]);printf("\tvalmerge");EL;
ll ans=0;
REPI(a, N){
    ans += Y[a]*(val2child[a]+valmerge[a]+valparent[a])+Z[a];
    ans = mod(ans);
}
cout << ans;
return 0;
}
