#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin, unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define dump(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;

int i, n, k, N, M, K;

int main(){
int a, b, c, d;
int Px, Py , Vx, Vy;
cin >> Px >> Py >> Vx >> Vy;
if(Px <= Vx and Py <= Vy){
    cout << "Polycarp";
}
else {
    int mn = min(Vx, Vy);

    if(Vx + Vy - mn >= Px + Py)
    {
        cout << "Polycarp";
    } else {
        printf("Vasiliy");
    }
}


return 0;
}
