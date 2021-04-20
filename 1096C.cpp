#include<bits/stdc++.h>

using namespace std;

int main(){
int a, b, c, d;
int k, T;
cin >> T;
while(T--){
    cin >> k;
    k *= 2;
    c = 360/__gcd(k, 360);
//    printf("%d %d %d\n", c, __gcd(360, k), k/__gcd(360, k));
    printf("%d\n", c*(k/__gcd(k, 360)>c-2?2:1));
}

return 0;
}
