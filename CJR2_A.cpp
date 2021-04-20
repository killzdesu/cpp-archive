#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>

using namespace std;

bool u[100005];
multiset<int> ss;
multiset<int>::iterator it, is;
int s[100005], sm;
int N, M, K, i, k;
int mn;

int main(){
freopen("A-large (4).in", "r", stdin);
freopen("A_out.txt", "w", stdout);
int a, b, c, d;
int R, T;
int *p;
string S;
cin >> R;
T = R;
while(T--){
    scanf("%d %d", &N, &M);
    c = 0;
    for(a=0;a<N;a++){
        u[a] = 0;
        scanf("%d", &s[a]);
        ss.insert(s[a]);
    }
    while(!ss.empty()){
        it = ss.end();
        it--;
        d = *it;
        ss.erase(it);
        c++;
        it = ss.upper_bound(M-d);
        if(it == ss.begin()) continue;
        it--;
        ss.erase(it);
    }
    printf("Case #%d: %d\n", R-T, c);
}

return 0;
}
