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
    REP(a, BN){
        REP(b, 10){
            tp.p[b] = S[a].p[tp.p[b]];
        }
    }
    printf("%d\n", tp.p[0]);
}

void rerun(int x){
    int a;
    pm tp;
    REP(a, 10) tp.p[a] = a;
    REP(a, 10){
        tp.p[a] = S[x].p[tp.p[a]];
    }
    S[x] = tp;
}

pm trydo(pm p, pm q){
    int a;
    REP(a, 10){
        p.p[a] = q.p[p.p[a]];
    }
    return p;
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
    t[a] = s[a];
}
REP(a, M){
    scanf("%d %d", &qry[a].fi, &qry[a].se);
    z.pb(qry[a].se);
}
sort(z.begin(), z.end());
z.resize(distance(z.begin(), unique(z.begin(), z.end())));

REP(a, z.size()){
    P[z[a]] = a;
}
F.init(z.size()+5);

//--------------- SETUP BLOCK -----------------//
sort(s, s+N);
REP(a, N){
    F.update(P[s[a].x]+1, 1);
    B[hi(a)].pb(s[a]);
}
BN = ceil(N/double(SQ));
pm tp;
REP(a, BN){
    REP(b, 10) tp.p[b] = b;
    REP(b, B[a].size()){
        REP(c, 10)
            tp.p[c] = B[a][b].p[tp.p[c]];
    }
    S[a] = tp;
}
//REP(a, BN){
//    REP(b, 10){
//        printf("%d ", S[a].p[b]);
//    }
//    EL;
//}
int __x;
int pold, pnew;
int id;
int ro, rn;

//DB("-----test\n");

REP(__x, M){
//    DB("-----%d\n", __x);
    pnew = P[qry[__x].se];
    id = qry[__x].fi-1;
    pold = P[t[id].x];
    F.update(pold+1, -1);
    ro = F.query(pold+1);
    rn = F.query(pnew+1);
    if(ro > rn){
        if(ro/SQ == (rn)/SQ){
            B[hi(ro)].erase(B[hi(ro)].begin()+lo(ro));
            B[hi(ro)].insert(B[hi(ro)].begin()+lo(rn), t[id]);
            rerun(hi(ro));
            DB("here\n");
        }
        else {
            // ------- SET first ---------//
            B[hi(ro)].erase(B[hi(ro)].begin()+lo(ro));
            B[hi(ro)].insert(B[hi(ro)].begin(), B[hi(ro)-1][B[hi(ro)-1].size()-1]);
            rerun(hi(ro));
            // ------- RUN EDIT ----------//
            for(a=hi(ro)-1;a>hi(rn);a--){
                S[a] = trydo(S[a], make_inv(B[a][B[a].size()-1]));
                S[a] = trydo(B[a-1][B[a-1].size()-1], S[a]);
                B[a].pop_back();
                B[a].insert(B[a].begin(), B[a-1][B[a-1].size()]);
            }
            // -------- SET last ---------//
            B[hi(rn)].pop_back();
            B[hi(rn)].insert(B[hi(rn)].begin()+lo(rn), t[id]);
            rerun(hi(rn));
        }
    }
    else if(rn > ro){
        DB("here2\n");
        if(ro/SQ == (rn)/SQ){
            B[hi(ro)].erase(B[hi(ro)].begin()+lo(ro));
            B[hi(ro)].insert(B[hi(ro)].begin()+lo(rn), t[id]);
        }
        else {
            // ------- SET first ---------//
            B[hi(ro)].erase(B[hi(ro)].begin()+lo(ro));
            B[hi(ro)].push_back(B[hi(ro)-1][0]);
            rerun(hi(ro));
            // ------- RUN EDIT ----------//
            for(a=hi(ro)-1;a>hi(rn);a--){
                S[a] = trydo(make_inv(B[a][0]), S[a]);
                S[a] = trydo(S[a], B[a-1][0]);
                B[a].pop_front();
                B[a].push_back(B[a-1][0]);
            }
            // -------- SET last ---------//
            B[hi(rn)].pop_front();
            B[hi(rn)].insert(B[hi(rn)].begin()+lo(rn), t[id]);
            rerun(hi(rn));
        }
    }
    else {
        ;
    }
    F.update(pnew+1, 1);
    run();
}

return 0;
}
