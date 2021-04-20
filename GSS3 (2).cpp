#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(x,y) for(x=0;x<(int)y;x++)
#define REPI(x,y) for(x=1;x<=(int)y;x++)
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define ll long long
#define ALL(x) (x).begin(),(x).end()

using namespace std;

int i, N, M, K, k;
int s[900000];

struct Node{
	int val, l, r, pre, post, sm;
}t[300005], dmmy;

Node calc(Node L, Node R){
	Node ans;
	ans.pre = max(L.pre, L.sm+R.pre);
	ans.post = max(R.post, L.post+R.sm);
	ans.val = max(L.val, R.val);
	ans.val = max(ans.val, L.post+R.pre);
	ans.sm = L.sm + R.sm;
	ans.l = L.l;
	ans.r = R.r;
	return ans;
}

void build(int k, int l, int r){
	t[k].l = l;
	t[k].r = r;
	if(l==r-1){
		t[k].val = s[l];
		t[k].sm = s[l];
		t[k].pre = s[l];
		t[k].post = s[l];
		/* printf("%d: %d %d --> %d\n", k, l, r, t[k].val); */
		return;
	}
	build(k*2, l, (l+r)/2);
	build(k*2+1, (l+r)/2, r);
	t[k] = calc(t[k*2], t[k*2+1]);
	/* printf("%2d: %2d %2d --> %d\n", k, l, r, t[k].val); */
	/* printf("%4d %4d\n", t[k].pre, t[k].post); */
	/* printf("\n"); */
}

Node query(int k, int lo, int hi){
	if(hi <= t[k].l or t[k].r <= lo){
		/* printf("%d: none %d %d \n", k, t[k].l, t[k].r); */
		return dmmy;
	}
	/* if(t[k].l == t[k].r-1) return t[k]; */	
	/* printf("Call %d %d\n", t[k].l, t[k].r); */
	if(lo <= t[k].l and t[k].r <= hi){
		/* printf("IN RANGE %d %d\n", lo, hi); */
		return t[k];
	}
	Node L=query(k*2, lo, hi);
	Node R=query(k*2+1, lo, hi);
	return calc(L, R);
}

void update(int k, int tar, int V){
  if(tar < t[k].l or t[k].r <= tar) return;
  if(t[k].l == t[k].r-1){
    t[k].sm = t[k].val = t[k].post = t[k].pre = V;
    return;
  }
  update(k*2, tar, V);
  update(k*2+1, tar, V);
	t[k] = calc(t[k*2], t[k*2+1]);
}

int main(){
	int a, b, c, d;
	int T;
	cin >> N;
	REP(a, N) scanf("%d", &s[a]);
	build(1, 0, N);

	dmmy.pre = dmmy.post = -2e8;
	dmmy.val = -2e8;


	cin >> M;
	while(M--){
		
		scanf("%d%d%d", &b, &c, &d);
		if(b)printf("%d\n", query(1,c-1,d).val);
		else {
      update(1, c-1, d);
		}
	}

	return 0;
}
