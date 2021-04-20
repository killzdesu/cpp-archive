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
#define IT iterator
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;

int i, n, k, N, M, K;

struct fenwick{
    int m[2*100010], N;

    void init(int n){
        N = n;
    }

    void update(int x, int val){
        while(x <= N){
            m[x] += val;
            x += (x&-x);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0){
            sum += m[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }


}F;

struct node{
    int val, id;
    bool operator < (const node &b) const {
        return (val != b.val ? val > b.val : id > b.id);
    }
}t;

priority_queue<node> Q;

int main(){
int a, b, c, d;
cin >> N;
F.init(N+5);
REPI(a, N) F.update(a, 1);
REPI(a, N){
    scanf("%d", &c);
    t.val = c;
    t.id = a;
    Q.push(t);
}
ll tim = 0;
int r = 1;
ll ans[50010];
queue<int> del;
while(!Q.empty()){
    t = Q.top();
    Q.pop();
    if(r < t.val){
        tim += (ll)F.query(N+1);
        while(!del.empty()){
            F.update(del.front(), -1);
            del.pop();
        }
        tim += ((ll)F.query(N+1))*(ll)(max(0, t.val-r-1));
        r = t.val;
    }
    ans[t.id] = tim + F.query(t.id);
    del.push(t.id);
}
REPI(a, N) printf("%lld\n", ans[a]);
return 0;
}
