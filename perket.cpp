#include<iostream>
#include<algorithm>

using namespace std;

int s, b, N, S[15], B[15];
int best;

void build(int i){
	if(i == N){
		if(s == 1 and b == 0) return;
        best = min(best, abs(s-b));
		return;
	}
    s *= S[i];
    b += B[i];
    build(i+1);
    s /= S[i];
    b -= B[i];
    build(i+1);
}

int main(){
cin >> N;
for(int i=0;i<N;i++) cin >> S[i] >> B[i];
best = 2e9; //= 2*10^9 = 2000M
s = 1; b = 0;
build(0);
cout << best;
return 0;
}
