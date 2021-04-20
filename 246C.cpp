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
int p[60];
int L[10000005];

int main(){
	int a, b, c, d;
	int T;
	cin >> N >> k;
	REPI(a, N) scanf("%d", &p[a]);
	L[0] = 60;
	REP(i, 10000001) {
		if(L[i]==0) continue;
		REPI(a, N){
			if(a >= L[i]) break;
			if(p[a]+i <= 10000000) L[p[a]+i] = max(L[p[a]+i], a);
		}
	}
	/* REPI(i, 10) printf("%d ", L[i]); */
	/* return 0; */
	i = 1;
	stack<int> S;
	while(k--){
	/* 	cout << "TEST"; */
		while(L[i]==0)i++;	
		c = L[i];
		d = i;
		/* printf("%d: %d\n", k, c); */
		while(d > 0){
	/* 		printf("#c : %d\n", c); */
			S.push(p[c]);
			d -= p[c];
			c = L[d];
		}
		printf("%d", S.size());
		while(!S.empty()) printf(" %d", S.top()), S.pop();
		printf("\n");
		i++;
	}

	return 0;
}
