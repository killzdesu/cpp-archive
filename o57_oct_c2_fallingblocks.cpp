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
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long

using namespace std;

int i, n, k, N, K;

struct fenwick{
    int m[2*100010], N;

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
        return query(idy) - query(idx-1);
    }

    int query_a(int idx){
        return query(idx) - query(idx-1);
    }
};

fenwick P, M, H;
int op[100010];

int main(){
int a, b, c, d, t;
cin >> N >> K;
P.init(N+5);
M.init(N+5);
H.init(N+5);
REP(a, K){
    scanf("%d", &t);
    if(t == 1){
        scanf("%d %d", &c, &d);
        H.update(c, 1);
        H.update(d+1, -1);
        op[c]++;
        op[d+1]--;
        if(op[c] > 0 and P.query_a(c)==0) P.update(c, 1);
        if(op[c] < 0 and M.query_a(c)==0) M.update(c, 1);
        if(op[d+1] > 0 and P.query_a(d+1)==0) P.update(d+1, 1);
        if(op[d+1] < 0 and M.query_a(d+1)==0) M.update(d+1, 1);
        if(op[c] == 0){
            P.update(c, -P.query_a(c));
            M.update(c, -M.query_a(c));
        }
        if(op[d+1] == 0){
            P.update(d+1, -P.query_a(d+1));
            M.update(d+1, -M.query_a(d+1));
        }
    }
    if(t == 2){
        scanf("%d %d", &c, &d);
        printf("%d %d\n", H.query(c), H.query(d));
    }
    if(t == 3){
        scanf("%d %d", &c, &d);
        printf("%d %d %d %d\n", H.query(c), H.query(d), P.query_r(c+1, d), M.query_r(c+1, d));
    }
}



return 0;
}
