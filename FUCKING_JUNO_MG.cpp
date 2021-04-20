#include<cstdio>

template <typename type>
class Node
{
public :
    Node(type k)
    {
        key=k;
        left=NULL;
        right=NULL;
        parent=NULL;
    };
    type key;
    Node *left;
    Node *right;
    Node *parent;

};

template <typename dT>
class BSTree
{
public :
    BSTree()
    {
        root=NULL;
    };
    void insertBSTree(dT x)
    {
        if(root==NULL)
        {
            root=new Node<dT>(x);
            return ;
        }
        if(findn(x))
            return ;
        Node<dT> *p,*q;
        p=root;
        q=p;
        while(p!=NULL)
        {
            q=p;
            if(x>p->key)
                p=p->right;
            else
                p=p->left ;
        }
        if(x>q->key)
        {
            q->right = new Node<dT>(x);
            q->right->parent=q;
        }
        else
        {
            q->left = new Node<dT>(x);
            q->left->parent=q;
        }
    };
    bool findn(dT x)
    {
        Node<dT> *p;
        p=root;
        while(p!=NULL)
        {
            if(p->key==x)
            {
                return true;
            }
            else
            {
                if(p->key > x)
                    p=p->left;
                else
                    p=p->right;
            }
        }
        return false ;
    }
    int Ans(dT x)
    {
        Node<dT> *p;
        p=root;
        int l,r;
        while(p!=NULL)
        {
            if(x>=p->key)
            {
                l=p->key;
                p=p->right;
            }
            else
            {
                r=p->key;
                p=p->left;
            }
        }
        return r-l;
    }
    Node<dT> *root;
};

int main()
{
    int n,m,q,x,y;
    BSTree<int> a;
    a.insertBSTree(1);
    scanf("%d%d%d",&n,&m,&q);
    a.insertBSTree(n+1);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        a.insertBSTree(x);
        if(x+y<=n+1)
        a.insertBSTree(x+y);
    }
    for(int i=0;i<q;i++)
    {
        scanf("%d",&x);
        printf("%d\n",a.Ans(x));
    }
}
