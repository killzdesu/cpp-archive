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

set<que> S;
set<que>::iterator it;

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

bool cmp(pair<pii, int> a, pair<pii, int> b){
    if(a.fi == b.fi) return T[a.se].y < T[b.se].y;
    return a.fi < b.fi;
}

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    scanf("%d %d %d", &b, &c, &d);
    T[a] = que(b, c, d);
    ev.pb(mp(mp(b, 1), a));
    ev.pb(mp(mp(c, 0), a));
    s.pb(b);
    s.pb(c);
}
sort(ev.begin(), ev.end(), cmp);
REP(i, ev.size()){
    if(ev[i].fi.se == 1){
        S.insert(que(0, ev[i].se, T[ev[i].se].y));
    }
    else {
        it = S.lower_bound(que(0, ev[i].se, T[ev[i].se].y));
        if(it==S.begin()){
            get[ev[i].se] = -1;
        }
        else {
            it--;
            get[ev[i].se] = it->x2;
            it++;
        }
        S.erase(it);
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
