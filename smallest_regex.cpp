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
int dp[110][510];

string R;

void copy_last(int x){
    int a;
    REP(a, 505){
        dp[x][a] = dp[x-1][a];
    }
}

void inc(int x, int val){
    int a;
    REP(a, 505){
        if(dp[x-1][a] and a+val < 505) dp[x][a+val] = 1;
    }
}

int main(){
int a, b, c, d;
cin >> K;
cin >> R;
string t;
char u;
stack<int> A;
dp[0][0] = 1;
REPI(a, R.length()){
    u = R[a];
    if('a' <= u and u <= 'z'){
        if(A.empty() or A.top() == 2){
            t.pb(u);
            A.push(1);
            copy_last(a);
        }
        else if(A.top() == 1){
            inc(a, 1);
            t[0] = u;
        }
    }
    else if(u == '('){
        A.push(2);
    }
}


return 0;
}
