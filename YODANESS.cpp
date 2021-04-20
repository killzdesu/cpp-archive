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
map<string, int> m;

struct fenwick{
    int m[2*40010], N;

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

int main(){
int a, b, c, d;
int R;
string S[30010], TS;
cin >> R;
while(R--){
    cin >> N;
    REP(a, 80000) F.m[a] = 0;
    F.init(40000);
    REP(a, N){
        cin >> S[a];
    }
    REP(a, N){
        cin >> TS;
        m[TS] = a+1;
    }
    k = 0;
    for(a=N-1;a>=0;a--){
        c = m[S[a]];
        k += F.query(c);
        F.update(c, 1);
    }
    printf("%d\n", k);
}



return 0;
}
