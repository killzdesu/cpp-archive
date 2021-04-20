#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

vector<int> p, s;
int n, z, u1, u2, u;

int main(){
int a, b, c;
cin >> n;
for(a=0;a<n;a++){
    cin >> c;
    if(c == 0) z++;
    else if(c < 0) s.push_back(c);
    else p.push_back(c);
}
if(p.empty()){
    u = 2;
}
printf("1 %d\n", s[u]);
if(u == 2) printf("2 %d %d\n", s[0], s[1]);
else printf("1 %d\n", p[0]);
b = z;
if(u == 2) z+=s.size()-3;
else z+= s.size()+p.size()-2;
printf("%d ", z);
for(a=0;a<b;a++)printf("0 ");
for(a=1;a<p.size();a++)printf("%d ", p[a]);
for(a=u+1;a<s.size();a++)printf("%d ", s[a]);


return 0;
}
