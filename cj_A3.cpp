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
pii p[4000], mk;
double eps = 2e-14;
const double pi = acos(-1.0);

double geta(pii a){
    return atan2(a.se-mk.se, a.fi-mk.fi);
}

bool cmp(pii a, pii b){
    return geta(a) < geta(b);
}

double an[100000];

int main(){
freopen("C-large-practice.in", "r", stdin);
freopen("C-l-pas.txt", "w", stdout);
int a, b, c, d;
int T, RR;
cin >> T;
REPI(RR, T){
    cin >> N;
    REP(a, N){
        cin >> p[a].fi >> p[a].se;
    }
    printf("Case #%d:\n", RR);
    REP(i, N){
        b = 0;
        mk = p[i];
        REP(a, N){
            if(a!=i){
                an[b] = atan2(p[a].se-p[i].se, p[a].fi-p[i].fi);
                b++;
            }
        }
//        continue;
        sort(an, an+N-1);
        REP(a, N-1) an[a+N-1] = (an[a]+2.0*pi);
        b = 0;
        int mn = N-1;
        REP(a, N-1){
            while(b < N+N-2 and an[b] < an[a]+pi+eps){
                b++;
            }
            mn = min(mn, N-1-(b-a));
        }
        cout << mn << "\n";
    }
}



return 0;
}
