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
int s[100010];
int cnt[10];

int main(){
	int a, b, c, d;
	int ans = 0;
	cin >> N;
	REP(a, N){
		cin >> s[a];
		cnt[s[a]]++;
	}
	ans += cnt[4];
	ans += cnt[2]/2;
	cnt[2] %= 2;
	c = min(cnt[3], cnt[1]);
	cnt[3] -= c;
	cnt[1] -= c;
	ans += c;
	if(cnt[3]){
		ans += cnt[3];
	}
	if(cnt[2]){
		if(cnt[1] >= 2) cnt[1]-=2;
		else cnt[1] = 0;
		ans++;
	}	
	ans += (int)ceil(((double)cnt[1]/4.0));

	cout << ans;

	return 0;
}
