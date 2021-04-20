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

struct que{
    ll x;
    int y;
    char c;
}q[100010];

ll ans[100010];

int i, n, k, N, M, K;
string S;
deque<char> Q;
char ss[10];

int main(){
//freopen("stamper.txt", "r", stdin);
int a, b, c, d;
cin >> N >> M;
cin >> S;
REP(a, S.size()){
    Q.pb(S[a]);
}
ss[0] = '\0';
ll tc;
REP(a, N){
    scanf("%lld %d", &tc, &d);
    if(d == 1){
        scanf("%s", ss);
    }
    q[a] = {tc+1, d, ss[0]};
}
REP(a, M){
    scanf("%lld", &ans[a]);
}
ll ro = 1;
ll beg = 1;
ll roi, df;
i = 0;
for(a=0;a<N;a++){
    if(i == M) return 0;
    roi = ans[i]-beg;
    roi /= (int)Q.size();
    roi += ro;
//    printf("%d vs %d\n", roi, q[a].x);
    if(roi < q[a].x){
        if(roi > ro){
            df = roi-ro;
            beg += df*Q.size();
            df %= (ll)Q.size();
            while(df--){
                Q.push_back(Q.front());
                Q.pop_front();
            }
            ro = roi;
        }
        printf("%c\n", Q[ans[i]-beg]);
        i++;
        a--;
    }
    else {
        if(q[a].x > ro){
            df = q[a].x-ro;
            beg += df*Q.size();
            df %= (ll)Q.size();
            while(df--){
                Q.push_back(Q.front());
                Q.pop_front();
            }
            ro = q[a].x;
        }
        if(q[a].y == 1){
            Q.pb(q[a].c);
        }
        else Q.pop_back();
    }
//    cout << ro << ":: ";
//    for(auto x: Q) cout << x << " "; EL;
}

for(;i<M;i++){
    roi = ans[i]-beg;
    roi /= (ll)Q.size();
    roi += ro;
    if(roi > ro){
        df = roi-ro;
        beg += df*Q.size();
        df %= (ll)Q.size();
        while(df--){
            Q.push_back(Q.front());
            Q.pop_front();
        }
        ro = roi;
    }
    printf("%c\n", Q[ans[i]-beg]);
}

return 0;
}
