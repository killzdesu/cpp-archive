#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin(), unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define dump(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

int i, n, k, N, M, K;

struct node{
    int key, prior;
    int flag, flag_val;
    node *left, *right;
    node(){
        left = right = NULL;
        prior = rand();
        flag = flag_val = 0;
    }
};

typedef node * nodep;

struct tree{
    nodep R;

    void rotate_right(nodep &p){
        nodep tmp = p->left;
        p->left = tmp->right;
        tmp->right = p;
        p = tmp;
    }

    void rotate_left(nodep &p){
        nodep tmp = p->right;
        p->right = tmp->left;
        tmp->left = p;
        p = tmp;
    }

    void update(nodep &p){
        if(p->flag == 0) return ;
        p->key += p->flag_val;
        if(p->left) p->left->flag = 1, p->left->flag_val += p->flag_val;
        if(p->right) p->right->flag = 1, p->right->flag_val += p->flag_val;
        p->flag_val = p->flag = 0;
    }

    void insert(nodep &p, int val){
        if(p == NULL){
            p = (nodep)new node();
            p->key = val;
            return ;
        }
//        printf(">> %d\n", p->key);
        if(val > p->key){
            insert(p->right, val);
            if(p->right->prior > p->prior){
                rotate_left(p);
            }
        }
        if(val < p->key){
            insert(p->left, val);
            if(p->left->prior > p->prior){
                rotate_right(p);
            }
        }
    }

    nodep find(nodep p, int val){
        if(!p) return NULL;
        update(p);
//        printf("> %d %d\n", p->key, val);
        if(p->key == val) return p;
        if(p->key < val) return find(p->right, val);
        if(p->key > val) return find(p->left, val);
    }

    void dodo(int k, int c, int d){
        nodep p = find(R, k);
        if(!p) return;
        p->left->flag = 1;
        p->left->flag_val += c;
        p->right->flag = 1;
        p->right->flag_val += d;
        swap(p->left, p->right);
    }

    void trav(nodep p){
        if(!p) return;
        update(p);
        trav(p->left);
        cout << p->key << " ";
        trav(p->right);
    }

}T;

int main(){
int a, b, c, d;
cin >> N >> M;
REP(a, N){
    scanf("%d", &c);
    T.insert(T.R, c);
}
while(M--){
    scanf("%d", &c);
    if(c == 1){
        scanf("%d", &d);
        if(T.find(T.R, d) != NULL) printf("1\n");
        else printf("0\n");
    }
    else {
        scanf("%d %d %d", &k, &c, &d);
        T.dodo(k, c, d);
        T.trav(T.R);EL;
    }

}


return 0;
}
