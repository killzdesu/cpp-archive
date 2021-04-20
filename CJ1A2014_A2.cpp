#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long

using namespace std;

map<string, bool> m;
int i, n, k, N, M, K;
string s[200], t[200];

string xx(string A, string B){
    string C;
    for(int a=0;a<B.length();a++){
        if(A[a] == B[a]) C.push_back('0');
        else C.push_back('1');
    }
    return C;
}

int main(){
        freopen("C:\\Users\\Jui\\Downloads\\A-large-practice.in", "r", stdin);
    freopen("ggg.txt", "w", stdout);

int a, b, c, d;
int T, R;
string dum;
cin >> T;
int mn;
REPI(R, T){
    cin >> N >> M;
    m.clear();
    REP(a, N){
        cin >> s[a];
        m[s[a]] = 1;
    }
    mn = 2e9;
    REP(a, N) cin >> t[a];
    REP(a, N){
        dum = xx(s[a], t[0]);
//        printf("dum[%s] :: ", dum.c_str());
        c = 0;
        REP(b, N){
            if(m[xx(t[b], dum)] == 0){ c = 1; break; }
        }
//        printf("%d\n", c);
        if(c == 1) continue;
        i = 0;
        for(b=0;b<M;b++){
            if(dum[b] == '1') i++;
        }
        mn = min(mn, i);
    }
    printf("Case #%d: ", R);
    if(mn > 1000) printf("NOT POSSIBLE\n");
    else printf("%d\n", mn);

}



return 0;
}
