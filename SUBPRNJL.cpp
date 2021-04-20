#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
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
using namespace __gnu_pbds; 

typedef tree<
pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int i, N, M, K, k;
int s[2010];
int cnt[2010];
int MAXK;
multiset<int> S;
ordered_set os;

int calc(int x){
	int F = cnt[x];
	if( (F!=0 and cnt[F]!=0) ){
		/* printf("%dF %d, %d, %d\n", os.size(), x, cnt[x], cnt[F]); */
		return 1;
	}
	return 0;
}

int main(){
	int a, b, c, d, i;
	int T;
	int in, out, now;
	double cal;
	auto it=os.begin();
	cin >> T;
	while(T--){
		cin >> N >> K;
		int SUM = 0;
		REP(a, N) cin >> s[a];
		REP(i, N){
			os.clear();
			fill(cnt, cnt+N+1, 0);
			for(a=i;a<N;a++){
				d = a-i+1;
				MAXK = (int)ceil((double)K/d)*d;
				c = 1+(int)floor((double)MAXK-K)/(MAXK/d);
				os.insert(mp(s[a], a));
				cnt[s[a]]++;
				it = os.find_by_order(d-c);
				SUM += calc(it->fi);
			}
		}
		cout << SUM << "\n";
	}

	return 0;
}
