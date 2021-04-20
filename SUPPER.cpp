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
#define foreach(it,x) for(auto it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;

int i, n, k, N, M, K;

int mx[100010];
int cnt[100010];
int opt[100010];
int id[100010];
set<int> S;
int s[100010];
set<int> ans;

int main(){
int a, b, c, d;
cin >> N;
REP(a, N) scanf("%d", s+a);
REP(a, N){
    if(S.insert(s[a]).se){
        auto k = S.find(s[a]);
        k++;
        if(k!=S.end())S.erase(k);
    }
}
for(auto a : S){
    mx[i] = a;
    opt[i++] = a;
    cnt[a] = 1;
    ans.insert(a);
}
i = 0;
REP(a, N){
    if(i == S.size()) break;
    if(opt[i] == s[a]) id[i++] = a;
}
i = S.size()-1;
mx[S.size()] = 2e9;
for(a=N-1;a>=0;a--){
    int p = lower_bound(mx, mx+S.size(), s[a])-mx;
    if(p == 0) continue;
    if(mx[p] == s[a]) continue;
    p--;
    if(id[p] > a){
        mx[p] = s[a];
        ans.insert(s[a]);
    }
    if(i>=0 and a == id[i]){
        i--;
    }
}
cout << ans.size() << "\n";
for(auto a: ans){
    printf("%d ", a);
}
return 0;
}
