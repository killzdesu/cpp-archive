#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back

using namespace std;

int i, n, k, N, M, K;

typedef pair<int, int> pii ;
map<int, int> m;

pii f[2000], t[2000];

int main(){
int a, b, c, d;
cin >> N >> M;
REP(a, N){
    scanf("%d %d", &f[a].fi, &f[a].se);
}
REP(a, M){
    scanf("%d %d", &t[a].fi, &t[a].se);
    c = 2e8;
    REP(b, N){
        c = (int)min((double)c, fabs(t[a].fi-f[b].fi)+fabs(t[a].se-f[b].se));
    }
//    printf("> %d\n", c);
    m[c]++;
}
map<int, int>::iterator it;
d = 0;
for(it=m.begin();it!=m.end();it++){
    d = max(d, it->se);
}
cout << d;
return 0;
}
