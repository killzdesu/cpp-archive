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
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

int SQ;
int DBG=1;
int i, n, k, N, M, K;

struct fenwick{
    int m[2*200010], N;

    void init(int n){
        N = n;
    }

    void update(int x, int val){
        while(x <= N){
            m[x] += val;
            x += (x&-x);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0){
            sum += m[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

}F;

struct pm{
    int id, x;
    int p[10];
    bool operator < (const pm &b) const{
        return x < b.x;
    }
};


int BN;
pm S[340];
deque<pm> B[340];
pm s[100010], t[100010];

int hi(int x){
    return x/SQ;
}

int lo(int x){
    return x%SQ;
}

pm make_inv(pm x){
    pm tmp;
    int a;
    REP(a, 10){
        tmp.p[x.p[a]] = a;
    }
    return tmp;
}

int pos[100010];
map<int, int> m, P;

vector<int> z;

pii qry[100010];

void run(){
    int a, b;
    pm tp;
    REP(a, 10) tp.p[a] = a;
    REP(a, N){
        REP(b, 10){
            tp.p[b] = s[a].p[tp.p[b]];
        }
    }
    printf("%d\n", tp.p[0]);
}

bool cmp(pm a, pm b){
    return pos[a.id] < pos[b.id];
}

int main(){
int a, b, c, d;
SQ = 330;
cin >> N >> M;
REP(a, N){
    scanf("%d", &pos[a]);
    m[pos[a]] = a;
    z.pb(pos[a]);
    REP(b, 10){
        scanf("%d", &s[a].p[b]);
    }
    s[a].id = a;
    s[a].x = pos[a];
}
REP(a, M){
    scanf("%d %d", &qry[a].fi, &qry[a].se);
    z.pb(qry[a].se);
}
//sort(z.begin(), z.end());
//z.resize(distance(z.begin(), unique(z.begin(), z.end())));

REP(a, z.size()){
    P[z[a]] = a;
}
F.init(z.size()+5);

int __x;
int pold, pnew;
int id;
int ro, rn;

//DB("-----test\n");

REP(__x, M){
//    DB("-----%d\n", __x);
    pos[qry[__x].fi-1] = qry[__x].se;
    sort(s, s+N, cmp);
    run();
}

return 0;
}
