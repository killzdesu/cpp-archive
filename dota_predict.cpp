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
#define dump(x) cerr<<#x<<"="<<x<<"\n"

using namespace std;

int i, n, k, N, M, K;

struct perceptron{
    int N;
    double w[100];
    double LR;

    void init(int n, double lr){
        N = n;
        LR = lr;
        for(int a=0;a<N;a++){
            w[a] = 1;//((a+1)*7)%10+1;
        }
    }

    int test(double x[]){
        double sm = 0;
        for(int a=0;a<=N;a++){
            sm += w[a]*x[a];
        }
        if(sm > 0) return 1;
        return -1;
    }

    void adapt(double t, double o, double x[]){
        for(int a=0;a<=N;a++){
            w[a] = w[a]+LR*(t-o)*x[a];
        }
    }
};

struct data{
    double x[100];
    int t;
}z[20010], A;

string S;
map<string, double> m;
double xx;

int main(){
int a, b, c, d;
int lim = 10;
xx = 1;
freopen("dota_match.txt", "r", stdin);
perceptron P;
P.init(10, 1.3);

REP(a, lim){
    REPI(b, 10){
        cin >> S;
        if(m[S] == 0){
            m[S] = xx;
            xx++;
        }
//        dump(m[S]);
        z[a].x[b] = m[S];
    }
    scanf("%d", &c);
    z[a].x[0] = 1.0;
    if(c == 1)z[a].t = -1;
    else z[a].t = 1;

    REPI(b, 10) printf("%.2f ", z[a].x[b]);
    cout << z[a].t << "\n";
}
cout << "Pass";
//return 0;
int cnt;
while(1){
    k++;
    cnt = 0;
    REP(a, lim){
        d = P.test(z[a].x);
        if(d == z[a].t) cnt++;
        P.adapt(z[a].t, d, z[a].x);
    }
    printf("%d \n", cnt);
    if(cnt == lim) break;
}
cout << k << "<<\n";

return 0;
for(a=0;a<19;a++){
    cin >> A.x[1] >> A.x[2];
    A.x[0] = 1;
    if(P.test(A.x) == -1) printf("Brown\n");
    else printf("Blue\n");
}

return 0;
}
