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

int MAXN;

int sum[1006][1010];
int cnt[1006][1010];
//
ll sum2[5][100010];
ll cnt2[5][100010];

struct fenwick{
    ll m[100100];
    fenwick(){}
    void update(int x, ll val){
        while(x < M+4){
            m[x] += val;
            x += (x&-x);
        }
    }
    ll query(int idx) {
        ll sm = 0;
        while (idx > 0){
            sm += m[idx];
            idx -= (idx & -idx);
        }
        return sm;
    }
}CNT[6], SUM[6];

void upd(int A[][1010], int x, int y, int val){
    int c = y;
    while(x < N+4){
        y = c;
        while(y < M+5){
            A[x][y] += val;
            y += (y&-y);
        }
        x += (x&-x);
    }
}

int query(int A[][1010], int x, int y){
    int sm = 0;
    int c = y;
    while(x > 0){
        y = c;
        while(y > 0){
            sm += A[x][y];
            y -= (y&-y);
        }
        x -= (x&-x);
    }
    return sm;
}

ll getq(int A[][1010], int x1, int y1, int x2, int y2){
    ll sm = 0;
    sm += query(A, x2, y2);
    sm -= query(A, x1-1, y2);
    sm -= query(A, x2, y1-1);
    sm += query(A, x1-1, y1-1);
    return sm;
}

void upd2(ll A[][100010], int x, int y, int val){
    int c = y;
    while(x < N+1){
        y = c;
        while(y < M+5){
            A[x][y] += val;
            y += (y&-y);
        }
        x += (x&-x);
    }
}

ll query2(ll A[][100010], int x, int y){
    ll sm = 0;
    int c = y;
    while(x > 0){
        y = c;
        while(y > 0){
            sm += A[x][y];
            y -= (y&-y);
        }
        x -= (x&-x);
    }
    return sm;
}

ll getq2(ll A[][100010], int x1, int y1, int x2, int y2){
    ll sm = 0;
    sm += query2(A, x2, y2);
    sm -= query2(A, x1-1, y2);
    sm -= query2(A, x2, y1-1);
    sm += query2(A, x1-1, y1-1);
    return sm;
}

int main(){
//freopen("test_rain.txt", "r", stdin);
int a, b, c, d;
int x1, y1, x2, y2;
int Q;
cin >> Q >> c >> N >> M;
Q += c;

if(N == 1) goto W1;
while(Q--){
    scanf("%d", &c);
    if(c == 1){
        scanf("%d %d", &c, &d);
        c++;d++;
        upd(sum, c, d, d);
        upd(cnt, c, d, 1);
    }
    else {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1++;x2++;
        y1++;y2++;
        ll sm = 0;
        sm += getq(sum, x1, y1, x2, y2);
        sm += (y2-y1)*(getq(cnt, x1, y2+1, x2, M+2));
        sm -= y1*(getq(cnt, x1, y1, x2, y2));
        ll SS = 0;
//        for(a=x1;a<=x2;a++){
//            sm += query(sum[a], y2);
//            sm -= query(sum[a], y1-1);
//            sm -= y1*(query(cnt[a], y2)-query(cnt[a], y1-1));
//            sm += (y2-y1)*(query(cnt[a], 1003)-query(cnt[a], y2));
//        }
        printf("%I64d\n", sm);
    }
}
return 0;

W1:;
//assert(i == 99);
while(Q--){
    scanf("%d", &c);
    if(c == 1){
        scanf("%d %d", &c, &d);
        d++;
        SUM[c].update(d, (ll)d);
        CNT[c].update(d, (ll)1);
    }
    else {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
//        x1++;x2++;
        y1++;y2++;
        ll sm = 0;
//            sm += query(sum[a], y2);
//            sm -= query(sum[a], y1-1);
//            sm -= y1*(query(cnt[a], y2)-query(cnt[a], y1-1));
//            sm += (y2-y1)*(query(cnt[a], 1003)-query(cnt[a], y2));
        for(a=x1;a<=x2;a++){
            sm += SUM[a].query(y2)-SUM[a].query(y1-1);
            sm += ((ll)y2-y1)*(CNT[a].query(M+1)-CNT[a].query(y2));
            sm -= y1*(CNT[a].query(y2)-CNT[a].query(y1-1));
        }
        printf("%lld\n", sm);
    }
}

return 0;
//W1_1:;
//while(Q--){
//    scanf("%d", &c);
//    if(c == 1){
//        scanf("%d %d", &c, &d);
//        c++;d++;
//        upd2(sum2, c, d, (ll)d);
//        upd2(cnt2, c, d, (ll)1);
//    }
//    else {
//        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
//        x1++;x2++;
//        y1++;y2++;
//        ll sm = 0;
//        sm += getq2(sum2, x1, y1, x2, y2);
//        sm += ((ll)y2-y1)*(getq2(cnt2, x1, y2+1, x2, M+2));
//        sm -= y1*(getq2(cnt2, x1, y1, x2, y2));
////        for(a=x1;a<=x2;a++){
////            sm += query(sum[a], y2);
////            sm -= query(sum[a], y1-1);
////            sm -= y1*(query(cnt[a], y2)-query(cnt[a], y1-1));
////            sm += (y2-y1)*(query(cnt[a], 1003)-query(cnt[a], y2));
////        }
//        printf("%lld\n", sm);
//    }
//}
//return 0;
}
