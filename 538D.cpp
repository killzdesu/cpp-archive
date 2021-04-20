#include<bits/stdc++.h>

using namespace std;

int i, n, k, N, M, K;

char in[100][100], s[200][200], t[100][100];

vector<pii> p;

int chk(int x, int y){
	if(x < 0 or y < 0 or x >= N or y >= N) return 1;
	if(in[x][y] == '.') return 0;
    return 1;
}

int test(int x, int y){
    x -= N-1;
    y -= N-1;
    int a;
    int c = 1;
    for(auto X: p){
		if(chk(X.fi+x, X.se+y) == 0) c = 0;
    }
    return c;
}

int main(){
int a, b, c, d;
cin >> N;
REP(a, N){
	scanf("%s", in[a]);
}
REP(a, N) REP(b, N) if(in[a][b] == 'o') p.pb(mp(a, b));
REP(a, N*2-1){
	REP(b, N*2-1){
		s[a][b] = '.';
		if(a == N-1 and b == N-1) continue;
		if(test(a, b)) s[a][b] = 'x';
	}
}
s[N-1][N-1] = 'o';

REP(a, N) REP(b, N) t[a][b] = '.';
for(auto X: p){
	int x, y;
    REP(a, 2*N-1) REP(b, 2*N-1){
        x = X.fi; y = X.se;
        x += a-N+1; y += b-N+1;
        if(s[a][b] != 'x') continue;
        if(x < 0 or y < 0 or x >= N or y >= N) continue;
        t[x][y] = 'x';
    }
}
for(auto X: p){
    t[X.fi][X.se] = 'o';
}
c = 1;
REP(a, N){
	REP(b, N){
		if(t[a][b] != in[a][b]) c = 0;
	}
}
if(c == 0){
	cout << "NO";
	return 0;
}
cout << "YES\n";
REP(a, N*2-1){
	REP(b, N*2-1)
		printf("%c", s[a][b]);
	EL;
}

return 0;
}
