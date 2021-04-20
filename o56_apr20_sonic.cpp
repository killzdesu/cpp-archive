#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<queue>
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

int i, n, k, N, M, K, L;

struct fenwick{
    int m[2*300010], N;

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
}fl, fr;

int main(){
int a, b, c, d;
cin >> N >> L;
int r, o;
fl.init(300002);
fr.init(300002);
REP(r, N){
//    L = 100;
    scanf("%d", &o);
    if(o == 1){
        scanf("%d %d %d", &b, &c, &d);
        fl.update(100001-(b-abs(c+L)), d);
        printf("UPDATE L: %d = %d\n", (b-abs(c+L)), d);
        fr.update(200001+(b-abs(L-c)), d);
        printf("UPDATE R: %d = %d\n", (b-abs(L-c)), d);

    }
    else {
        scanf("%d %d", &b, &c);
        printf("%d\n", fl.query(100001-(b-abs(c+L)))+fr.query(200001+(b-abs(L-c))));
        printf("QUERY L: %d = %d\n", (b-abs(c+L)), fl.query(100001-(b-abs(c+L))));
        printf("QUERY R: %d = %d\n", (b-abs(L-c)), fr.query(200001+(b-abs(L-c))));
    }
}


return 0;
}
