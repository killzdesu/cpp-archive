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
char S[100010];
int rank[100100], sa[100010], pos[100010];
int gap;

bool cmp(int a, int b){
    if(pos[a] != pos[b]) return pos[a] < pos[b];
    if(a+gap < N and b+gap < N) return pos[a+gap] < pos[b+gap];
    return a > b;
}

void buildSA(){
    int a, b;
    int tmp[100010];
    REP(a, N){
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

int main(){
int a, b, c, d;
cin >> S;
N = strlen(S);
buildSA();
REP(a, N) printf("%d\n", sa[a]);

return 0;
}
