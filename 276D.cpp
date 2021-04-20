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
ll x, y;
int main(){
	int a, b, c, d;
	int T;
	cin >> x >> y;
	bitset<60> A(x);	
	bitset<60> B(y);	
	for(a=59;a>=0;a--){
		if(A[a]==0 && B[a]==1) break;
	}
	if(a<0) cout << "0";
	else {
		ll ans=1;
		REP(b, a+1) ans *= 2;
		cout << ans-1;
	}


	return 0;
}
