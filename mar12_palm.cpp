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
int dp[5010][2];
int root[5010];
vector<int> v[5010];

void make_tree(int x){
    int a;
    REP(a, v[x].size()){
        if(v[x][a] != root[x]){
            root[v[x][a]] = x;
            make_tree(v[x][a]);
        }
    }
}

void clear_tree(){
    int a, x;
    REPI(x, N){
        REP(a, v[x].size()){
            if(v[x][a] == root[x]){
                v[x].erase(v[x].begin()+a);
                break;
            }
        }
    }
}

void rec(int x){
    int a, b, sm=0, sm1=0;
    if(v[x].size() == 0){
        dp[x][0] = 1;
        dp[x][1] = 0;
        return;
    }
    REP(a, v[x].size()){
        rec(v[x][a]);
        sm += dp[v[x][a]][0];
    }
    dp[x][1] = 2e9;
    REP(a, v[x].size()){
        dp[x][1] = min(dp[x][1], sm-dp[v[x][a]][0]+dp[v[x][a]][1]);
    }
    dp[x][0] = 2e9;
    if(v[x].size()==1){
        dp[x][0] = dp[v[x][0]][1]+1;
        return;
    }
    REP(a, v[x].size()){
        for(b=a+1;b<v[x].size();b++){
            dp[x][0] = min(dp[x][0], sm-dp[v[x][a]][0]-dp[v[x][b]][0]+dp[v[x][a]][1]+dp[v[x][b]][1]+1);
        }
    }
}

int main(){
int a, b, c, d;
cin >> N;
REP(a, N-1){
    scanf("%d %d", &c, &d);
    v[c].pb(d);
    v[d].pb(c);
}
fill_n(root, N+3, -1);
make_tree(1);
clear_tree();
//return 0;
rec(1);
//REPI(a, N){
//    printf("%d: 0[%d] 1[%d]\n", a, dp[a][0], dp[a][1]);
//}
cout << dp[1][0];

return 0;
}
