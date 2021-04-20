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

int i, n, k, N, M, K;


//float m[5000][5000];
short dp[5001][5001];
int s[5001];
vector<pair<int, pii> > bk, B;
vector<short> og;


double mm(int a, int b){
    return (double)(s[b]-s[a])/((double)b-a);
}

bool cmp(int a, int b){
    return mm(k, a) < mm(k, b);
}

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    scanf("%d", &s[a]);
}
REP(a, N) for(b=0;b<N;b++){
//    m[a][b] = (double)(s[b]-s[a])/((double)b-a);
    dp[a][b] = 2;
}

REP(a, N){
    B.clear();
    for(b=0;b<a;b++){
        B.pb(mp(dp[b][a], mp(b, a)));
    }
    sort(B.begin(), B.end(), greater<pair<int, pii> >());
    i = 0;
    og.clear();
    for(b=a+1;b<N;b++) og.pb(b);
    k = a;
    sort(og.begin(), og.end(), cmp);
    for(b=0;b<og.size();b++){
        c = og[b];
        while(i < B.size() and mm(B[i].se.fi, B[i].se.se) < mm(a, c)) i++;
        if(i < B.size()){
            dp[a][c] = max((int)dp[a][c], B[i].fi+1);
        }
    }
}
int mx = 0;
REP(a, N) REP(b, N){
    mx = max(mx, (int)dp[a][b]);
}
cout << mx;
return 0;
}
