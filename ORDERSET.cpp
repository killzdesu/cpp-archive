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

//struct qry{
//    int x, y, t;
//    qry(){}
//    qry(int a, int b, int c){
//        x = a; y = b; t = c;
//    }
//}Q[200010];

pii q[200010];
int m[200010];

void update(int x, int val){
    while(x < 200002){
        m[x] += val;
        x += (x&-x);
    }
}

int query(int x){
    int sm = 0;
    while(x > 0){
        sm += m[x];
        x -= (x&-x);
    }
    return sm;
}

vector<int> cp;

int main(){
int a, b, c, d;
char rr[4];
cin >> N;
REP(a, N){
    scanf("%s %d", rr, &c);
    q[a] = mp(rr[0], c);
    if(rr[0] != 'K') cp.pb(c);
}
sort(cp.begin(), cp.end());
cp.resize(distance(cp.begin(), unique(cp.begin(), cp.end())));
int lo, hi, mi;
REP(a, N){
    if(q[a].fi == 'I'){
        i = distance(cp.begin(), lower_bound(cp.begin(), cp.end(), q[a].se));
        if(query(i+1)-query(i) == 0) update(i+1, 1);
    }
    if(q[a].fi == 'D'){
        i = distance(cp.begin(), lower_bound(cp.begin(), cp.end(), q[a].se));
        if(query(i+1)-query(i) != 0) update(i+1, -1);
    }
    if(q[a].fi == 'C'){
        i = distance(cp.begin(), lower_bound(cp.begin(), cp.end(), q[a].se));
        printf("%d\n", query(i));
    }
    if(q[a].fi == 'K'){
        lo = 0; hi = cp.size()-1;
        if(query(200001) < q[a].se){
            printf("invalid\n");
            continue;
        }
        while(lo < hi){
            mi = lo+(hi-lo)/2;
            if(query(mi+1) >= q[a].se) hi = mi;
            else lo = mi+1;
        }
        printf("%d\n", cp[lo]);
    }

}

return 0;
}
