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
int lp[10000010];

/* void sieve(int n){ */
/* 	for(int a=2;a<=n;a++){ */
/* 		if(lp[a]==0) Prime.pb(a); */
/* 		lp[a] = a; */
/* 		for(auto x:Prime){ */
/* 			if(x > lp[a] || x*lp[a] > n) break; */
/* 				lp[x*lp[a]] = x; */
/* 		} */
/* 	} */
/* } */

const int MAX = 10000002;

int ans[10000100];
int cnt[10000010];


int main(){
	int a, b, d;
	ll c;
	int T;
	cin >> N;
	REP(a, N){
		scanf("%d", &d);
		cnt[d]++;
	}
	for(int i=2;i<MAX;i++){
		ans[i] = ans[i-1];
		if(lp[i]==0){
			for(a=i;a<MAX;a+=i){
				ans[i] += cnt[a];
				lp[a] = 1;
			}
		}
	}
	cin >> T;
	while(T--){
		scanf("%d %d", &a, &b);
		a = min(MAX-1, a);
		b = min(MAX-1, b);
		printf("%d\n", ans[b]-ans[a-1]);
	}

	return 0;
}
