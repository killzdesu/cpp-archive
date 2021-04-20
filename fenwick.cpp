#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long

using namespace std;

int i, n, k, N, M, K;

struct fenwick{
    int m[2*100010], N;

    void init(int n){
        N = n;
    }

    void update(int x, int val){
        while(x <= N){
            m[x] += val;
            x += (x&-x);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0){
            sum += m[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }


};

int main(){
int a, b, c, d;




return 0;
}
