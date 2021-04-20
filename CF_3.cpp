#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<set>
#include<list>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long

using namespace std;

int i, n, k, N, M, K;
int t[3];
set<int> X, Y;
set<int>::iterator it, i1, i2, is;
set<int> ax, ay;
pii Q[200010];
stack<int> st;

int main(){
int a, b, c, d;
cin >> N >> M >> K;
X.insert(0);
X.insert(N);
Y.insert(0);
Y.insert(M);
REP(a, K){
    scanf("%s %d", t, &c);
    if(t[0] == 'V'){
        Q[a].fi = 0;
        Q[a].se = c;
        X.insert(c);
    }
    else {
        Q[a].fi = 1;
        Q[a].se = c;
        Y.insert(c);
    }
}

int mx=-2, my=-2;
for(it=X.begin(); it!=X.end();it++){
    if(it!=X.begin()){
        is = it;
        is--;
        mx = max(mx, (*it)-(*is));
    }
}
for(it=Y.begin(); it!=Y.end();it++){
    if(it!=Y.begin()){
        is = it;
        is--;
        my = max(my, (*it)-(*is));
    }
}
ll P;
stack<ll> ss;
for(i=K-1;i>=0;i--){
    P = mx;
    P*= (ll)my;
    ss.push(P);
    if(Q[i].fi == 0){
        it = X.lower_bound(Q[i].se);
        i1 = i2 = it;
        i1--;
        i2++;
        X.erase(it);
        mx = max(mx, (*i2)-(*i1));
    }
    if(Q[i].fi == 1){
        it = Y.lower_bound(Q[i].se);
        i1 = i2 = it;
        i1--;
        i2++;
        Y.erase(it);
        my = max(my, (*i2)-(*i1));
    }
}
while(!ss.empty()){
    printf("%I64d\n", ss.top());
    ss.pop();
}
return 0;
}
