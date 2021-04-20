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
cin >> N;
if(N == 1){
    printf("1\n1");
}
else if(N == 2){
    printf("1\n1");
}
else if(N == 3){
    printf("2\n1 3");
}
else if(N == 4){
    printf("4\n2 4 1 3");
}
else{
    int s[6000];
    printf("%d\n", N);
    i = 0;
    for(a=1;a<=N;a+=2){
        s[i++] = a;
    }
    for(a=2;a<=N;a+=2){
        s[i++] = a;
    }
    REP(a, N) printf("%d ", s[a]);
}



return 0;
}
