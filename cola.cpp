#include<cstdio>

int n, k;
long long sm;

int main(){
int a, b, c;
while(scanf("%d", &n) == 1){
    sm = 0;
    k = 0;
    while(1){
        sm += n;
        n -= k;
        if(n <= 1)break;
        k = 0;
        if(n%3 == 0){
            n/=3;
        }
        else if(n%3 == 1){
            sm -= 1;
            n = n/3+1;
        }
        else if(n%3 == 2){
            n = (n+1)/3;
            k = 1;
        }
    }printf("%lld\n", sm);
}
return 0;
}
