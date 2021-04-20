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

set<int, greater<int> > S;
set<int, greater<int> >::IT it;
map<int, int> m;

int can(){
    if(S.empty()) return 0;
    int a, c, d, next;
    it = S.begin();
    c = *(it);
    it++;
    if(it == S.end()) d = 0;
    else d = *it;
    next = max(d, (c+1)/2);
    if(c-next >= m[c]) return 1;
    return 0;
}

int s[10010];

int main(){
freopen("B-large.in", "r", stdin);
//freopen("B-large.txt", "w", stdout);
int a, b, c, d;
int T;
cin >> T;
REPI(i, T){
    cin >> N;
    S.clear();
    m.clear();
    REP(a, N){
        cin >> s[a];
    }
    int ans = 2e9;
    REPI(c, 1000){
        k = 0;
        REP(a, N){
            k += s[a]/c-1+(s[a]%c?1:0);
        }
        ans = min(k+c, ans);
    }
    printf("Case #%d: %d\n", i, ans);
}



return 0;
}
