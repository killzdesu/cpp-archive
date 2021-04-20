#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define dump(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int i, j, n, k, N, M, K;
string sx, sy;
int x[10010], y[10010];
const int dig = 10;

int* mul(int *x, int *y, int i, int j){
	int a, b, c = 0, t;
	int res[i+j+2], tod;
	if(i == 1){
        for(a=0; a<j; a++){
			t = (x[0]* y[a])+tod;
            res[a] = (t % dig);
            tod = t/dig;
        }
        if(res[a])
	}
    for()
}

int main(){
int a, b, c, d;
int T;
cin >> T;
while(T--){
    cin >> sx >> sy;
    i = 0;
    int m = 1;
    for(a = sx.length()-1; a >= 0; a--){
		if(m == dig){
			m = 1;
			i++;
        }
        x[i] += m*(sx[a]-'0');
        m *= 10;
    }
    j = 0;
    m = 1;
    for(a = sy.length()-1; a >= 0; a--){
		if(m == dig){
			m = 1;
			j++;
        }
        y[j] += m*(sy[a]-'0');
        m *= 10;
    }
}


return 0;
}
