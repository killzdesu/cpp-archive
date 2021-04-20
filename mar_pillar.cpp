#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#define IT iterator
#define all(x) x.begin(),x.end()
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()
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

int i, n, k, N, M, K;
int s[1000010];
int upl[50010], upr[50010], dol[50010], dor[50010];

int main(){
freopen("C:/Users/Jui/Downloads/mar_pillar-input.txt", "r", stdin);
freopen("pillar.txt", "w", stdout);
int a, b, c, d;
int R;
cin >> R;
while(R--){
    cin >> N;
    REP(a, N){
        cin >> s[a];
        upl[a] = dol[a] = dor[a] = upr[a] = 1;
    }
    REPI(a, N-1){
        if(s[a] > s[a-1] and s[a]-s[a-1]<=2){
            upr[a] = upr[a-1]+1;
        }
        if(s[a] < s[a-1] and s[a-1]-s[a] <= 2){
            dor[a] = dor[a-1]+1;
        }
    }
    for(a=N-2;a>=0;a--){
        if(s[a] > s[a+1] and s[a]-s[a+1] <= 2){
            dol[a] = dol[a+1]+1;
        }
        if(s[a] < s[a+1] and s[a+1]-s[a] <= 2){
            upl[a] = upl[a+1]+1;
        }
    }
//    REP(a, N) printf("%d ", dol[a]);EL;
    int mx = 0;
    a = 0;
    if(mx < dol[a+1]+1){
        mx = dol[a+1]+1; i = a;
    }
    if(mx < upl[a+1]+1){
        mx = upl[a+1]+1; i = a;
    }
    for(a=1;a<N-1;a++){
        if(s[a-1] < s[a+1] and s[a+1]-s[a-1] <= 4 and s[a+1]-s[a-1] >= 2){
            if(mx < upr[a-1]+upl[a+1]+1){
                mx = upr[a-1]+upl[a+1]+1;
                i = a;
            }
        }
        else if(s[a-1] > s[a+1] and s[a-1]-s[a+1] <= 4 and s[a-1]-s[a+1] >= 2){
            if(mx < dor[a-1]+dol[a+1]+1){
                mx = dor[a-1]+dol[a+1]+1;
                i = a;
            }
        }
        if(mx < dor[a-1]+1){
            mx = dor[a-1]+1; i = a;
        }
        if(mx < upr[a-1]+1){
            mx = upr[a-1]+1; i = a;
        }
        if(mx < dol[a+1]+1){
            mx = dol[a+1]+1; i = a;
        }
        if(mx < upl[a+1]+1){
            mx = upl[a+1]+1; i = a;
        }
    }
    a = N-1;
    if(mx < dor[a-1]+1){
        mx = dor[a-1]+1; i = a;
    }
    if(mx < upr[a-1]+1){
        mx = upr[a-1]+1; i = a;
    }
    printf("%d %d\n", mx, i);
}


return 0;
}
