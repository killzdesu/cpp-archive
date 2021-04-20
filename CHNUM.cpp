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

int main(){
	int a, b, c, d;
	int T;
	cin >> T;
	while(T--){
		cin >> N;
		int POS, POS_CNT, NEG, NEG_CNT;
		POS_CNT = 0;
		NEG_CNT = 0;
		REP(a, N){
			cin >> c;
			if(c > 0){
				/* POS += c; */
				POS_CNT++;
			}
			else {
				/* NEG += c; */
				NEG_CNT++;
			}
		}
		if(NEG_CNT == 0 or POS_CNT ==0)
			printf("%d %d\n", max(NEG_CNT, POS_CNT), max(NEG_CNT, POS_CNT));
		else printf("%d %d\n", max(NEG_CNT, POS_CNT), min(NEG_CNT, POS_CNT));
	}


	return 0;
}
