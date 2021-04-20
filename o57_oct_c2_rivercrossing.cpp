#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long

using namespace std;

int i, k, N, M, K, L;

struct fenwick{
    int m[100010], N;

    void clear(){
        fill_n(m, N+10, 0);
    }

    void init(int n){
        N = n;
    }

    void update(int x, int val){
        while(x <= N){
            m[x] += val;
            x += (x&-x);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0){
            sum += m[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    int query_r(int idx, int idy){
        return query(idy) - query(idx-1);
    }

    int query_a(int idx){
        return query(idx) - query(idx-1);
    }

};

int n[2];
fenwick P[2], T;
deque<int> ban[2][50010];
deque<int>::iterator it, p, is;
pii go[2][50010], TT;
int A[2][50010];

int sum(int i, fenwick F, int x, int y){
    if(x <= y){
        return F.query_r(x, y);
    }
    else {
        return F.query_r(x, n[i]) + F.query_r(1, y);
    }
}

int main(){
int a, b, c, d, i, j;
cin >> N >> M >> K >> L;
n[0] = N;
n[1] = M;
for(a=0;a<L;a++){
    scanf("%d %d", &c, &d);
    ban[0][c].pb(d);
    ban[1][d].pb(c);
}
for(a=1;a<=N;a++){
    scanf("%d %d", &d, &c);
    sort(ban[0][a].begin(), ban[0][a].end());
    go[0][a].fi = c;
    go[0][a].se = c+d-1;
    if(go[0][a].se > M) go[0][a].se%=M;
    while(!ban[0][a].empty() and ban[0][a].front() < go[0][a].fi){
        ban[0][a].pb(ban[0][a].front()+N);
        ban[0][a].pop_front();
    }
}
for(a=1;a<=M;a++){
    scanf("%d %d", &d, &c);
    sort(ban[1][a].begin(), ban[1][a].end());
    go[1][a].fi = c;
    go[1][a].se = c+d-1;
    if(go[1][a].se > N) go[1][a].se%=N;
    while(!ban[1][a].empty() and ban[1][a].front() < go[1][a].fi){
        ban[1][a].pb(ban[0][a].front()+N);
        ban[1][a].pop_front();
    }
}
P[0].init(N+10);
P[1].init(M+10);
P[0].update(1, 1);
P[0].update(N+1, -1);
ll sm=0;
int trig;
for(a=0;a<K;a++){
    i = a%2;
    j = (a+1)%2;
    P[j].clear();
//    printf("i:%d >> ", i);
//    REP(b, n[i]){
//        printf("%d ", P[i].query(b));
//    }printf("\n");
    trig = 0;
    for(b=1;b<=n[i];b++){
        c = P[i].query(b);
        c %= 30011;
        TT = go[i][b];
        P[j].update(go[i][b].fi, c);
        it = ban[i][b].begin();
        if(go[i][b].se >= go[i][b].fi){
                while(it != ban[i][b].end() and *it <= go[i][b].se){
                    d = *it;
                    if(d > n[j]){
                        d%=n[j];
                    }
                    P[j].update(d, -c);
                    P[j].update(d+1, c);
                    it++;
                    go[i][b].se++;
                    if(go[i][b].se > n[j]){
                        if(trig == 0){
                            trig = 1;
                            P[j].update(n[j]+1, -c);
                            P[j].update(1, c);
                        }
                    }
                }

                if(go[i][b].se > n[j]) go[i][b].se%=n[j];
                P[j].update(go[i][b].se+1, -c);
        }
        else{
            while(it != ban[i][b].end() and *it <= go[i][b].se){
                d = *it;
                if(d > n[j]){
                    d%=n[j];
                }
                P[j].update(d, -c);
                P[j].update(d+1, c);
                it++;
                go[i][b].se++;
            }
            P[j].update(n[j]+1, -c);
            P[j].update(1, c);
            P[j].update(go[i][b].se+1, -c);
        }
//        printf("%d@%d: %d %d\n", i, b, go[i][b].fi, go[i][b].se);
        go[i][b] = TT;

    }
    if(j == 1){
        for(b=1;b<=n[j];b++){
            sm += P[j].query(b)%30011;
        }
        sm %= 30011;
    }
}
cout << sm;
return 0;
}
