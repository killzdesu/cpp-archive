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
int mx, mn;

struct node{
    int prior;
    int cnt;
    string key;
    node *left, *right;
    node(){
        left = right = NULL;
        prior = rand();
        cnt = 1;
    }
};
typedef node * nodep;

struct treap{
    nodep R;

    int size(nodep p){
        return p ? p->cnt : 0;
    }

    void update_cnt(nodep &p){
        if(!p) return;
        p->cnt = size(p->left)+size(p->right)+1;
    }

    void rotate_right(nodep &p){
        nodep tmp = p->left;
        p->left = tmp->right;
        tmp->right = p;
        p = tmp;
        update_cnt(p->right);
        update_cnt(p);
    }

    void rotate_left(nodep &p){
        nodep tmp = p->right;
        p->right = tmp->left;
        tmp->left = p;
        p = tmp;
        update_cnt(p->left);
        update_cnt(p);
    }

    void insert(nodep &p, string val, int P){
        if(p == NULL){
            p = (nodep)new node();
            p->key = val;
            p->prior = P;
            return ;
        }
        if(val > p->key){
            insert(p->right, val, P);
            update_cnt(p->right);
            if(p->right->prior > p->prior){
                rotate_left(p);
            }
        }
        if(val < p->key){
            insert(p->left, val, P);
            update_cnt(p->left);
            if(p->left->prior > p->prior){
                rotate_right(p);
            }
        }
        update_cnt(p);
    }

    nodep find(nodep p, string val){
        if(!p) return NULL;
        if(p->key == val) return p;
        if(p->key < val) return find(p->right, val);
        if(p->key > val) return find(p->left, val);
    }

    void del(nodep &p, string val){
        if(p == NULL) return;
//        printf("find %d: %d\n", val, p->key);
        if(p->key > val) del(p->left, val);
        else if(p->key < val) del(p->right, val);
        else {
            if(p->left and p->right){
                if(p->left->prior > p->right->prior){
                    rotate_right(p);
                }
                else rotate_left(p);
                del(p, val);
            }
            else {
                nodep t = p;
                if(p->left) p = p->left;
                else p = p->right;
                delete t;
            }
        }
        update_cnt(p);
    }

    void clear(nodep p){
        if(p == NULL) return;
        clear(p->left);
        clear(p->right);
        delete p;
    }

    void trav(nodep p){
        if(p == NULL) return;
        printf("(");
        trav(p->left);
        printf("%d/%s", p->prior, p->key.c_str());
        trav(p->right);
        printf(")");
    }
}T;

int main(){
//freopen("input.in", "r", stdin);
int a, b, c, d;
nodep p;
char rr[100001];
RUN:;
scanf("%d", &N);
if(N == 0) return 0;
scanf(" ");
T.clear(T.R);
T.R = NULL;
REP(a, N){
    i = 0;
    while(1){
        scanf("%c", &rr[i]);
        if(rr[i] == '/') break;
        i++;
    }
    rr[i] = '\0';
    string TT = rr;
    scanf("%d ", &c);
    T.insert(T.R, TT, c);
}
T.trav(T.R);EL;
goto RUN;

return 0;
}
