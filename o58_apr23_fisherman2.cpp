#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin(), unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define dump(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

int i, n, k, N, M, K;
ll C, D;
pair<ll, ll> p[100010];
string Ans;
int ans[100010];

bool cmp_fish1(pair<ll, ll> a, pair<ll, ll> b){
    if(a.se != b.se) return a.se < b.se;
    return abs(a.fi) < abs(b.fi);
}
typedef pair<pair<ll, ll>, int> sp;
vector<pair<pair<ll, ll>, int> > q0, q1;

vector<sp> q[2];

int main(){
int a, b, c, d;
cin >> N >> M;
REP(a, N){
    scanf("%d %d", &c, &d);
    p[a] = {c*c, d};
}
REP(a, M){
    scanf("%lld %lld", &C, &D);
    if(C > 0) q[0].pb({{C, D}, a});
    else q[1].pb({{C, D}, a});
}


return 0;
}
