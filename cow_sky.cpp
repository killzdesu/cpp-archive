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

int i, n, k, N, M, K;
ll W;
pair<ll, int> s[20];

int main(){
int a, b, c, d;
cin >> N >> W;
REP(a, N){
    cin >> s[a].fi;
    s[a].se = a+1;
}
sort(s, s+N);
vector<vector<int> > A;
int mn = 2e9;
do{
    k = 1;
    ll sm = 0;
    REP(a, N){
        if(sm + s[a].fi > W){
            sm = s[a].fi;
            k++;
        }
        else {
            sm += s[a].fi;
        }
    }
    if(mn > k){
        A.clear();
        A.pb(vector<int>());
        k = 1;
        sm = 0;
        REP(a, N){
        if(sm + s[a].fi > W){
                A.pb(vector<int>());
                A[A.size()-1].pb(s[a].se);
                sm = s[a].fi;
                k++;
            }
            else {
                A[A.size()-1].pb(s[a].se);
                sm += s[a].fi;
            }
        }
        mn = k;
    }
}while(next_permutation(s, s+N));
cout << mn;
REP(a, A.size()){
    printf("\n%d", A[a].size());
    sort(ALL(A[a]));
    REP(b, A[a].size()){
        printf(" %d", A[a][b]);
    }
}
return 0;
}
