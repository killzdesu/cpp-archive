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

ll i, N, M, K, k;

int main(){
	int a, b, c, d;
	int T;
	cin >> N >> M;
	ll x, y, z;
	ll B=0, Y=0;
	cin >> x >> y >> z;
	Y += 2*x+y;
	B += y+3*z;
	ll sum = 0;
	if(N < Y) sum += Y-N;
	if(M < B) sum += B-M;
	cout << sum;

	return 0;
}
