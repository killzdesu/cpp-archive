#include<stdio.h>
#include<algorithm>

using namespace std;

typedef long long ll;

int N;
ll s[2000005];
ll qs[2000005];

int main(){
//freopen("input_10", "r", stdin);
int a, b, c;
scanf("%d", &N);
for(a=1;a<=N;a++){
	scanf("%lld", &s[a]);
	s[a+N] = s[a];
}
for(a=1;a<=2*N;a++){
	qs[a] = s[a];
	qs[a] += qs[a-1];
}
ll sum = 0, mx;
for(a=1;a<=N;a++){
    sum += min(a-1, N-a+1)*s[a];
}
mx = sum;
int i = N/2+1;
for(a=2;a<=N;a++){
    sum -= qs[a+N/2-1] - qs[a-1];
    sum += qs[a+N-1] - qs[a+N/2-1];
	if(sum > mx){
		mx = sum;
        i = (a+N/2-1)%N+1;
	}
	else if(sum == mx and i > (a+N/2-1)%N+1){
		i = (a+N/2-1)%N+1;
	}
}
printf("%d %lld", i, mx);
}
