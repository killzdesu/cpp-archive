#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#include<set>
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

    int query_r(int idx, int idy){
        return query(idy)-query(idx-1);
    }

    int query_a(int idx){
        return query(idx)-query(idx-1);
    }

};

int s[200010];
set<int> S;
set<int>::iterator it;
fenwick F;

void print_all(){
    int a;
//    printf(">> ");
    REPI(a, N){
        printf("%d ", F.query_a(a));
    }printf("\n");
}

int main(){
int a, b, c, d;
int mn=2e9;
cin >> N >> K;
F.init(N+2);
REPI(a, N){
    scanf("%d", &s[a]);
    S.insert(a);
    mn = min(s[a], mn);
    F.update(a, s[a]);
}
int sm;
int all=0;
//int fr=K, re=K;
//cout << mn << "\n";
REPI(a, N-K+1){
    sm = F.query_r(a, a+K-1);
    while(sm >=0){
        it = S.upper_bound(a+K-1);
        it--;
        c = F.query_a(*it);
//        printf("sm: %d   it: %d   c: %d  -> ", sm, *it, c);
        if(c-mn <= sm+1){
            F.update(*it, -c+mn);
            all += c-mn;
        }
        else {
            //printf("Set 2\n");
            F.update(*it, -sm-1);
            all += sm+1;
        }
        S.erase(it);
        sm = F.query_r(a, a+K-1);
//        printf(" new sm: %d\n", sm);
    }
}
printf("%d\n", all);
print_all();

return 0;
}
