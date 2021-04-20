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
pii z[105];
int h[105];
int fh(int x){
	return (h[x]==x?x:h[x]=fh(h[x]));
}

int main(){
	int a, b, c, d;
	int T;
	cin >> N;
	REP(a, N) h[a] = a;
	REP(a, N) scanf("%d%d",&z[a].fi,&z[a].se);
	REP(a, N) REP(b, a){
		if(z[a].fi == z[b].fi || z[a].se == z[b].se){
			h[fh(b)] = fh(a);
		}
	}
	REP(a, N) if(fh(a) == a) k++;
	cout << k-1;


	return 0;
}
