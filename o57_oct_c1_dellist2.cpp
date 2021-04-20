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

struct node{
    int val;
    vector<int> ins, del;
    node *next;
};
typedef node * nodep;

int i, n, k, N, M, K;
map<int, int> m;

void ins(nodep &h, nodep &t, int x){
    if(h==NULL){
        h = new node;
        h->val = x;
        h->next = NULL;
        t = h;
    }
    else {
        nodep p = new node;
        p->val = x;
        p->next = NULL;
        t->next = p;
        t = t->next;
    }
}

int main(){
int a, b, c, d, r;
nodep p;
nodep h[100010], t[100010];

cin >> N >> M;
REP(a, N+1){
    h[a] = t[a] = NULL;
}
REPI(a, N){
    scanf("%d", &c);
    REP(b, c){
        scanf("%d", &d);
        ins(h[a], t[a], d);
    }
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
