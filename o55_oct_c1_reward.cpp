#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back

using namespace std;

int i, n, k, N, M, K;
/*
binary_search(lo, hi, p):
   while lo < hi:
      mid = lo + (hi-lo)/2
      if p(mid) == true:
         hi = mid
      else:
         lo = mid+1

   if p(lo) == false:
      complain                // p(x) is false for all x in S!

   return lo
*/
int s[600000];
int main(){
int a, b, c, d;
cin >> N >> M;
int mx = 0;
REP(a, N){
    scanf("%d", &s[a]);
    mx = max(mx, s[a]);
}
int lo=1, hi = mx+1, mi;
while(lo < hi){
    mi = lo+(hi-lo)/2;
    c = 0;
    REP(a, N){
        c += s[a]/mi;
        if(s[a]%mi) c++;
    }
    if(c <= M)hi = mi;
    else lo = mi+1;
    //printf("%d %d\n", lo, hi);
}
cout << lo;


return 0;
}
