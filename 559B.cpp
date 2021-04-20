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
string S[3];
string T1, T2;

void getLex(int i, int l, int r){
	if((r-l)%2 == 1) return;
	getLex(i, l, (l+r)/2);
	getLex(i, (l+r)/2, r);
	T1 = S[i].substr(l, (r-l)/2);
	T2 = S[i].substr((r+l)/2, (r-l)/2);
	if(T1 > T2){
		S[i].replace(l, (r-l)/2, T2);
		S[i].replace((r+l)/2, (r-l)/2, T1);
	}
	else {
		S[i].replace(l, (r-l)/2, T1);
		S[i].replace((r+l)/2, (r-l)/2, T2);
	}
}

int main(){
	int a, b, c, d;
	int T;
	cin >> S[1] >> S[2];
	getLex(1, 0, S[1].size());
	getLex(2, 0, S[1].size());
	cout << (S[1]==S[2]?"YES":"NO");
	/* cout << S[1] << '\n' << S[2]; */
	return 0;
}
