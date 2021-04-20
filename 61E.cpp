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
    ll m[2*1000010], N;
    ll sum;
    fenwick(){N=1000005;}

    void init(int n){
        N = n;
    }

    void update(int x, int val){
        while(x <= N){
            m[x] += val;
            x += (x&-x);
        }
    }

    ll query(int idx) {
        ll sum = 0;
        while (idx > 0){
            sum += m[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
}F[5];

int s[1000010];
pii p[1000100];

bool cmp(int a, int b){return s[a] < s[b];};
map<int, int> m, ma;

int main(){
int a, b, c, d;
cin >> N;
K = 3;
REP(a, N){
    scanf("%d", &s[N-1-a]);
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
        F[b].update(p[a].se, c);
    }
    F[1].update(p[a].se, 1);
}
cout << F[K].query(1000003);
return 0;
}
