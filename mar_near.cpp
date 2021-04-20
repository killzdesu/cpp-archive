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
int u[1000010];
int s[10010];

int main(){
//freopen("C:/Users/Jui/Downloads/mar_near-input.txt", "r", stdin);
//freopen("near.txt", "w", stdout);
int a, b, c, d;
int R, Q;
cin >> R;
while(R--){
    cin >> N >> M >> Q;
    fill(u, u+1000002, 0);
    REP(a, M){
        scanf("%d", s+a);
        u[s[a]] = 1;
    }
    while(Q--){
        cin >> c;
        d = 0;
        REP(a, M){
            if(s[a]-c >= 0 and u[s[a]-c] == 1){
                d++;
            }
        }
        printf("%d", d);
        printf("%c", Q==0?'\n':' ');
    }
}



return 0;
}
