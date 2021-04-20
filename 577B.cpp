#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(x,y) for(x=0;x<(int)y;x++)
#define REPI(x,y) for(x=1;x<=(int)y;x++)
#define pii pair<int,int>
#define ll long long
#define ALL(x) (x).begin(),(x).end()

using namespace std;

int i, N, M, K, k;
set<int> S, A;
vector<int> cp;
int dp[2][1005];
unordered_map<int, int> m;

int main(){
	int a, b, c, d;
	int T;
	cin >> N >> M;
	REP(a, N){
		cin >> c;
		m[c%M]++;
		if(c%M==0){puts("YES");return 0;}
	}
	int sw = 0;
	for(a=1;a<M;a++){
		c = m[a];
		if(c == 0) continue;
		d = 0;
		S.clear();
		REP(b, c){
			d += a;
			d%=M;
			S.insert(d);
		}
		for(i=0;i<M;i++) dp[sw^1][i] |= dp[sw][i];
		for(auto x:S){
			for(i=0;i<M;i++){
				dp[sw^1][(i+x)%M] |= dp[sw][i];
			}
			dp[sw^1][x] = 1;
		}
		sw ^= 1;
		/* REP(b, M){ */
		/* 	printf("%d ", dp[sw][b]); */
		/* }cout << '\n'; */
	}
	cout << (dp[sw][0]?"YES":"NO");

	return 0;
}
