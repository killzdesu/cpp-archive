#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#include<stack>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back

using namespace std;

struct trip{
    int a1, a2, a3;
}tp;

trip mt(int a, int b, int c){
    tp.a1 = a;
    tp.a2 = b;
    tp.a3 = c;
    return tp;
}

struct node{
    int t;
    trip bt;
    char C;
};
node dp[42][42][42];

int i, n, k, N, M, K;
int tab[5][5], dummy[5][5];

void run(int x, int y, int z){
    int a, b, c, lim=20;
//    printf("%d %d %d \n", x, y, z);
    if(x >= lim or y>=lim or z>=lim) return;
    // go a b c
    for(a=0;a<3;a++){
        if(x >= tab[a][0] and y >= tab[a][1] and z >= tab[a][2]){
            if(dp[x+dummy[a][0]-tab[a][0]][y+dummy[a][1]-tab[a][1]][z+dummy[a][2]-tab[a][2]].t > dp[x][y][z].t+1){
                dp[x+dummy[a][0]-tab[a][0]][y+dummy[a][1]-tab[a][1]][z+dummy[a][2]-tab[a][2]].t = dp[x][y][z].t+1;
//                dp[x+dummy[a][0]-tab[a][0]][y+dummy[a][1]-tab[a][1]][z+dummy[a][2]-tab[a][2]].s = dp[x][y][z].s;
//                dp[x+dummy[a][0]-tab[a][0]][y+dummy[a][1]-tab[a][1]][z+dummy[a][2]-tab[a][2]].s.pb((a+'a'));
                dp[x+dummy[a][0]-tab[a][0]][y+dummy[a][1]-tab[a][1]][z+dummy[a][2]-tab[a][2]].bt = mt(x, y, z);
                dp[x+dummy[a][0]-tab[a][0]][y+dummy[a][1]-tab[a][1]][z+dummy[a][2]-tab[a][2]].C = a+'a';
                run(x+dummy[a][0]-tab[a][0], y+dummy[a][1]-tab[a][1], z+dummy[a][2]-tab[a][2]);
            }
        }
    }
    //return ;
    //go A B C
    for(a=0;a<3;a++){
        if(x >= dummy[a][0] and y >= dummy[a][1] and z >= dummy[a][2])
        if(x+tab[a][0]-dummy[a][0] <= lim and y+tab[a][1]-dummy[a][1] <= lim and z+tab[a][2]-dummy[a][2] <= lim){
            if(dp[x+tab[a][0]-dummy[a][0]][y+tab[a][1]-dummy[a][1]][z+tab[a][2]-dummy[a][2]].t > dp[x][y][z].t+1){
                dp[x+tab[a][0]-dummy[a][0]][y+tab[a][1]-dummy[a][1]][z+tab[a][2]-dummy[a][2]].t = dp[x][y][z].t+1;
//                dp[x+tab[a][0]-dummy[a][0]][y+tab[a][1]-dummy[a][1]][z+tab[a][2]-dummy[a][2]].s = dp[x][y][z].s;
//                dp[x+tab[a][0]-dummy[a][0]][y+tab[a][1]-dummy[a][1]][z+tab[a][2]-dummy[a][2]].s.pb((a+'A'));
                dp[x+tab[a][0]-dummy[a][0]][y+tab[a][1]-dummy[a][1]][z+tab[a][2]-dummy[a][2]].bt = mt(x, y, z);
                dp[x+tab[a][0]-dummy[a][0]][y+tab[a][1]-dummy[a][1]][z+tab[a][2]-dummy[a][2]].C = a+'A';
                run(x+tab[a][0]-dummy[a][0], y+tab[a][1]-dummy[a][1], z+tab[a][2]-dummy[a][2]);
            }
        }
    }
}

int main(){
int a, b, c, d;
REP(a, 3){
    REP(b, 3){
        scanf("%d", &tab[a][b]);
    }
    dummy[a][a] = 1;
}
cin >> N;
int r;
int wx, wy, wz, X, Y, Z;
stack<char> ans;
REP(r, N){
    REP(a, 40)REP(b, 40)REP(c, 40){
        dp[a][b][c].t = 2e9;
        dp[a][b][c].C = '-';
    }
    scanf("%d %d %d %d %d %d", &X, &Y, &Z, &wx, &wy, &wz);
    dp[X][Y][Z].t = 0;
    dp[X][Y][Z].C = '*';
//    dp[X][Y][Z].s.clear();
    run(X, Y, Z);
    if(dp[wx][wy][wz].t < 2e8){
        printf("%d ", dp[wx][wy][wz].t);
        a = wx; b = wy; c = wz;
        while(dp[a][b][c].C != '*'){
            ans.push(dp[a][b][c].C);
            tp = dp[a][b][c].bt;
            a = tp.a1;
            b = tp.a2;
            c = tp.a3;
        }
        while(!ans.empty()){
            printf("%c", ans.top());
            ans.pop();
        }
        printf("\n");
    }
    else printf("NO SOLUTION\n");
}


return 0;
}
