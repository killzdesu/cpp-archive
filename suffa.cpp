#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define all(x) x.begin(),x.end()
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()


using namespace std;

int i, n, k, N, M, K;
char s[100010];
int pos[100010], sa[100010];
int gap;

bool cmp(int a, int b){
    if(pos[a] != pos[b]) return pos[a] < pos[b];
    if(a+gap < N and b+gap < N) return pos[a+gap] < pos[b+gap];
    return a > b;
}

void buildSA(){
    int a;
    int tmp[N+10];
    REP(a, N) tmp[a] = 0;
    REP(a, N) pos[a] = s[a];
    REP(a, N) sa[a] = a;
    for(gap=1;;gap*=2){
        sort(sa, sa+N, cmp);
        REPI(a, N-1) tmp[a] = tmp[a-1]+cmp(sa[a-1], sa[a]);
        REP(a, N) pos[sa[a]] = tmp[a];
        if(tmp[N-1] == N-1) break;
    }
}

int lcp [100010];

void buildLCP(){
    int a, b;
    int rank[100010];
    REP(a, N) rank[sa[a]] = a;
    int h = 0;
    REP(a, N){
        b = sa[rank[a]-1];
        while(a+h < N and b+h < N and s[a+h]==s[b+h]) h++;
        lcp[rank[a]] = h;
        if(h) h--;
    }
}

int main(){
int a, b, c, d;
cin >> s;
N = strlen(s);
buildSA();
//REP(a, N) printf("%d\n", sa[a]);
buildLCP();
REP(a, N) printf("%d ", lcp[a]);
return 0;
}
