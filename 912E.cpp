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
ll P[20];
priority_queue<ll, vector<ll>, greater<ll> > Q;
unordered_map<ll, int> m;

int main(){
	int a, b, c, d;
	int T;
	cin >> N;
	REP(a, N) cin >> P[a];
	cin >> k;
	k--;
	ll t;
	Q.push(1);
	m[1] = 0;
	while(k){
		t = Q.top(); Q.pop();	
		for(a=N-1;a>=0 && P[a]>=m[t];a--){
			if(P[a]*t < 1000000000000000001){
				m[P[a]*t] = P[a];
				Q.push(P[a]*t);
			}
		}
		k--;
	}
	cout << Q.top();

	return 0;
}
