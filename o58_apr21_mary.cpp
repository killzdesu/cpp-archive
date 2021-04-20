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

vector<int> v;
int inc[100010];
int incl[100010];

int main(){
int a, b, c, d;
cin >> N >> K;
REP(a, N){
    scanf("%d", &c);
    v.pb(c);
}
int mxx = 0;
REP(k, K+1){
    int mx = 0;
    fill(inc, inc+N+1, 0);
    fill(incl, incl+N+1, 0);
    for(a=N-1;a>=0;a--){
        inc[a] = (a!=N-1 and v[a] < v[a+1]?inc[a+1]:0) + 1;
        mxx = max(mxx, inc[a]);
    }
    REP(a, N) {
        incl[a] = 1;
        if(a) incl[a] += (v[a-1] < v[a]?incl[a-1]:0);
    }
    if(mxx == N) break;
    if(k == K) break;
//    REP(a, N) cout << inc[a] << " \n"[a==N-1];
//    REP(a, N) cout << incl[a] << " \n"[a==N-1];
    int T = 0;
    pii mem;
    REP(a, N){
        if(a and a!=N-1){
            if(v[a-1] < v[a+1]){
                if(maxa(T, incl[a-1]+inc[a+1]+1)){
                    mem = {a, 3};
                }
            }
        }
        if(a) if(maxa(T, incl[a-1]+1)){
            mem = {a, 1};
        }
        if(a!=N-1)if(maxa(T, inc[a+1]+1)){
            mem = {a, 2};
        }
    }
//    printf("%d %d %d\n", T, mem.fi, mem.se);
    if(mem.se == 3){
        if(v[mem.fi] > v[mem.fi-1]) mem.se = 2;
        else mem.se = 1;
    }
    if(mem.se == 1){
        i = mem.fi-1;
        while(v[mem.fi] < v[i] and i >= 0) i--;
        v.insert(v.begin()+i+1, v[mem.fi]);
        v.erase(v.begin()+mem.fi+1);
    }
    else if(mem.se == 2 or mem.se == 3){
        i = mem.fi+1;
        while(v[mem.fi] > v[i] and i < N) i++;
        v.insert(v.begin()+i, v[mem.fi]);
        v.erase(v.begin()+mem.fi);
    }
//    REP(a, N) cout << v[a] << " \n"[a==N-1];
}
cout << mxx;
return 0;
}
