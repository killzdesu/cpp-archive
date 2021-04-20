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

int i, N, M, K;
ll n,k;

int main(){
	int a, b, c, d;
	int T;
	cin >> n >> k;
	if(k == 1){
		cout << n;
		return 0;
	}
	bitset<60> x(n);
	for(a=59;a>=0;a--){
		if(x[a]==1) break;
	}

	ll sum = 1;
	if(a>0){
		for(;a>=0;a--) sum*=2;
		cout << sum-1;
	}
	else if(a==0) cout << 0;
	else {
		cout << 0;
	}

	return 0;
}
