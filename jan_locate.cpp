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
int s[100][100];
int x, y;
int mx;

void upd(int a, int b, int c){
    if(c > mx){
        mx = c;
        x = a;
        y = b;
    }
}

int main(){
    freopen("C:\\Users\\Jui\\Downloads\\jan_locate-input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

int a, b, c, d;
int T;
cin >> T;
while(T--){
    mx = -2;
    cin >> N >> M;
    REP(a, N) REP(b, M){
        cin >> s[a][b];
    }
    REP(a, N) REP(b, M){
        if(a != N-1){
            if(fabs(s[a][b]-s[a+1][b]) <= 10){
                upd(a, b, s[a][b]+s[a+1][b]);
            }
        }
        if(b != M-1){
            if(fabs(s[a][b]-s[a][b+1]) <= 10){
                upd(a, b, s[a][b]+s[a][b+1]);
            }
        }
    }
//    printf("%d -- ", mx);
    printf("%d %d\n", x+1, y+1);
}



return 0;
}
