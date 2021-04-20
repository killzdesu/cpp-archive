#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin, unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;

int i, n, k, N, M, K;

struct node{
    int val, prior;
    int cnt;
    node *right, *left;
    node(){
        cnt = 1;
        prior = rand()+1;
        right = left = nullptr;
    }
    node(int v){
        cnt = 1;
        val = v;
        prior = rand()+1;
        right = left = nullptr;
    }
};

typedef node * nodep;

struct treap{
    nodep R;

    int cnt(nodep p){
        return (p?p->cnt:0);
    }

    void upd_cnt(nodep p){
        if(p){
            p->cnt = cnt(p->right)+cnt(p->left)+1;
        }
    }

    void rot_left(nodep &p){
        nodep q = p->right;
        p->right = q->left;
        q->left = p;
        p = q;
        upd_cnt(p->left);
        upd_cnt(p);
    }

    void rot_right(nodep &p){
        nodep q = p->left;
        p->left = q->right;
        q->right = p;
        p = q;
        upd_cnt(p->right);
        upd_cnt(p);
    }

    void balance(nodep &p){
        if(!p) return;
        if(p->left and p->left->prior > p->prior) rot_right(p);
        else if(p->right and p->right->prior > p->prior) rot_left(p);
    }

    void insert(nodep &p, int key){
        if(!p){
            p = new node(key);
            return;
        }
        if(key < p->val){
            insert(p->left, key);
            balance(p);
        }
        else if(key > p->val){
            insert(p->right, key);
            balance(p);
        }
    }

    void del(nodep &p, int key){
        if(!p) return;
        if(key < p->val){
            del(p->left, key);
            balance(p);
        }
        else if(key > p->val){
            del(p->right, key);
            balance(p);
        }
    }

    void trav(nodep p){
        if(!p) return;
        trav(p->left);
        printf("%d\n", p->val);
        trav(p->right);
    }

}T;

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    scanf("%d", &c);
    T.insert(T.R, c);
}
T.trav(T.R);
return 0;
}
