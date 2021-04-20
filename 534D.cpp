#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin, unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;

int i, n, k, N, M, K;

pii p;
vector<pii> ans;
vector<pii> buc[3];
bool chk[200010];

int main(){
int a, b, c, d;
cin >> N;
int mx = 0;
REP(a, N){
    scanf("%d", &c);
    p = mp(c, a+1);
    buc[c%3].pb(p);
    mx = max(mx, c);
}
REP(i, 3){
    sort(ALL(buc[i]));
    REP(a, sz(buc[i])){
        chk[buc[i][a].fi] = 1;
        buc[i][a].fi = max(buc[i][a].fi, a*3 + i);
//        buc[i][a].fi = a*3 + i;
        ans.pb(buc[i][a]);
    }
}
REP(a, mx+1) if(chk[a] == 0) goto FAIL;
sort(ALL(ans));
REP(a, N) {
    if(ans[a].fi == a) k++;
}
FAIL:;
if(k != N){
    cout << "Impossible";
}
else {
    cout << "Possible\n";
    REP(a, N) printf("%d ", ans[a].se);
}

return 0;
}
