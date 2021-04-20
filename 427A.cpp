#include<cstdio>

int main(){
int k=0, n, c, p=0;
scanf("%d", &n);
while(n--){
    scanf("%d", &c);
    if(c <= -1){
        if(k == 0){
            p++;
        }
        else {
            k--;
        }
    }
    else k+=c;
}
printf("%d", p);
}
