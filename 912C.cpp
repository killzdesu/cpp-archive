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
int B, I, D;

struct enemy{
	int regen, maxhp, hp, t;
}E[100010];

struct Time{
	int id, hp, t, type;
	Time(int a, int b, int c, int d){
		id = a;
		hp = b;
		t = c;
		type = d; 
	}
	bool operator <(const Time& r) const{
		if(t != r.t)
			return t > r.t;
		return type > r.type;
	}
} ;
vector<Time> tl;
priority_queue<Time> pq;

bool cmp(Time a, Time b){
}

ll MAX_VAL;

int main(){
	int a, b, c, d;
	cin >> N >> M;
	cin >> B >> I >> D;
	REP(a, N){
		scanf("%d%d%d", &b, &c, &d);
		pq.push(Time(a+1, c, 0, 0));
		E[a+1].maxhp = b;
		E[a+1].regen = d;
	}
	while(M--){
		scanf("%d%d%d", &b, &c, &d);
		pq.push(Time(c, d, b, 0));
	}
	sort(ALL(tl));
	Time T;
	while(!pq.empty()){
		T = pq.top();
		pq.pop();
		if(T.type==0){
			if(T.hp > D) continue;
			E[T.id].hp = T.hp;
			E[T.id].t = T.t;
			c = (int)floor(((double)D-E[T.id].hp)/E[T.id].regen);
			pq.push(Time(T.id, -1, T.t+c, 1);
		}
		else if(T.type==1){
				
		}
	}
	return 0;
}
