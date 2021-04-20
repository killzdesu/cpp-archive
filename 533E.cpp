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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define dump(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;

int i, n, k, N, M, K;

char s[100010], t[100010];

int main(){
int a, b, c, d;
cin >> N;
cin >> s >> t;
int miss=0;
REP(a, N){
    if(s[a] != t[a] and miss != 0 and s[a-1] == t[a-1]) {
        cout << "0"; return 0;
    }
    if(s[a] != t[a]) miss++;
    if(miss == 1) i = a;
}
if(miss == 1){
    cout << "2";
    return 0;
}
if(s[i] == t[i+1]){
    int cnt = 0;
    for(a = 0;a<miss-1;a++){
        if(s[a+i] == t[a+i+1]) cnt++;
    }
    if(cnt == miss-1){
        cout << "1";
        return 0;
    }
}

return 0;
}
