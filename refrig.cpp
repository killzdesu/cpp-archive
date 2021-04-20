#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#define fi first
#define se second

using namespace std;

int i, n, k, N, M, K;
priority_queue<int, vector<int>, greater<int> > q;

int main(){
int a, b, c, d, T;
scanf("%d", &T);
while(T--){
    cin >> N;
    d = 0;
    while(!q.empty())q.pop();
    for(a=0;a<N;a++){
        scanf("%d", &c);
        q.push(c);
    }
    while(q.top() > d){
        c = q.top();
        q.pop();
        b = min(q.top()-c+1, q.top()-d);
        q.push(c+b);
        d += b;
    }
    printf("%d\n", d);
}


return 0;
}
