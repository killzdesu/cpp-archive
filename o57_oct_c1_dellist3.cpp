#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
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

int i, n, k, N, M, K;
map<int, int> m;
int s[100010];
vector<int> ins[100010];
vector<int> del[100010];
int next[100010];

int main(){
int a, b, c, d, r;
int h[100010], t[100010];

cin >> N >> M;
i=0;
REPI(a, N){
    h[a] = t[a] = NULL
    scanf("%d", &c);
    h[a] = i;
    REP(b, c){
        scanf("%d", &s[i]);
        i++;
    }
    t[a] = i;
}

REP(r, M){
    scanf("%d %d %d", &b, &c, &d);
    if(b == 1){
        if(h[c] == NULL) continue;
        h[c]->ins.pb(d);
        t[c]->del.pb(d);
    }
    else {
        if(h[d] == NULL){
            continue;
        }
        else if(h[c] == NULL){
            h[c] = h[d];
            t[c] = t[d];
            h[d] = t[d] = NULL;
        }
        else {
            t[c]->next = h[d];
            t[c] = t[d];
            h[d] = t[d] = NULL;
        }
    }
}

REPI(a, N){
    for(p=h[a]; p!=NULL; p=p->next){
        REP(b, p->ins.size()){
            m[p->ins[b]]++;
        }
        if(m[p->val]==0)printf("%d\n", p->val);
        REP(b, p->del.size()){
            m[p->del[b]]--;
        }
    }
    //printf("\n");
}
return 0;
}
