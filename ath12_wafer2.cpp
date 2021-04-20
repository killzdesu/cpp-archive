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

pii p[100010];
vector<ll> Lup, Ldown, Rup, Rdown;

bool cmp2(pii a, pii b){
    return a.se < b.se;
}

int main(){
int a, b, c, d;
int T;
ll sm, mx;
ll l, r;
cin >> T;
while(T--){
    cin >> N >> M >> K;

    sm = 0;

    REP(a, K){
        scanf("%d %d", &p[a].fi, &p[a].se);
    }
    sort(p, p+K, cmp2);

    Lup.clear();
    Ldown.clear();
    Rup.clear();
    Rdown.clear();

    Lup.pb(0);
    Rup.pb(0);
    Ldown.pb(0);
    Rdown.pb(0);

//    REP(a, K){
//        printf("> %d %d\n", p[a].fi, p[a].se);
//    }printf("\n");

    l = 2e9;
    r = -2e9;
    REP(a, K){
        l = min(l, (ll)p[a].fi);
        r = max(r, (ll)p[a].fi);
        while(a!=K-1 and p[a].se == p[a+1].se){
            a++;
            l = min(l, (ll)p[a].fi);
            r = max(r, (ll)p[a].fi);
        }
        if(a == K-1) break;
        Lup.pb((l)*((ll)p[a+1].se-p[a].se));
    }
    l = 2e9;
    r = -2e9;
    for(a=K-1;a>=0;a--){
        l = min(l, (ll)p[a].fi);
        r = max(r, (ll)p[a].fi);
        while(a!=0 and p[a].se == p[a-1].se){
            a--;
            l = min(l, (ll)p[a].fi);
            r = max(r, (ll)p[a].fi);
        }
        if(a == 0) break;

        Ldown.pb((l)*((ll)p[a].se-p[a-1].se));
    }

    l = 2e9;
    r = -2e9;
    REP(a, K){
        l = min(l, (ll)p[a].fi);
        r = max(r, (ll)p[a].fi);
        while(a!=K-1 and p[a].se == p[a+1].se){
            a++;
            l = min(l, (ll)p[a].fi);
            r = max(r, (ll)p[a].fi);
        }
        if(a == K-1) break;
        Rup.pb((N-r)*((ll)p[a+1].se-p[a].se));
    }
    l = 2e9;
    r = -2e9;
    for(a=K-1;a>=0;a--){
        l = min(l, (ll)p[a].fi);
        r = max(r, (ll)p[a].fi);
        while(a!=0 and p[a].se == p[a-1].se){
            a--;
            l = min(l, (ll)p[a].fi);
            r = max(r, (ll)p[a].fi);
        }
        if(a == 0) break;

        Rdown.pb((N-r)*((ll)p[a].se-p[a-1].se));
    }

    REP(a, Lup.size()){
        if(a) Lup[a] += Lup[a-1];
        if(a) Rup[a] += Rup[a-1];
        if(a) Ldown[a] += Ldown[a-1];
        if(a) Rdown[a] += Rdown[a-1];
    }

    for(a=0;a<Ldown.size()/2;a++){
        swap(Ldown[a], Ldown[Ldown.size()-1-a]);
        swap(Rdown[a], Rdown[Rdown.size()-1-a]);
    }

    REP(a, Lup.size()){
        printf("%lld ", Lup[a]);
    }printf(" :\n");
    REP(a, Ldown.size()){
        printf("%lld ", Ldown[a]);
    }printf(" :\n");
    REP(a, Rup.size()){
        printf("%lld ", Rup[a]);
    }printf(" :\n");
    REP(a, Rdown.size()){
        printf("%lld ", Rdown[a]);
    }printf(" :\n");

    mx = 0;
    REP(a, Lup.size()){
        mx = max(mx, Lup[a]+Ldown[a]);
    }
    sm += mx;
    mx = 0;
    REP(a, Lup.size()){
        mx = max(mx, Rup[a]+Rdown[a]);
    }
    sm += mx;
    printf("%d\n", sm);
}

return 0;
}
