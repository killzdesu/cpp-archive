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
#include<regex>


using namespace std;

int i, n, k, N, M, K;

string S, R;


int main(){
int a, b, c, d;
int T;
cin >> T;
while(T--){
    cin >> N;
    cin >> R;
    REP(a, R.length()){
        if('a' <= R[a] and R[a] <= 'z') R[a] = 'a';
    }
    S.clear();
    regex r(R);
    REPI(a, N-1) S.pb('a');
    for(;a<501;a++){
        S.pb('a');
        if(regex_match(S, r)){
            break;
        }
    }
    printf("%d\n", a<501?a:-1);
}


return 0;
}
