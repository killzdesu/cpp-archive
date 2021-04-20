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

int **s;
int **own1;
int **own2;
int **vs;
deque<int> Q;

int fail[100010];

int dfs(int x, int y, int di, int c){
	if(x < 0 or x >= N or y < 0 or y >= M) return 1;
	if(s[x][y] != 0){
		return 1;
	}
	if(di == 1 and own1[x][y] == 0) return 0;
    if(di == 2 and own2[x][y] == 0) return 0;

    if(vs[x][y] == c){
		return 1;
    }
    vs[x][y] = c;

    if(dfs(x+1, y, di, c) == 0) return 0;
    if(dfs(x, y+1, di, c) == 0) return 0;
    if(dfs(x-1, y, di, c) == 0) return 0;
    if(dfs(x, y-1, di, c) == 0) return 0;
    return 1;
}

int FAIL;

int main(){
//freopen("light.txt", "r", stdin);
int a, b, c, d;
int TEST;
cin >> TEST;
while(TEST--){
	FAIL = 0;
	cin >> N >> M;
	fill(fail, fail+100005, 0);
    s = new int*[N+2];
    own1 = new int*[N+2];
    own2 = new int*[N+2];
    vs = new int*[N+2];
	REP(a, N){
		s[a] = new int[M+2];
		own1[a] = new int[M+2];
		own2[a] = new int[M+2];
		vs[a] = new int[M+2];
	}
    REP(a, N) REP(b, M) vs[a][b] = 0;
    REP(a, N) REP(b, M){
		scanf("%d", &s[a][b]);
		own1[a][b] = s[a][b];
		own2[a][b] = s[a][b];
    }
//    REP(a, N) REP(b, M) cout << s[a][b] << " \n"[b==M-1];
    REP(a, N){
        REP(b, M){
			if(fail[s[a][b]] == 2) fail[s[a][b]] = 0;
        }
    	Q.clear();
		REP(b, M){
            if(s[a][b] == 0){
				if(!Q.empty()){
					own1[a][b] = Q.back();
				}
            }
            else {
				if(fail[s[a][b]]){
					if(fail[s[a][b]] == 2) fail[s[a][b]] = 1;
//					printf("%d FAIL %d\n", fail[s[a][b]], s[a][b]);
				}
				if(!Q.empty()){
                    if(Q.back() == s[a][b]){
                        Q.pop_back();
                    }
                    else{
						while(!Q.empty()){
							if(!fail[Q.back()])
								fail[Q.back()] = 2;
							Q.pop_back();
						}
                        Q.pb(s[a][b]);
                    }
				}
				else {
                    Q.pb(s[a][b]);
				}
            }
//            printf(">> ");
//            for(int x: Q){
//				printf("%d ", x);
//            }EL;
		}
		REP(b, M){
			if(s[a][b] != 0 ) continue;
			if(own1[a][b] != 0 and fail[own1[a][b]]) own1[a][b] = 0;
		}
    }

    REP(b, M){
        REP(a, N){
			if(fail[s[a][b]] == 2) fail[s[a][b]] = 0;
        }
    	Q.clear();
		REP(a, N){
            if(s[a][b] == 0){
				if(!Q.empty()){
					own2[a][b] = Q.back();
				}
            }
            else {
				if(fail[s[a][b]]){
					if(fail[s[a][b]] == 2) fail[s[a][b]] = 1;
//					printf("%d FAIL %d\n", fail[s[a][b]], s[a][b]);
				}
				if(!Q.empty()){
                    if(Q.back() == s[a][b]){
                        Q.pop_back();
                    }
                    else{
						while(!Q.empty()){
							if(!fail[Q.back()])
								fail[Q.back()] = 2;
							Q.pop_back();
						}
                        Q.pb(s[a][b]);
                    }
				}
				else {
                    Q.pb(s[a][b]);
				}
            }
//            printf(">> ");
//            for(int x: Q){
//				printf("%d ", x);
//            }EL;
		}
		REP(a, N){
			if(s[a][b] != 0 ) continue;
			if(own2[a][b] != 0 and fail[own2[a][b]]) own2[a][b] = 0;
		}
    }

    c = 1;
    REP(a, N) REP(b, M){
//    	printf("%d %d: ", a, b);
//    	for(int x: own[a][b]) printf("%d ", x); EL;
		if(!own1[a][b] and !own2[a][b]){
			c = 0;
//            printf("::: %d %d\n", a, b);
            FAIL = 1;
            goto dofail;
		}
    }
//	REP(a, N) {
//		REP(b, M){
//			printf("%d ", own1[a][b]);
//		}EL;
//	}
//	printf("---------------\n");
//	REP(a, N) {
//		REP(b, M){
//			printf("%d ", own2[a][b]);
//		}EL;
//	}
    REP(a, N) REP(b, M){
        if(s[a][b] != 0) continue;
        c = dfs(a, b, 1, 1);
        d = dfs(a, b, 2, 2);
        if(c==0 and d==0){
//            printf("fail at %d %d : %d %d\n", a, b, c, d);
			FAIL = 1;
			goto dofail;
        }
    }

	dofail:;
    if(FAIL == 1){
		printf("NO\n");
    }
    else printf("YES\n");
//	printf("-------- %d ---------\n", ++K);
}



return 0;
}
