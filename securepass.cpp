#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(all(x));(x).resize(distance((x).begin, unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()


using namespace std;

int i, n, k, N, M, K;

ll A, B;
ll m10[20];

int main(){
int a, b, c, d;
cin >> N;
m10[0] = 1;
for(a=1;a<=15;a++) m10[a] = m10[a-1]*10;
while(N--){
    cin >> c >> d;
    A = 0;
    for(a=c;a<=d;a++){
        A += m10[a];
    }
    if(A > 1000000) printf("YES\n");
    else printf("NO\n");
}



return 0;
}
