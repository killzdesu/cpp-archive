#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

priority_queue<pair<int, int> > q;
int N, K, C, T;
int s[200010];

int main(){
int a, b, c, d;
cin >> N >> T >> C;
for(a=0;a<N;a++){
    scanf("%d", &s[a]);
}
for(a=0;a<C-1;a++){
    q.push(make_pair(s[a], a));
}
for(a=C-1;a<N;a++){
    q.push(make_pair(s[a], a));
    while(q.top().second+C<=a) q.pop();
    if(q.top().first <= T) K++;
}
cout << K;

return 0;
}
