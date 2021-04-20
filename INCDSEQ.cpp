#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define All(x) x.begin(),x.end()
#define compress(x) {sort(all(x));(x).resize(distance((x).begin, unique(All(x))));}
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()
const int mod = 5e6;

using namespace std;

int i, n, k, N, M, K;

struct tree{
    int val;
    int lo, hi;
};


struct fenwick{
    int m[2*10010], N;
    ll sum;
    fenwick(){N=10005;}

    void init(int n){
        N = n;
    }

    void update(int x, int val){
        while(x <= N){
            m[x] += val;
            while(m[x] > mod) m[x]-=mod;
            while(m[x] < 0) m[x]+=mod;
            x += (x&-x);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0){
            sum += m[idx];
            while(sum > mod) sum -= mod;
            while(sum < 0) sum += mod;
            idx -= (idx & -idx);
        }
        return sum;
    }
}F[52];

int s[10010];
pii p[10010];

bool cmp(int a, int b){return s[a] < s[b];};
map<int, int> m, ma;

int main(){
int a, b, c, d;
cin >> N >> K;
REP(a, N){
    scanf("%d", &s[a]);
}

REP(a, N){
    p[a].fi = s[a];
    p[a].se = a;
}
sort(p, p+N);
REP(a, N){
    swap(p[a].fi, p[a].se);
    p[a].se = a+1;
}
sort(p, p+N);
REP(a, N){
    if(m[s[a]]==0) m[s[a]] = p[a].se;
//    printf("%d -> %d\n", s[a], m[s[a]]);;
}
ll sm=0;
REP(a, N){
    for(b=K;b>1;b--){
        c = F[b-1].query(m[s[a]]-1);
        d = F[b].query(m[s[a]])-F[b].query(m[s[a]]-1);
        F[b].update(m[s[a]], c-d);
    }
    d = F[b].query(m[s[a]])-F[b].query(m[s[a]]-1);
    F[1].update(m[s[a]], 1-d);
//    REPI(b, K){
//        printf("%d: ", b);
//        REPI(c, N){
//            printf("%d ", F[b].query(c)-F[b].query(c-1));
//        }
//        EL;
//    }
}
cout << ((F[K].query(10003)%mod)+mod)%mod;
return 0;
}
