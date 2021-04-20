#include<cstdio>
#include<iostream>
#include<algorithm>
#include<unordered_map>
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
int val[100010], L[100010], R[100010];
bool par[100010];
unordered_map<int, bool> m;

void DFS(int x, int MIN, int MAX){
	if(MIN < val[x] && val[x] < MAX) m[val[x]]=true;
	if(R[x] != -1)
		DFS(R[x], max(val[x], MIN), MAX);
	if(L[x] != -1)
		DFS(L[x], MIN, min(val[x], MAX));
}

int main(){
	int a, b, c, d;
	int T;
	cin >> N;
	REPI(a, N){
		cin >> val[a] >> L[a] >> R[a];
		par[L[a]] = 1;
		par[R[a]] = 1;
	}
	REPI(a, N) if(par[a]==0)break;
	DFS(a, -2e9, 2e9);
	c = 0;
	REPI(a, N) if(m[val[a]]==true) c++;
	cout << N-c;

	return 0;
}
