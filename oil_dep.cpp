#include<cstdio>
#include<iostream>

char s[200][200];
int chk[200][200];
int n, k, m;

void clear(){
    k = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            chk[i][j] = 0;
        }
    }
}

void dfs(int x, int y){
    if(x < 0 or x >= n or y < 0 or y >= m)return;
    if(chk[x][y] or s[x][y]!='@') return;
    chk[x][y] = k;
    for(int i=-1;i<2;i++)for(int j=-1;j<2;j++)
        dfs(x+i, y+j);
}

int main(){
int a, b, c;
while(1){
    scanf("%d %d", &n, &m);
    if(!n and !m) return 0;

    clear();

    for(int i=0;i<n;i++)
        scanf("%s", s[i]);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!chk[i][j] and s[i][j] == '@'){
                k++;
                dfs(i, j);
            }
        }
    }
    printf("%d\n", k);
}


}
