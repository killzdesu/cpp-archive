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

int s[1010];

int main(){
freopen("A-large.in", "r", stdin);
freopen("A-large.out", "w", stdout);
int a, b, c, d;
int T;
cin >> T;
int ans;
REPI(i, T){
    cin >> N;
    k = 0;
    ans = 0;
    REP(a, N+1){
        scanf("%1d", &s[a]);
        if(k < a){
            ans += a-k;
            k = a;
        }
        k += s[a];
    }
    printf("Case #%d: %d\n", i, ans);
}



return 0;
}
