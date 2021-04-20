#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long

using namespace std;

int i, n, k, N, M, K;
double V[100010], S[100010],v;

pair<double, double> x[100010];
int cnt[200010];
//map<double, int> m;
vector<double> ans;

int m(double i){
    return distance(ans.begin(), lower_bound(ans.begin(), ans.end(), i));
}

int main(){
int a, b, c, d;
cin >> N;
N--;
REP(a, N){
    scanf("%lf %lf", &V[a], &S[a]);
}
cin >> v;

REP(a, N){
    if(V[a] > v){
        x[a].se = S[a];
        x[a].fi = (double)v*((double)S[a]/V[a]);
    }
    else {
        x[a].fi = S[a];
        x[a].se = (double)v*((double)S[a]/V[a]);
    }
    ans.pb(x[a].fi);
    ans.pb(x[a].se);
//    printf("%.2lf, %.2lf\n", x[a].fi, x[a].se);
}

sort(ans.begin(), ans.end());
ans.resize(distance(ans.begin(), unique(ans.begin(), ans.end())));
//REP(a, ans.size()) m[ans[a]] = a;
int mx = 0;
REP(a, N){
    cnt[m(x[a].fi)]++;
    cnt[m(x[a].se)+1]--;
}
REP(a, 200003) cnt[a+1] += cnt[a];
REP(a, 200003) mx = max(cnt[a], mx);
cout << mx;
return 0;
}
