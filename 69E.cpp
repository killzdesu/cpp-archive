#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define all(x) x.begin(),x.end()
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()


using namespace std;

int i, n, k, N, M, K;

map<int, int> m;
priority_queue<int> Q;
int s[100010];

int main(){
int a, b, c, d;
cin >> N >> K;
REP(a, K-1){
    scanf("%d", &c);
    s[a] = c;
    Q.push(c);
    m[c]++;
}
for(;a<N;a++){
    scanf("%d", &c);
    s[a] = c;
    m[c]++;
    Q.push(c);
    while(!Q.empty() and m[Q.top()] != 1){
        Q.pop();
    }
    if(!Q.empty())printf("%d\n", Q.top());
    else printf("Nothing\n");
    m[s[a-K+1]]--;
    Q.push(s[a-K+1]);
}


return 0;
}
