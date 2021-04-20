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
const ll mod = 1000000007;
char s[11][1010];
int f[11][1010];
int g[11][1010];
int cnt;

void test(int x, int y){
    if(x < 0 or y < 0 or x >= N or y >= M) return;
    if(f[x][y] == 0) return;
    if(g[x][y] == 1) return;
    g[x][y] = 1;
    test(x+1, y);
    test(x, y+1);
    test(x, y-1);
    test(x-1, y);
}

void test1(int x, int y){
    if(x < 0 or y < 0 or x >= N or y >= M) return;
    if(s[x][y] == '#') return;
    if(g[x][y] == 1) return;
    g[x][y] = 1;
    i++;
    test1(x+1, y);
    test1(x, y+1);
    test1(x, y-1);
    test1(x-1, y);
}

//ll pas[2][100010];
//
//ll Pas(int x, int y){
//	int a, b;
//    REP(a, N+2) pas[0][a] = pas[1][a] = 0;
//    int now=0, prev=1;
//    REPI(a, x){
//		REP(b, a+1){
//            if(b == 0 or b == a) pas[now][b] = 1;
//            else pas[now][b] = ( pas[prev][b] + pas[prev][b-1] ) % mod;
//		}
//		swap(now, prev);
//    }
//    return pas[prev][y];
//}

void run(int x, int y){
    if(x == N-1 and y == M){
        int a, b;
        REP(a, N) REP(b, M) g[a][b] = 0;
        k = 0;
        for(a=0;a < N;a++){
			for(b=0;b<M;b++){
                if(g[a][b] == 0 and f[a][b] == 1){
					k++;
                    test(a, b);
                }
			}
        }
        if(k == 1){
//			REP(a, N){
//				REP(b, M){
//					if(s[a][b] == '#') printf("#");
//					else {
//						if(f[a][b] == 1) printf("O");
//						else printf(".");
//					}
//				}EL;
//			}
            cnt++;
        }
        return ;
    }
    if(y == M){
		x++; y = 0;
    }
    if(s[x][y] == '#'){
        f[x][y] = 0;
        run(x, y+1);
    }
    else {
        f[x][y] = 0;
        run(x, y+1);
        f[x][y] = 1;
        run(x, y+1);
    }
}

int main(){
int a, b, c, d;
cin >> N >> M;
REP(a, N) scanf("%s", s[a]);
if(N*M < 22) goto Sol20;
else if(N == 1) goto Sol1;
else return 0;
Sol20:;
run(0, 0);
cout << cnt;
return 0;
Sol1:;
vector<ll> z;
k = 0;
REP(a, N){
	REP(b, M){
        if(g[a][b] == 0){
			++k;
			i = 0;
			test1(a, b);
            z.pb(i);
        }
	}
}
ll sm = 0;
for(auto x: z){
//	printf("%d ", x);
	sm += x*(x+1)/2;
	sm %= mod;
}
cout << sm;
return 0;
}
