#include<cstdio>
#include<algorithm>

using namespace std;

int i, n, k, N;
int p[10][10], chk[20];
char s[10][10];

void bt(int x){
    if(x == N*N){

        int i, j=-1, sm=0;
        for(i=0;i<x;i++){
            if(i%N==0) j++;
            p[j][i%N] = chk[i];
            sm += chk[i];
        }

        for(i=0;i<N;i++){
            for(j=0;j<N;j++)if(p[i][j] and s[i][j] == 'X') return;
        }

        int c = 0;
        for(i=0;i<N;i++){
            c = 0;
            for(j=0;j<N;j++){
                if(p[i][j] and c==0) c = 1;
                else if(p[i][j] and c) return;
                if(s[i][j] == 'X') c = 0;
            }
        }

        for(i=0;i<N;i++){
            c = 0;
            for(j=0;j<N;j++){
                if(p[j][i] and c==0) c = 1;
                else if(p[j][i] and c) return;
                if(s[j][i] == 'X') c = 0;
            }
        }
        k = max(k, sm);

        return;
    }
    chk[x] = 0;
    bt(x+1);
    chk[x] = 1;
    bt(x+1);
}

int main(){
int a, b, c, d;
while(1){
    scanf("%d", &N);
    if(!N) return 0;
    k = 0;
    for(int i=0;i<N;i++){
        scanf("%s", s[i]);
    }
    bt(0);
    printf("%d\n", k);
}

return 0;
}
