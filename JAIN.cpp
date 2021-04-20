#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(x,y) for(x=0;x<(int)y;x++)
#define REPI(x,y) for(x=1;x<(int)y;x++)
#define pii pair<int,int>
#define ll long long
#define ALL(x) (x).begin(),(x).end()

using namespace std;

int i, N, M, K, k;
int chk[100010][5];
vector<int> v[100];

int toNum(char x){
	if(x == 'a') return 0;
	if(x == 'e') return 1;
	if(x == 'i') return 2;
	if(x == 'o') return 3;
	if(x == 'u') return 4;
}

int main(){
	int a, b, c, d;
	int T;
	string S;
	cin >> T;
	ll cnt=0;
	while(T--){
		cin >> N;
		REP(a, N){
			c = 0;
			cin >> S;
			for(auto x: S) chk[a][toNum(x)]=1;
			c = (chk[a][0]<<4) + (chk[a][1]<<3) + (chk[a][2]<<2) + (chk[a][3]<<1) + chk[a][4];
			cnt += v[(~c)&31].size();
			for(b=0;b<32;b++) if(!(b&((~c)&31))){
				v[b].pb(a);
			}
		}
		cout << cnt << '\n';
		REP(a, N){
			REP(b, 5) chk[a][b] = 0;
		}
		REP(a, 100) v[a].clear();
		cnt = 0;
	}



	return 0;
}
