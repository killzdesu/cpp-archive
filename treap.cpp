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

struct node{
    int key, cnt, prior;
    node *left;
    node *right;
    node(){
        cnt = 0;
        prior = rand();
        left = right = NULL;
        key = 0;
    }
};

typedef node * nodep;

struct treap{
    nodep root;
    treap(){root = NULL; srand(233333);}

    int tcnt(nodep p){
        if(p) return p->cnt;
        return 0;
    }

    void upd_size(nodep &p){
        if(p){
            p->cnt = tcnt(p->left)+tcnt(p->right)+1;
        }
    }

    void rotate_left(nodep &p){
        nodep tmp = p->right;
        p->right = tmp->left;
        tmp->left = p;
        p = tmp;
        upd_size(p->left);
        upd_size(p);
    }

    void rotate_right(nodep &p){
        nodep tmp = p->left;
        p->left = tmp->right;
        tmp->right = p;
        p = tmp;
        upd_size(p->right);
        upd_size(p);
    }

    void insert(nodep &p, int val){
        if(p == NULL){
            p = (nodep)new node();
            p->key = val;
            upd_size(p);
            return;
        }
        if(p->key > val){
            insert(p->left, val);
            if(p->prior < p->left->prior){
                rotate_right(p);
            }
        }
        else if(p->key < val){
            insert(p->right, val);
            if(p->prior < p->right->prior){
                rotate_left(p);
            }
        }
        upd_size(p);
    }

    void insert(int val){
        insert(root, val);
    }

    nodep find(nodep p, int val){
        if(!p) return NULL;
        if(p->key == val) return p;
        else if(p->key < val) return find(p->right, val);
        else return find(p->left, val);
    }

    nodep find(int val){
        return find(root, val);
    }

    void del(nodep &p, int val){
        if(p==NULL) return;
        if(p->key < val) del(p->right, val);
        else if(p->key > val) del(p->left, val);
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
        upd_size(p);
    }

    void travel(nodep p){
        if(p){
            travel(p->left);
            printf("%d\n", p->key);
            travel(p->right);
        }
    }

    int count(nodep p, int bound){
        if(p == NULL) return 0;
        if(p->key < bound){
            return tcnt(p->left)+1+count(p->right, bound);
        }
        return count(p->left, bound);
    }

    int kth(nodep p, int k){
//        printf("%d|| cnt[%d] :k[%d]\n", p->key, tcnt(p), k);
        if(tcnt(p) < k) return -2e9;
        if(tcnt(p->left)+1 == k) return p->key;
        if(tcnt(p->left)+1 > k) return kth(p->left, k);
        if(tcnt(p->left)+1 < k) return kth(p->right, k-tcnt(p->left)-1);
    }

}Tr;

int main(){
freopen("ORDER.txt", "r", stdin);
int a, b, c, d;
char rr[3];
cin >> N;
nodep p;
REP(a, N){
    scanf("%s %d", rr, &c);
    if(rr[0] == 'I'){
        if(Tr.find(c) == NULL) Tr.insert(c);
    }
    if(rr[0] == 'D'){
        Tr.del(Tr.root, c);
    }
    if(rr[0] == 'C'){
        printf("%d\n", Tr.count(Tr.root, c));
    }
    if(rr[0] == 'K'){
        d = Tr.kth(Tr.root, c);
        if(d != -2e9) printf("%d\n", d);
        else printf("invalid\n");
    }
}



return 0;
}
