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

int i, n, k, N, M, K;

struct ar{
    char S[50];
};

//char s[250][50], t[250][50];

ar s[250], t[250];

bool cmp(ar s, ar t){
    return s.S[k] < t.S[k];
}

int main(){
    freopen("C:\\Users\\Jui\\Downloads\\A-small-practice.in", "r", stdin);

//    freopen("ggg.txt", "w", stdout);
int a, b, c, d;
int T, R;
cin >> T;
REPI(R, T){
    cin >> N >> M;
    REP(a, N){
        scanf("%s", s[a].S);
    }
    REP(a, N){
        scanf("%s", t[a].S);
    }
    i = 0;
    REP(b, M){
        k = b;
        sort(s, s+N, cmp);
        sort(t, t+N, cmp);
        int cnt_s=0, cnt_t=0;
        REP(a, N) if(s[a].S[b] == '1')cnt_s++;
        REP(a, N) if(t[a].S[b] == '1')cnt_t++;
        if(cnt_s == cnt_t){
            ;
        }
        else if(cnt_s == N-cnt_t){
            i++;
        }
        else {
            i = -1;
            break;
        }
    }
    if(i == -1)printf("Case #%d: NOT POSSIBLE\n", R);
    else printf("Case #%d: %d\n", R, i);
}


return 0;
}
