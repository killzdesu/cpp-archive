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

int main(){
int a, b, c, d;
cin >> N >> M;
if(M < 15) goto M15;
M15:;
multiset<int> S;
REP(a, N){
    scanf("%d", &c);
    S.insert(c);
}
vector<int> T;
while(M--){
    scanf("%d", &c);
    if(c == 1){
        scanf("%d", &d);
        if(S.find(d)!=S.end()) printf("1\n");
        else printf("0\n");
    }
    else {
        scanf("%d %d %d", &k, &c, &d);
        if(S.find(k) == S.end()) continue;
        T.clear();
        for(auto is = S.begin(); is!=S.end(); is++){
            int it = *is;
            if(it < k) T.pb(it+c);
            else if(it >= k) T.pb(it+d);
        }
        S.clear();
        REP(a, N){
            S.insert(T[a]);
        }
//        printf(" >> ");
//        for(auto it: S) printf("%d ", it);
//        EL;
    }
}

return 0;

return 0;
}
