#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int s[10000], n;
vector<int> v;

int main(){
int a, b, c;
cin >> n;
for(int i=0;i<n;i++){
    cin >> c;
    s[c]++;
}

for(int i=1;i<=5000;i++){
    if(s[i]){
        s[i]--;
        v.push_back(i);
        b = i;
    }
}
for(int i=b-1;i>=1;i--){
    if(s[i]){
        s[i]--;
        v.push_back(i);
    }
}
printf("%d\n", v.size());
for(int i=0;i<v.size();i++)printf("%d ", v[i]);

return 0;
}
