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
int pos[100010], arr[100010];


int main(){
int a, b, c, d;
cin >> N >> M >> K;
REP(a, N){
    scanf("%d", &arr[a]);
    pos[arr[a]] = a;
}
ll sm=0;
REP(a, M){
    scanf("%d", &c);
    sm += pos[c]/K+1;
    if(pos[c] == 0) continue;
    pos[arr[pos[c]-1]]++;
    pos[c]--;
    swap(arr[pos[c]], arr[pos[c]+1]);
}
cout << sm;

return 0;
}
