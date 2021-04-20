#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define pb push_back

using namespace std;

int i, n, k, N, M, K, h[100010];

struct node{
    node *parent;
    node *left;
    node *right;
    int val;
    int num_left;
    int num_right;
};

typedef node* nodep;

nodep ins(nodep h, int val){
    nodep p, q;

    p = nodep(new node);
    p->left = p->right = p->parent = NULL;
    p->val = val;
    p->num_left = p->num_right = 0;

    if(h == NULL){
        h = p;
        return h;
    }
    q = p;
    p = h;
    while(p != NULL){
        if(p->val > val){
            p->num_left += 1;
            if(p->left == NULL) break;
            p = p->left;
        }
        else {
            p->num_right += 1;
            if(p->right == NULL) break;
            p = p->right;
        }
    }
    if(p->val > val){
        p->left = q;
        q->parent = p;
    }
    else {
        p->right = q;
        q->parent = p;
    }
    return h;
}

nodep move_node(nodep h1, nodep h2){
    if(h2->left != NULL) h1 = move_node(h1, h2->left);
    h1 = ins(h1, h2->val);
    if(h2->right != NULL) h1 = move_node(h1, h2->right);
    return h1;
}

nodep merge_each(nodep h1, nodep h2){
    nodep p;
    p = h2;
//    if(h1->num_left + h1->num_right < h2->num_left + h2->num_right)swap(h1, h2);
    h1 = move_node(h1, h2);
    return h1;
}

nodep merge(nodep h1, nodep h2){
    nodep p, q;
    p = h1;
    while(p != NULL){
        if(p->val > h2->val){
            p->num_left += h2->num_right + h2->num_left + 1;
            if(p->left == NULL) break;
            p = p->left;
        }
        else {
            p->num_right += h2->num_right + h2->num_left + 1;
            if(p->right == NULL) break;
            p = p->right;
        }
    }
    if(p->val > h2->val){
        p->left = h2;
        h2->parent = p;
    }
    else {
        p->right = h2;
        h2->parent = p;
    }
    return h1;
}

int disj_query(int x){
    if(h[x] != x){
        h[x] = disj_query(h[x]);
    }
    return h[x];
}

void find(nodep h, int val){
    nodep p;
    int R = 1;
    p = h;
    while(p != NULL){
        if(p->val == val){
            printf("%d\n", R+p->num_right);
            return;
        }
        if(p->val > val){
            R += p->num_right + 1;
            p = p->left;
//            printf("L ");q
        }
        else {
            p = p->right;
//            printf("R ");
        }
    }
}

int main(){
int a, b, c, d;
nodep head[100010];
int T;
cin >> T;
while(T--){
    scanf("%d %d", &N ,&M);
    REP(a, N+5){
        h[a] = a;
//        free(head[a]);
        head[a] = NULL;
    }
    REP(a, N+5){
        head[a] = ins(head[a], a);
    }
    REP(a, M){
        scanf("%d", &i);
        if(i == 1){
            scanf("%d %d", &c, &d);
            //head[disj_query(c)] = merge(head[disj_query(c)], head[disj_query(d)]);
            if(head[disj_query(c)]->num_left + head[disj_query(c)]->num_right < head[disj_query(d)]->num_left + head[disj_query(d)]->num_right)
                swap(head[disj_query(c)], head[disj_query(d)]);
            head[disj_query(c)] = merge_each(head[disj_query(c)], head[disj_query(d)]);
            h[d] = h[c];
        }
        else {
            scanf("%d", &c);
            find(head[disj_query(c)], c);
        }
    }
}

return 0;
}
