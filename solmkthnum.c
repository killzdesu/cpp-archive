#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>

#define RIGHT 131072
#define SIZE 262144

using namespace std;

struct T
{
    int am, l, r;
    T(int a, int b, int c) : am(a), l(b), r(c) {};
};

int N, Q, Last;
int A[100005], Orig[100005], S[100005], Root[100005];
map<int,int> M;
vector<T> V(2100000, T(0, 0, 0));

int newNode(int n)
{
    V[++Last].am = V[n].am;
    V[Last].l = V[n].l;
    V[Last].r = V[n].r;
    return Last;
}

int insert(int idx, int v, int n, int a, int b)
{
    if(a > v || b < v)
        return idx;

    idx = newNode(idx);

    if(a == v && b == v)
    {
        V[idx].am++;
        return idx;
    }

    int mid = (a+b) / 2;
    V[idx].l = insert(V[idx].l, v, 2*n, a, mid);
    V[idx].r = insert(V[idx].r, v, 2*n + 1, mid + 1, b);

    V[idx].am = V[V[idx].l].am + V[V[idx].r].am;
    return idx;
}

int query(int idx_l, int idx_r, int k, int n, int a, int b)
{
    if(k == 1 && a == b && V[idx_r].am - V[idx_l].am == 1)
        return a;

    int mid = (a+b) / 2;
    int on_left = V[V[idx_r].l].am - V[V[idx_l].l].am;

    if(on_left < k)
        return query(V[idx_l].r, V[idx_r].r, k - on_left, 2*n + 1, mid + 1, b);
    else
        return query(V[idx_l].l, V[idx_r].l, k, 2*n, a, mid);
}

int main()
{
    scanf("%d %d", &N, &Q);

    for(int i = 0; i < N; i++)
    {
        int x;
        scanf("%d", &A[i]);
        S[i] = A[i];
    }

    sort(S, S+N);

    for(int i = 0; i < N; i++)
        M[S[i]] = i+1, Orig[i+1] = S[i];

    for(int i = 0; i < N; i++)
        Root[i+1] = insert(Root[i], M[A[i]], 1, 1, RIGHT);

    while(Q--)
    {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", Orig[query(Root[l-1], Root[r], k, 1, 1, RIGHT)]);
    }
}
