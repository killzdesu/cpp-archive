#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin, unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;

int i, n, k, N, M, K;

string S;
int pos[1000100], r[1000100], sa[1000100];
int gap;

bool cmp(int a, int b){
    if(pos[a] != pos[b]) return pos[a] < pos[b];
    if(a+gap < N and b+gap < N) return pos[a+gap] < pos[b+gap];
    return a > b;
}

int tmp[1000100];

void buildSA(){
    int a;
    N = S.length();
    REP(a, N){
        tmp[a] = 0;
        sa[a] = a;
        pos[a] = S[a];
    }
    for(gap=1;;gap*=2){
        sort(sa, sa+N, cmp);
        REP(a, N-1) tmp[a+1] = tmp[a] + cmp(sa[a], sa[a+1]);
        REP(a, N) pos[sa[a]] = tmp[a];
        if(tmp[N-1] == N-1) break;
    }
}

int lcp[1000100];

void buildLCP(){
    int h=0, a, b;
    REP(a, N) {
        r[sa[a]] = a;
    }
    lcp[0] = 0;
    REP(a, N){
        if(r[a] == 0) continue;
        b = sa[r[a]-1];
        while(a+h < N and b+h < N and S[a+h] == S[b+h]) h++;
        lcp[r[a]] = h;
        if(h) h--;
    }
}

struct sparse_table{
    int a, b, N, LN, c;
    int M[1000010][21];

    void init(int N){
        LN = (int)ceil(log2(N));
        REP(a, N){
            M[a][0] = a;
        }
        REPI(b, LN){
            c = (1<<b);
            for(a=0;a+c-1<N;a++){
                if(lcp[M[a][b-1]] < lcp[M[a+c/2][b-1]]) M[a][b] = M[a][b-1];
                else M[a][b] = M[a+c/2][b-1];
            }
        }
    }

    int query(int lo, int hi){
        if(lo > hi) return 0;
        int k = (int)floor(log2(hi-lo+1));
        if(lcp[M[lo][k]] < lcp[M[hi-(1<<k)+1][k]]) return lcp[M[lo][k]];
        else return lcp[M[hi-(1<<k)+1][k]];
    }
}sp;

char ss[1000004];

int main(){
int a, b, c, d;
cin >> S;
buildSA();
buildLCP();
REP(a, N) ss[a] = S[a];
ss[N] = '\0';
sp.init(N+5);
//REP(a, N) printf("%d ", lcp[a]); EL;
//cout << sp.query(1, 2);
//return 0;
REP(i, N){
    a = r[i];
    if(a == N-1) continue;
    b = r[i]+1;
    if(r[i]+1 == r[0]) b++;
    if(b == N-1) continue;
    c = 0;
//    if(lcp[r[i]+1] >= N-a) break;
//    printf("%d: %d %d = %d\n", i, r[i], r[0], sp.query(min(r[i], r[0]), max(r[i], r[0])));
    if(lcp[b] >= N-i and sp.query(min(r[i], r[0])+1, max(r[i], r[0])) >= N-i) break;
}
printf("%s", i!=N?ss+i:"Just a legend");

return 0;
}
