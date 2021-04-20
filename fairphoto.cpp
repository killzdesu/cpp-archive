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

pii p[100010];
vector<int> cp;
map<int, int> m;

int qs[9][100010];

struct node{
    int d[8];
    node(){};
    node(int x){
        int i;
        for(i=1;i<=7;i++){
            d[i-1] = qs[i][x]-qs[i+1][x];
        }
    }
    bool operator < (const node &b) const{
        int i = 0;
        while(i < 6 and b.d[i] == d[i]) i++;
        return d[i] < b.d[i];
    }
};

map<node, int> h;

int qr(int d, int lo, int hi){
    return qs[d][hi]-qs[d][lo-1];
}

int main(){
int a, b, c, d;
cin >> N >> K;
REP(a, N){
    scanf("%d %d", &p[a].fi, &p[a].se);
    cp.pb(p[a].fi);
}
compress(cp);
REP(a, N){
    m[cp[a]] = a+1;
}
REP(a, N){
    qs[p[a].se][m[p[a].fi]]++;
}
REPI(b, 8) REPI(a, 100000){
    qs[b][a] += qs[b][a-1];
}
node t;
k = 0;
REPI(a, N){
    t = node(a);
//    printf("T: ");
//    REP(b, 7) cout << t.d[b] << " \n"[b == 6];
    c = h[t];
    if(c != 0){
        k = max(k, cp[a-1]-cp[c]);
    }
    else {
        h[t] = a;
    }
    dump(h[t]);
}
cout << k;
return 0;
}
