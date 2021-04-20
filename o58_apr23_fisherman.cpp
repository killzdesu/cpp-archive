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
    return a.se-a.fi > b.se-b.fi;
}
typedef pair<pair<ll, ll>, int> sp;
vector<pair<pair<ll, ll>, int> > q0, q1;

int main(){
int a, b, c, d;
cin >> N >> M;
REP(a, N){
    scanf("%d %d", &c, &d);
    p[a] = {c, d};
}
if(N <= 100 and M <= 100 ) goto sol100;
else goto solA1;
sol100:;
ll A, B;
REP(a, M){
    scanf("%lld %lld", &A, &B);
    c = 0;
    if(A > 0){
        REP(b, N){
            if(A*p[b].fi*p[b].fi+B <= p[b].se) c++;
        }
    }
    else {
        REP(b, N){
            if(A*p[b].fi*p[b].fi+B >= p[b].se) c++;
        }
    }
    if(c == 0) Ans = "NONE";
    else if(c == N) Ans = "ALL";
    else Ans = "SOME";
    cout << Ans << "\n";
}
return 0;
solA1:;
REP(a, N) p[a].fi*=p[a].fi;
REP(a, M){
    scanf("%lld %lld", &C, &D);
    if(C > 0) q0.pb({{C, D}, a});
    else q1.pb({{C, D}, a});
}
// do q+
sort(ALL(q0), [](sp a, sp b){return a.fi.se > b.fi.se;});
sort(p, p+N, cmp_fish1);

b = 0;
for(a=0;a<q0.size();a++){
    while(b < N and p[b].fi+q0[a].fi.se <= p[b].se) b++;
//    printf("%d %lld %lld\n", b, p[b].fi, p[b].se);
//    printf("> %lld %lld %d\n", q0[a].fi.fi, q0[a].fi.se);
    ans[q0[a].se] = b;
}

REP(a, M){
    c = ans[a];
    if(c == 0) Ans = "NONE";
    else if(c == N) Ans = "ALL";
    else Ans = "SOME";
    printf("%s\n", Ans.c_str());
}
return 0;
}
