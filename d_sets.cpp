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
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define pb push_back
#define pii pair<long long, int>

using namespace std;

int i, n, k, N, M, K;
priority_queue<pii, vector<pii>, greater<pii> > q;

vector<int> p;
vector<int> w;
int s[500000];
int pn[500000];
int chk[500000];
int PP = 480000;

int gcd(int x, int y){
    if(x < y) swap(x, y);
    if(x%y==0) return y;
    return gcd(y, x%y);
}

int main(){
int a, b, c, d;
pii P1, P2, P3, P4;

cin >> N >> K;
for(a=2;a<480000;a++){
    if(chk[a] == 0){
        p.pb(a);
        for(b=a+a;b<480000;b+=a){
            chk[b] = 1;
        }
    }
}
for(a=0;a<p.size();a++){
    q.push(make_pair(p[a],p[a]));
    //printf("> %d\n", p[a]);
}
vector<int> z;
z.pb(1);
int A1, A2, A3, A4;

A1 = q.top().fi;
P1 = make_pair(q.top().fi*q.top().se, q.top().se);
q.pop();
A2 = q.top().fi;
P2  = make_pair(q.top().fi*q.top().se, q.top().se);
q.pop();
A3 = q.top().fi;
P3 = make_pair(q.top().fi*q.top().se, q.top().se);
q.pop();
q.push(P1);
q.push(P2);
q.push(P3);
z.pb(A1);
z.pb(A2);
z.pb(A3);

for(d=0;d<N-1;d++){
    A1 = q.top().fi;
    P1 = make_pair(q.top().fi*q.top().se, q.top().se);
    q.pop();
    A2 = q.top().fi;
    P2  = make_pair(q.top().fi*q.top().se, q.top().se);
    q.pop();
    A3 = q.top().fi;
    P3 = make_pair(q.top().fi*q.top().se, q.top().se);
    q.pop();
    A4 = q.top().fi;
    P4 = make_pair(q.top().fi*q.top().se, q.top().se);
    q.pop();
    q.push(P1);
    q.push(P2);
    q.push(P3);
    q.push(P4);
    z.pb(A1);
    z.pb(A2);
    z.pb(A3);
    z.pb(A4);
    //printf("%d %d %d %d\n", A1, A2, A3, A4);
}
printf("%d\n", z[z.size()-1]*K);
for(a=0;a<z.size();a++){
    printf("%d ",z[a]*K);
    if(a%4==3)printf("\n");
}
return 0;
}
