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
#define mp make_pair
#define pii pair<int, int>
#define ll long long

using namespace std;

int i, n, k, N, M, K;

long long t[100010], sm;

void m_sort(ll s[], int lo, int hi){
    int mi = (lo+hi)/2;
    if(hi-lo==1) return;
    m_sort(s, lo, mi);
    m_sort(s, mi, hi);

    int i=lo, j=mi, cnt=0;
    while(i < mi and j < hi){
        if(s[i] <= s[j]){
            t[cnt++] = s[i++];
        }
        else {
            sm += (mi-i);
            t[cnt++] = s[j++];
        }
    }
    while(i < mi){
        t[cnt++] = s[i++];
    }
    while(j < hi){
        t[cnt++] = s[j++];
    }
    for(i=lo;i<hi;i++) s[i] = t[i-lo];
}

ll s[100010];
int p[100010];
pair<ll, int> z[100010];

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    scanf("%lld", &s[a]);
}
m_sort(s, 0, N);

cout << sm;

return 0;
}
