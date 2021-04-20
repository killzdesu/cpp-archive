#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long

using namespace std;

int i, n, k, N, M, K;

long long m[100010];

struct fenwick{
    int N;

    void init(int n){
        N = n;
    }

    void update(int x, int val){
        while(x <= N){
            //printf("%d %d\n", x, N);
            m[x] += val;
            x += (x&-x);
        }
    }

    ll query(int x){
        ll sm = 0;
        while(x > 0){
            sm += m[x];
            x -= (x&-x);
        }
        return sm;
    }

};

ll s[100010];
int p[100010];
pair<ll, int> z[100010];

int main(){
int a, b, c, d;
fenwick F;
cin >> N;
F.init(N+2);
ll cnt=0;
REP(a, N){
    scanf("%lld", &s[a]);
    z[a].fi = s[a];
    z[a].se = a;
}
sort(z, z+N);
REP(a, N){
    p[z[a].se] = a+1;
}
ll sm = 0;
//return 0;
for(a=N-1;a>=0;a--){
    sm += F.query(p[a]);
    F.update(p[a], 1);
}

printf("%lld", sm);

return 0;
}
