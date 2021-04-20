#include<bits/stdc++.h>
#define REP(x,y) for(x=0;x<(int)y;x++)
#define REPI(x,y) for(x=1;x<=(int)y;x++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

int i, N, M, K;

vector<int> cp;
pii p[300010], pp[300010];
long long dp[600010];
vector<int> ED[600010];

priority_queue<int, vector<int>, greater<int> > q;

int main(){
int a, b, c, d;
int T;
cin >> N >> M;
REP(a, N){
	cin >> p[a].fi >> p[a].se;
	p[a].se++;
	cp.pb(p[a].fi);
	cp.pb(p[a].se);
}
sort(cp.begin(), cp.end());
cp.resize(distance(cp.begin(), unique(cp.begin(), cp.end())));

REP(a, N){
	p[a].fi = (int)(lower_bound(cp.begin(), cp.end(), p[a].fi)-cp.begin());
	p[a].se = (int)(lower_bound(cp.begin(), cp.end(), p[a].se)-cp.begin());
	// printf("%d %d\n", p[a].fi, p[a].se);
//	dp[p[a].fi]++;
	//dp[p[a].se]--;
	ED[p[a].se].pb(a);
	pp[a] = p[a];
}
sort(pp, pp+N);
int i=0;
int MAX=0, start=-1, op, ed;
int cnt=0;
REP(a, cp.size()){
	while(!q.empty() and q.top() <= a) q.pop();
	while(i<N and pp[i].fi == a){
		q.push(pp[i].se);
		if(q.size() >= M){
			while(q.size() > M) q.pop();
			c = cp[q.top()]-cp[pp[i].fi];
			if(MAX < c){
				MAX = c; op = pp[i].fi; ed = q.top();
			}
		}
		i++;
	}
}

//REP(a, cp.size()) printf("%d: %d\n", a, dp[a]);

cout << MAX << endl;
if(!MAX){
	REPI(a, M) printf("%d ", a);
	return 0;
}
REP(a, N){
	if(p[a].fi <= op and p[a].se >= ed){
		printf("%d ", a+1);
		M--;
	}
	if(M == 0) break;
}

return 0;
}

