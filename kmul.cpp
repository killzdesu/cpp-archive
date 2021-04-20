#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int n, k;
int s[100010], p[100100];

int main(){
int a, b, c, d;
cin >> n >> k;
for(int i=0;i<n;i++){
    scanf("%d", &s[i]);
    p[i] = 1;
}

sort(s, s+n);

for(int i=0;i<n;i++){
    if(!p[i]) continue;
    for(int j=i+1;j<n;j++){
        if(s[j]%s[i] == 0)p[j] = 0;
    }
}
b=0;
for(int i=0;i<n;i++) b+=p[i];
cout << b;

return 0;
}
