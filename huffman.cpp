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

int i, n, k, N, M, K;

struct node{
    int val, freq;
    node * left;
    node * right;
};

typedef node * nodep;

struct que{
    nodep P;
    int freq;
    bool operator < (const que &b) const{
        return freq > b.freq;
    }
    que(int a, nodep b){
        freq = a; P = b;
    }
    que(){};
};

priority_queue<que> Q;

int freq[1000];
string s[1000];
string T;
char ss[1000], sl;

void trav(nodep p){
    if(p->left){
        ss[sl++] = '0';
        trav(p->left);
        sl--;
    }
    if(p->right){
        ss[sl++] = '1';
        trav(p->right);
        sl--;
    }
    if(p->right==NULL and p->left==NULL){
        ss[sl] = '\0';
        s[p->val] = ss;
//        printf("%c: %s\n", p->val, s[p->val].c_str());
    }
}

char tmps[1000000];

int main(){
int a, b, c, d;
string S;
nodep xx;
xx = (nodep)(new node);
//cin >> S;
gets(tmps);
S = tmps;
REP(a, S.length()){
    freq[S[a]]++;
}
for(a=0;a<=800;a++){
    if(freq[a] == 0) continue;
    nodep p;
    p = (nodep)(new node);
    p->left = p->right = NULL;
    p->val = a;
    p->freq = freq[a];
    Q.push(que(freq[a], p));
}

nodep p, q, t;
que tmp;

while(Q.size()!=1){
    tmp = Q.top();
    Q.pop();
    p = tmp.P;
    tmp = Q.top();
    Q.pop();
    q = tmp.P;
    t = (nodep)(new node);
    t->left = p;
    t->right = q;
    t->freq = p->freq+q->freq;
    t->val = 7;
    tmp.P = t;
    tmp.freq = t->freq;
    Q.push(tmp);
}
nodep h = Q.top().P;
trav(h);

printf("Encoded: ");
REP(a, S.size()){
    printf("%s", s[S[a]].c_str());
    k += s[S[a]].length();
}
printf("\n%d", k);

return 0;
}
