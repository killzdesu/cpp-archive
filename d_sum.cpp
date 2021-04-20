#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define pb push_back

using namespace std;

int i, n, k, N, M, K;

int main(){
int a, b, c, d;
long long A, B, C, X, Y;
cin >> A >> B;
X=(B-1)*B/2;
Y=(A+1)*A/2;
X%=1000000007;
Y%=1000000007;
Y*=B;
Y+=A;
Y%=1000000007;
X*=Y;
X%=1000000007;
cout << X;
return 0;
}
