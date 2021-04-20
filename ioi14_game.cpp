#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#define DB if(DBG)printf
#define IT iterator
#define all(x) x.begin(),x.end()
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#include<ctime>

using namespace std;

int DBG=1;
int i, n, k, N, M, K;
int cnt[2000];
int head[2000];

vector<pii> ord;

int fh(int x){
    if(x!= head[x]) head[x] = fh(head[x]);
    return head[x];
}

int main(){
int a, b, c, d;
N = 5;
REP(a, N) REP(b, N){
    if(a < b) ord.pb(mp(a, b));
    head[a] = a;
}
srand(time(0));
REP(a, N*(N-1)/2){
    cin >> ord[a].fi >> ord[a].se;
}
//random_shuffle(ord.begin(), ord.end());
REP(a, sz(ord)){
//    printf("%d %d", ord[a].fi, ord[a].se);
    if(cnt[ord[a].fi]>=N-2 or cnt[ord[a].se]>=N-2){
        printf(" y");
        head[fh(ord[a].fi)] = fh(ord[a].se);
        k++;
    }
    else if(sz(ord)-a+k<N){
        printf(" Y");
        head[fh(ord[a].fi)] = fh(ord[a].se);
        k++;
    }
    else {
        printf(" n");
    }
    cnt[ord[a].fi]++;
    cnt[ord[a].se]++;
    EL;
}
REP(a, N-1){
    if(fh(a) != fh(a+1)){
        cout << "FALSE";
        return 0;
    }
}

return 0;
}
