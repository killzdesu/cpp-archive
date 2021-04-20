#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(all(x));(x).resize(distance((x).begin, unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()


using namespace std;

int i, n, k, N, M, K;
vector<int> A[303];

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
    cin >> M;
    while(M--){
        scanf("%d", &c);
        A[a].pb(c);
    }
    sort(A[a].begin(), A[a].end());
}
cin >> M;
vector<int> T;
int ans;
while(M--){
    ans = 0;
    scanf("%d", &d);
    scanf("%d", &K);
    T.clear();
    while(K--){
        scanf("%d", &c);
        T.pb(c);
    }
    sort(ALL(T));
    REP(a, N){
        k = 0;
        i = 0;
        REP(b, sz(A[a])){
            while(i < T.size() and T[i] < A[a][b]) i++;
            if(i == T.size()) break;
            if(T[i] == A[a][b]){
                k++; i++;
            }
        }
        if(d == 1){
            if(k == T.size()) ans++;
        }
        if(d == 2 and k >= 1) ans++;
        if(d == 3 and k >= 1 and k <= T.size()-1) ans++;
//        printf("%d:: %d\n", a, k);
    }
    printf("%d\n", ans);
}


return 0;
}
