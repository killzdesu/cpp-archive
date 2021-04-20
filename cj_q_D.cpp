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

int main(){
freopen("D-large.in", "r", stdin);
freopen("D-large.txt", "w", stdout);
int a, b, c, d;
int T, X;
cin >> T;
REPI(i, T){
    cin >> X >> N >> M;
    c = 0;
    if(N*M % X != 0) goto PRINT;
    if(M % X == 0) swap(N, M);
    if(X == 1) c = 1;
    if(X == 2){
        c = 1;
    }
    if(X == 3){
        if(M > 1) c = 1;
    }
    if(X == 4){
        if(M > 2) c = 1;
    }
    if(X == 5){
        if(M > 3) c = 1;
    }
    if(X == 6){
        if(M > 4) c = 1;
    }
    if(X >= 7){
        c = 0;
    }

    PRINT:;
    cout << "Case #" << i << ": " << (c?"GABRIEL":"RICHARD");EL;

}



return 0;
}
