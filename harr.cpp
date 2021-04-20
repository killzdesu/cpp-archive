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

int A[200][200];

void upd(int x, int y, int val){
    int c = y;
    while(x < 150){
        y = c;
        while(y < 150){
            A[x][y] += val;
            y += (y&-y);
        }
        x += (x&-x);
    }
}

int query(int x, int y){
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

int H[200][200];

int main(){
int a, b, c, d;
char ss;
cin >> N >> M;
REPI(a, N) REPI(b, M){
	scanf(" %c", &ss);
	H[a][b] = (ss == 'B'? -1 : 1);
}
for(i=N+M;i>1;i--){
    for(a=1;a<=N;a++){
		if(i-a > M or i-a < 1) continue;
		b = i-a;
        c = query(a, b);
        if(c != H[a][b]){
			k++;
            d = H[a][b]-c;
            upd(1, 1, d);
            upd(a+1, 1, -d);
            upd(1, b+1, -d);
            upd(a+1, b+1, d);
        }
    }
}
cout << k;

return 0;
}
