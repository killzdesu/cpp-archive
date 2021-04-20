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

int cnt[10];
vector<string> ans;

int main(){
int a, b, c, d;
string S;
cin >> S;
string T;
while(1){
    int cnt = 0;
    T.clear();
    REP(a, S.length()){
		cnt += S[a]-'0';
    }
    if(cnt == 0) break;
	for(a=0;a<S.length();a++){
		if('1' <= S[a] and S[a] <= '9'){
			T.pb('1');
			S[a]--;
		}
		else {
            if(!T.empty())
				T.pb('0');
		}
	}
	ans.pb(T);
}
printf("%d\n", ans.size());
for(auto x: ans){
	printf("%s ", x.c_str());
}


return 0;
}
