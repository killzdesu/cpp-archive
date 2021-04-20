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

int mx[1010];
int sum[1001][100002];
short cnt[1001][100002];

void upd(int *A, int t, int val){
    while(t < 1005){
        A[t] += val;
        t += (t&-t);
    }
}

int query(int *A, int t){
    int sm = 0;
    while(t > 0){
        sm += A[t];
        t -= (t&-t);
    }
    return sm;
}

int main(){
int a, b, c, d;
int x1, y1, x2, y2;
int Q;
cin >> Q >> c >> N >> M;
Q += c;
return 0;
while(Q--){
    scanf("%d", &c);
    if(c == 1){
        scanf("%d %d", &c, &d);
        maxa(mx[c], d);
        upd(sum[c], d, d);
//        upd(cnt[c], d, 1);
    }
    else {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        ll sm = 0;
        for(a=x1;a<=x2;a++){
            sm += query(sum[a], y2);
            sm -= query(sum[a], y1-1);
            sm -= y1*(query(cnt[a], y2)-query(cnt[a], y1-1));
            sm += (y2-y1)*(query(cnt[a], 1003)-query(cnt[a], y2));
        }
        printf("%I64d\n", sm);
    }
}

return 0;
}
