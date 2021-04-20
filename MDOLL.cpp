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

int i, n, k, N, M, K;
pii s[100010];

struct cmp{
    bool operator() (const pii &a, const pii &b) const{
        if(a.se != b.se) return a.se < b.se;
        return a.fi > b.fi;
    }
};

set<pii> S;

int main(){
int a, b, c, d;
int T;
cin >> T;
while(T--){
    cin >> N;
    REP(a, N){
        scanf("%d %d", &s[a].fi, &s[a].se);
    }
    sort(s, s+N);
    S.clear();
    REP(a, N){
        auto it = S.lower_bound(s[a]);
        if(it != S.begin()){
            it--;
            while(it!=S.begin() and it->fi >= s[a].fi) it--;
            if(it->fi < s[a].fi) S.erase(it);
        }
        S.insert(s[a]);
    }
    cout << S.size() << "\n";
}




return 0;
}
