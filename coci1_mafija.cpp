#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#define fi first
#define se second
#define mp make_pair
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define pb push_back

using namespace std;

int i, n, k, N, M, K;
map<pair<int, int>, int> m;
pair<int, int> p[500010];
vector<int> v[500010];

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    p[a+1].se = a+1;
    scanf("%d", &c);
    if(m[mp(c, a+1)] == 1) continue;
    v[a+1].pb(c);
    v[c].pb(a+1);
    p[a+1].fi++;
    p[c].fi++;
    m[mp(c, a+1)]=1;
    m[mp(a+1, c)]=1;
    K++;
}
sort(p, p+N+5, greater<pair<int, int> >());
k = K;
REP(a, N){
//    printf("Removing %d\n", p[a].se);
    for(b=0;b<v[p[a].se].size();b++){
        if(m[mp(p[a].se, v[p[a].se][b])] == 0) continue;
        k -= m[mp(p[a].se, v[p[a].se][b])];
//        printf("Del edge: %d %d || %d\n", p[a].se, v[p[a].se][b], m[p[a].se][v[p[a].se][b]]);
        m[mp(p[a].se, v[p[a].se][b])] = m[mp(v[p[a].se][b], p[a].se)] = 0;
    }
    if(k == 0) break;
}
cout << N-a-1;
return 0;
}
