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

char s[100010];
int z[100010];

int main(){
int a, b, c, d;
cin >> s;
N = strlen(s);
z[0] = 0;
int L = 0, R = 0;
REPI(a, N-1){
    if(a > R){
        L = R = a;
        while(R < N and s[R-L] == s[R]) R++;
        z[a] = R-L; R--;
    }
    else {
        k = a-L;
        if(z[k] < R-a+1) z[a] = z[k];
        else {
            L = a;
            while(R < N and s[R-L] == s[R]) R++;
            z[a] = R-L; R--;
        }
    }
}
REP(a, N) cout << z[a];

return 0;
}
