#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<stack>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define pb push_back

using namespace std;

int i, n, k, N, M, K;

typedef pair<int, int> pii;
stack<int> S;

bool cmp(pair<pii, int> a, pair<pii, int> b){
    if(a.fi.fi != b.fi.fi) return a.fi.fi < b.fi.fi;
    return a.fi.se > b.fi.se;
}

pair<pii, int> p[100010];
pii Q[100010];

bool ans(pii a, pii b){
    return a.se < b.se;
}

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    cin >> c >> d;
    p[a].fi = make_pair(c, d);
    p[a].se = a+1;
}
sort(p, p+N, cmp);
cin >> M;
REP(a, M){
    cin >> Q[a].fi;
    Q[a].se = a;
}
sort(Q, Q+M);
i = 0;
REP(a, M){
    while(i < N and p[i].fi.fi <= Q[a].fi){
        S.push(i);
        i++;
    }
    while(!S.empty() and p[S.top()].fi.se < Q[a].fi) S.pop();
    if(!S.empty()){
        Q[a].fi = p[S.top()].se;
    }
    else Q[a].fi = -1;
}
sort(Q, Q+M, ans);
REP(a, M) printf("%d\n", Q[a].fi);

return 0;
}
