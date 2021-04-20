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
    int key, prior;
    int cnt;
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

    void insert(nodep &p, int val){
        if(p == NULL){
            p = (nodep)new node();
            p->key = val;
            return ;
        }
        if(val > p->key){
            insert(p->right, val);
            update_cnt(p->right);
            if(p->right->prior > p->prior){
                rotate_left(p);
            }
        }
        if(val < p->key){
            insert(p->left, val);
            update_cnt(p->left);
            if(p->left->prior > p->prior){
                rotate_right(p);
            }
        }
        update_cnt(p);
    }

    nodep find(nodep p, int val){
        if(!p) return NULL;
        if(p->key == val) return p;
        if(p->key < val) return find(p->right, val);
        if(p->key > val) return find(p->left, val);
    }

    void del(nodep &p, int val){
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

    void diff_min(nodep p, int cur, int lo, int hi){
        if(!p) return;
        if(cur + size(p->left) >= lo) diff_min(p->left, cur, lo, hi);
        cur += size(p->left)+1;
//        printf("visit %d\n", p->key);
        if(i!=-1) k = min(k, abs(p->key-i));
        i = p->key;
        if(cur < hi) diff_min(p->right, cur, lo, hi);
    }

    void diff_max(nodep p, int cur, int lo, int hi){
        if(!p) return;
        if(cur + size(p->left) >= lo) diff_max(p->left, cur, lo, hi);
        cur += size(p->left)+1;
//        printf("visit %d\n", p->key);
        mn = min(mn, p->key);
        mx = max(mx, p->key);
        if(cur < hi) diff_max(p->right, cur, lo, hi);
    }
}T;

int main(){
//freopen("input.in", "r", stdin);
int a, b, c, d;
nodep p;
char rr[3];
cin >> N;
while(N--){
    scanf("%s", rr);
    if(rr[0] == 'I'){
        scanf("%d", &c);
        T.insert(T.R, c);
    }
    if(rr[0] == 'D'){
        scanf("%d", &c);
        T.del(T.R, c);
    }
    if(rr[0] == 'N'){
        i = -1;
        k = 2e9;
        scanf("%d %d", &c, &d);
//        printf("--------------- %d %d\n", c+1, d+1);
        T.diff_min(T.R, 0, c+1, d+1);
        printf("%d\n", k==2e9?-1:k);
    }
    if(rr[0] == 'X'){
        mx = -2e9;
        mn = 2e9;
        scanf("%d %d", &c, &d);
        T.diff_max(T.R, 0, c+1, d+1);
        printf("%d\n", mx-mn==0?-1:mx-mn);
    }

}


return 0;
}
