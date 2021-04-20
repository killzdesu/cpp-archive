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
char s[100100];
stack<char> st;
set<pair<char, int> > S;

int main(){
	int a, b, c, d;
	int T;
	cin >> s;
	N=strlen(s);
	auto it = S.begin();
	REP(a, N) S.insert(mp(s[a], a));
	for(a=0;a<N;a++){
		it = S.begin();
		if(s[a] == it->fi){
			printf("%c", s[a]);
			S.erase(it);
			it = S.begin();
			while(!st.empty() && st.top()<=it->fi){
				printf("%c", st.top());
				st.pop();
			}
		}
		else {
			st.push(s[a]);
			S.erase(mp(s[a], a));
		}
	}
	while(!st.empty()){
		printf("%c", st.top());
		st.pop();
	}

	return 0;
}
