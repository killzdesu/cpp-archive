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

ll sm;
ll S;
ll s[200010];
ll mn[200010], mx[200010];

int main(){
int a, b, c, d;
cin >> N >> S;
REP(a, N){
    scanf("%d", &c);
    s[a] = c;
    sm += c;
}
REP(a, N){
    mn[a] = max((ll)0, S-(sm-s[a]));
    mx[a] = min(s[a], S-(N-1));
}
REP(a, N){

    printf("%I64d ", (mn[a]>0?mn[a]-1:0)+s[a]-mx[a]);
}

return 0;
}
