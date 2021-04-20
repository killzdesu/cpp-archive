#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int n;
pair<int, int> s[300010];

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
int a, b, c, d;
cin >> n;
for(int i=0;i<n;i++){
    scanf("%d", &d);
    s[i] = make_pair(i, d);
}

sort(s, s+n, cmp);
for(int i=1;i<n;i++){
    if(s[i].second <= s[i-1].second) s[i].second = s[i-1].second+1;
}
sort(s, s+n);

for(int i=0;i<n;i++) printf("%d ", s[i].second);

return 0;
}
