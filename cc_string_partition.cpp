#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin(), unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define dump(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

int i, n, k, N, M, K;
char s[100010];
int pr[100010];
vector<int> P;
int chk[300];

void genp(int N){

	P.pb(2);
	for(int i=3;i<=N;i+=2){
		if(pr[i] == 0){
			P.pb(i);
			for(int j=i+i;j<=N;j+=i){
				pr[j] = 1;
			}
		}
	}
}

int main(){
int a, b, c, d;
scanf("%s", s);
N = strlen(s);
genp(N+6);
int mn = 2e9;
for(i=0; i<P.size(); i++){
	k = P[i];
	if(N%k !=0) continue;
	k = N/k;
	int mx = 0;
	int cnt = 0;
    for(a=0;a<k;a++){
        for(b='a'; b<='z'; b++) chk[b] = 0;
        mx = 0;
        for(b=a; b<N; b+=k){
			chk[s[b]]++;
			mx = max(mx, chk[s[b]]);
        }
        cnt += N/k - mx;
    }
    mn = min(mn, cnt);
}
if(mn > 2e8) mn = 0;
cout << mn;

return 0;
}
