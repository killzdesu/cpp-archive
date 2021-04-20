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

int main(){
int a, b, c, d;
int B, E;
cin >> B >> E;
cin >> N >> d;
int s[1000];
s[1] = B;
s[N] = E;
for(a=2;a<N;a++){
    if(s[a-1] <= E){
        s[a] = s[a-1]+d;
    }
    else {
        s[a] = min(s[a-1]+d, (N-a)*d+E);
    }
}
k = 0;
REPI(a, N){
//    printf("%d ", s[a]);
    k += s[a];
}
cout << k;

return 0;
}
