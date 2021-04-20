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
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

int DBG=1;
int i, n, k, N, M, K;
int s[100010];

int main(){
int a, b, c, d;
cin >> N >> K;
REP(a, N) cin >> s[a];
sort(s, s+N, greater<int>() );
REP(a, N){
    if(s[a] > 0 and s[a] >= s[K-1]) i++;
}
cout << i;
return 0;
}
