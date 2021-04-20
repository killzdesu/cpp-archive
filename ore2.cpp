#include<cstdio>
#include<algorithm>

long long s[1000005], sm, dp[1000005];
int n, k;

int main(){
int a, b, c, l=0;
scanf("%d %d", &n, &k);
for(a=1;a<=n;a++){
    scanf("%lld", &s[a]);
    s[a] += s[a-1];
    sm = s[a]-s[l];

    while(s[a]-s[l] > k){
        l++;
    }

    dp[a+1] = s[a]-s[l]+dp[l];
}
printf("%lld", dp[n+1]);
return 0;
}
