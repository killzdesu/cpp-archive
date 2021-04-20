#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int s[100010], n, k;
int *p;

int main(){
    int a, b, c;
    int mx = 1;
    cin >> n >> k;
    for(a=1;a<=n;a++){
        scanf("%d", &s[a]);
        s[a]+=s[a-1];
    }
    for(a=1;a<=n;a++){
        p = upper_bound(s+1, s+n+1, s[a-1]+k);
        b = p-s-a;
        //printf("%d %d\n", a, p-s);
        //b--;
        mx = max(mx, b);
    }
    cout << mx;
return 0;
}
