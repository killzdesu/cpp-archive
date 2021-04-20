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

int F[20010];

void build_failure_function(char p[]) {

    int i, j;
    int m = strlen(p);
    F[0] = F[1] = 0; // always true

    for(i=2; i<=m; i++) {
        j = F[i-1];
        while(1) {
            if(p[j] == p[i-1]) {
                F[i] = j+1;
                break;
            }
            if(j == 0) {
                F[i] = 0;
                break;
            }
            j = F[j];
        }
    }
}

int kmp(char* t, int N, char *p, int M){
    build_failure_function(p);
    int now = 0;
    int i = 0, cnt = 0;
    while(i < N){
        if(t[i] == p[now]){
            i++;
            now++;
            if(now == M) cnt++;
        }
        else if(now > 0) now = F[now];
        else i++;
    }
    return cnt;
}

int main(){
srand(time(0));
int a, b, c, d;
N = 1000000;
M = 10000;
k = rand()%(N/M+1);
dump(k);

string P, T;
REP(a, M){
	P.pb(rand()%26+'a');
}
REP(a, N) T.pb(rand()%26+'a');
REP(a, k){
	i = rand()%(N-M+1);
	i = rand()%(N-M+1);
    for(b=0;b<M;b++){
		T[b+i] = P[b];
    }
}
//dump(T);
//dump(P);
cout << kmp((char*)T.c_str(), N, (char*)P.c_str(), M);


return 0;
}
