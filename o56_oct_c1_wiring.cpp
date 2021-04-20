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

int i, n, k, N, M, K, err;
int up[100010], down[100010];
int h[100010];

void merge(int x, int y){
    h[y] = h[x];
}

int head(int x){
    if(h[x] != x){
        h[x] = head(h[x]);
    }
    return h[x];
}

int li[100010];

int main(){
int a, b, c, d;
int R, mx;
cin >> R;
while(R--){
    mx = 0;
    cin >> N;
    REPI(a, N+5){
        up[a] = down[a] = 0;
        li[a] = -1;
        h[a] = a;
    }
    REPI(a, N){
        scanf("%d", &c);
        mx = max(mx, c);
        if(!c) continue;
        up[c] = a;
    }
    REPI(a, N){
        scanf("%d", &c);
        if(!c) continue;
        down[c] = a;
    }
    REPI(a, mx){
        if(up[a] != down[a])
            li[up[a]] = down[a];
    }
    k = 1;
    err = 0;
//    REPI(a, N) printf("%d", li[a]);
//    printf("\n");
    REPI(a, N){
        if(li[a] != -1){
            if(head(a) == head(li[a])){
                err = 1;
                break;
            }
            merge(a, li[a]);
        }
    }
    if(err) cout << "NO\n";
    else cout << "YES\n";
}



return 0;
}
