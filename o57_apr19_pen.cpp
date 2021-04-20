#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define pb push_back
#define pii pair<int,int>
#define mp make_pair

using namespace std;

int i, n, k, N, M, K;

struct que{
    int x1, x2, y;
    que(){}
    que(int a, int b, int c){
        x1 = a; x2 = b; y = c;
    }
    bool operator < (const que &b) const{
        return y < b.y;
    }
}T[100010];

set<pii> S;
set<pii>::iterator it;

vector<pair<pii, int> > ev;
vector<int> s;

int get[100010];
int dp[100010];

int ans(int x){
    if(dp[x] != 0) return dp[x];
    if(get[x]==-1){
        dp[x] = 1;
        return 1;
    }
    dp[x] = 1+ans(get[x]);
    return dp[x];
}

map<int, int> m;
vector<int> B[200010], E[200010];

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    scanf("%d %d %d", &b, &c, &d);
    T[a] = que(b, c, d);
    s.pb(b);
    s.pb(c);
}

sort(s.begin(), s.end());
s.resize(distance(s.begin(), unique(s.begin(), s.end())));

REP(a, s.size()){
    m[s[a]] = a;
}

REP(a, N){
    B[m[T[a].x1]].pb(a);
    E[m[T[a].x2]].pb(a);
}
vector<int> tmp;
REP(i, s.size()){
    tmp.clear();
    c = m[s[i]];
    REP(a, B[c].size()){
        tmp.pb(B[c][a]);
        S.remove(mp(T[B[c][a]], B[c][a]));
    }
    it = S.upper_bound(mp());
    REP(a, tmp.size()){

    }
}

//REP(a, N){
//    printf("%d --> %d\n", a, get[a]);
//}

REP(a, N){
    dp[a] = ans(a);
    printf("%d\n", dp[a]);
}

return 0;
}
