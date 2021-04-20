#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#include<set>
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

int h[100010];

int find_head(int x){
    if(h[x] != x){
        h[x] = find_head(h[x]);
    }
    return h[x];
}

vector<int> v[10];
int s[100010];

int main(){
int a, b, c, d;
cin >> N;
REPI(a, N){
    h[a] = a;
    scanf("%d", &s[a]);
}
REP(a, N-2){
    scanf("%d %d", &c, &d);
    h[find_head(d)] = find_head(c);
}
c = find_head(1);
REPI(a, N){
    if(find_head(a) == c)v[0].pb(s[a]);
    else v[1].pb(s[a]);
}
//sort(v[0].begin(), v[0].end());
sort(v[1].begin(), v[1].end());
//REP(a, v[0].size())
//    printf("%d ", v[0][a]);
//printf("\n");
//REP(a, v[1].size())
//    printf("%d ", v[1][a]);
//printf("\n");
int sm = 2e9;
std::vector<int>::iterator p,up;
for(a=0;a<v[0].size();a++){
    p = lower_bound(v[1].begin(), v[1].end(), v[0][a]);
    if(p != v[1].end())c = fabs(v[0][a]-*p);
    else c = 2e8;
    if(p != v[1].begin()){
        p--;
        d = fabs(v[0][a]-*p);
    }
    else d = 2e8;
    sm = min(sm, min(c, d));
}
cout << sm;
return 0;
}
