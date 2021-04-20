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

int main(){
	int a, b, c, d;
	int T;
	int odd=-2e9, even=-2e9;
	cin >> N;
	int to, te;
	REP(a, N){
		cin >> c;
		if(c%2){
			to = max(odd, even+c);
			te = max(even, odd+c);
			to = max(to, c);
		}
		else {
			te = max(even, even+c);
			to = max(odd, odd+c);
			te = max(te, c);
		}
		odd = to;
		even = te;
	}
	cout << odd;

	return 0;
}
