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
deque<int> Q;

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    cin >> c;
    Q.pb(c);
}
sort(Q.begin(), Q.end(), greater<int>() );
//REP(a, N){
//    printf("%d ", Q[a]);
//}
long long sm = 0;
while(Q.size() >= 5){
    sm+=Q.front();
    Q.pop_front();
    Q.pop_front();
    sm+=Q.back();
    Q.pop_back();
    sm+=Q.back();
    Q.pop_back();
    sm+=Q.back();
    Q.pop_back();
}
while(!Q.empty()){
    sm+=Q.back();
    Q.pop_back();
}
cout << sm;
return 0;
}
