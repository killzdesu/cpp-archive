#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#define DB if(DBG)printf
#define IT iterator
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

int DBG=1;
int i, n, k, N, M, K;
ll s[100010];

set<ll> S;
set<ll>::IT it, is;

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    scanf("%lld", &s[a]);
    if(a) s[a] += s[a-1];
    if(a == N-1) break;
    if(s[a] <= 0) continue;
//    if(*(S.lower_bound(s[a])) == s[a]){
//        continue;
//    }
    if(S.insert(s[a]).second){
        it = S.find(s[a]);
        it++;
        if(it!=S.end()) S.erase(it);
    }
}
int cnt=0;
S.insert(s[a]);
for(it=S.begin();*it!=s[a];it++){
    cnt++;
}
cout << cnt+1;

return 0;
}
