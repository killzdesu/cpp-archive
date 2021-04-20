#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(all(x));(x).resize(distance((x).begin, unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()


using namespace std;

int i, n, k, N, M, K;
int head[100010];
int fh(int p){
    if(head[p] < 0) return p;
    head[p]  = fh(head[p]);
    return head[p];
}

void merge(int p, int q){
    if((p = fh(p)) == (q = fh(q))) return;
    if(-head[p] > -head[q]) swap(p, q);
    head[q] += head[p];
    head[p] = q;
}

int size(int p){
    return -head[fh(p)];
}

int main(){
int a, b, c, d;
cin >> N;
M = N;
REPI(a, N) head[a] = -1;
char rr[30];
REP(a, N-1){
    scanf("%d %d %s", &c, &d, rr);
    if(rr[0] == 'b'){
        merge(c, d);
    }
}
int u[100010];
fill(u, u+100004, 0);
ll sum = 0;
ll mod = 1e9+7;
REPI(a, N){
    printf("fh[%d]\n", fh(a));
    if(u[fh(a)]) continue;
    u[fh(a)] = 1;
    sum += (ll)size(a)*((ll)M-size(a))*((ll)M-size(a)-1)/2;
    sum %= mod;
    M -= size(a);
}
cout << sum;

return 0;
}
