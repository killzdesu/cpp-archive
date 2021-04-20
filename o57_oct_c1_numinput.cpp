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
int pc[2014][2014];

void gen_pc(int lim){
    int a, b;
    for(a=0;a<lim;a++){
        for(b=0;b<=a;b++){
            if(b==0 or b==a)pc[a][b] = 1;
            else {
                pc[a][b] = pc[a-1][b]+pc[a-1][b-1];
                pc[a][b]%=9901;
            }
        }
    }
}

int u[1010];
int sm[1010];
vector<pii> l;

int main(){
int a, b, c, d;
gen_pc(2005);
cin >> N >> M;
REP(a, N){
    scanf("%d", &sm[a]);
    if(a) sm[a]+=sm[a-1];
}
l.pb(mp(1, 0));
REP(a, M){
    scanf("%d", &c);
    d = lower_bound(sm, sm+N, c)-sm;
    l.pb(mp(d+1, c));
}
l.pb(mp(N, sm[N-1]+1));
n = sm[N-1];
ll s=1;
i = 1;
int dis, av, imp;
for(a=1;a<l.size();a++){
    dis = l[a].se-l[a-1].se-1;
    av = l[a].fi-l[a-1].fi+1;
    imp = l[a].fi-i;
    if(a == l.size()-1) imp++;
//    printf("[dis: %d]  [av: %d]  [imp: %d] -> %d\n", dis, av, imp, pc[dis+av-1-imp][av-1]);
    //break;
    s*=pc[dis+av-1-imp][av-1];
    s%=9901;
    i = l[a].fi+1;
}


cout << s;

//REP(a, l.size()) printf("%d ", l[a]); printf("\n");

return 0;
}
