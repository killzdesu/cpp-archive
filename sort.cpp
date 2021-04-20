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
int s[100010];
//
//void qsort(int *s, int lo, int hi){
//    int pv, l, r;
//    //pv = s[lo+(hi-lo)/2];
//    pv = s[lo];
////    swap(s[lo], s[pv]);
////    pv = lo;
//    l = lo; r = hi-1;
//    while(l <= r){
//        while(s[l] < pv) l++;
//        while(s[r] > pv) r--;
//        if(l <= r) swap(s[l++], s[r--]);
//    }
////    printf("%d %d\n", l, r);
//    if(lo < r) qsort(s, lo, r+1);
//    if(l < hi-1) qsort(s, l, hi);
//}

int tmp[100010];

void msort(int *s, int lo, int hi){
    if(lo == hi-1) return ;
    //int tmp[hi-lo+1];
    int mi = (lo+hi)/2, a=lo, b=mi, i=0;
    msort(s, lo, mi);
    msort(s, mi, hi);

//    inplace_merge(s+lo, s+mi, s+hi);

    while(a < mi and b < hi){
        if(s[a] < s[b]){
            tmp[i] = s[a];
            i++; a++;
        }
        else {
            tmp[i] = s[b];
            i++; b++;
        }
    }
    while(a < mi){
        tmp[i] = s[a];
        i++; a++;
    }
    while(b < hi){
        tmp[i] = s[b];
        i++; b++;
    }

    for(a=lo;a<hi;a++){
        s[a] = tmp[a-lo];
    }

}

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    scanf("%d", &s[a]);
}
msort(s, 0, N);
REP(a, N){
    printf("%d\n", s[a]);
}

return 0;
}
