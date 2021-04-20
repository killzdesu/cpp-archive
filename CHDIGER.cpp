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
char s[30];
deque<char> v;

int main(){
	int a, b, c, d;
	int T;
	cin >> T;
	while(T--){
		scanf("%s %d", s, &d);
		N = strlen(s);
		for(int i=1;i<=9;i++){
			for(a=N-1;a>=0;a--){
				if(s[a]==i+'0') break;
			}
			for(;a>=0;a--){
				if(s[a]>i+'0') s[a] = 'x';
			}
		}
		v.clear();
		REP(a, N) if(s[a]!='x') v.pb(s[a]);
		while(!v.empty() && v.back() > d+'0') v.pop_back();
		for(auto x:v) printf("%c", x);
		for(a=v.size();a<N;a++) printf("%d", d);
		printf("\n");
	}


	return 0;
}
