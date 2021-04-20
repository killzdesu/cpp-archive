#include<stdio.h>
#include<algorithm>
int s[1000004];

int main(){
int a;
for(a=0;a<1000000;a++)s[a] = (10000-a)*3273871%(1000000);
std::sort(s, s+1000000);
printf("");
return 0;
}
