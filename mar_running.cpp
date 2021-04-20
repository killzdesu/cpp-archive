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

int s[10000];

int main(){
freopen("C:/Users/Jui/Downloads/mar_running-input.txt", "r", stdin);
freopen("runn.txt", "w", stdout);
int a, b, c, d;
int R;
cin >> R;
while(R--){
    cin >> M >> N >> K;
    fill(s, s+2001, 0);
    REP(a, N){
        scanf("%d", s+a);
        s[a+N] = s[a]+M;
    }
    K%=M;
    c = -1;
    REP(a, N){
        REP(b, N){
            if(s[a+b]-s[a] == K){
                c = a+1;
                goto ans;
            }
        }
    }
    ans:;
    printf("%d\n", c);
}



return 0;
}
