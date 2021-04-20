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
int s[10010];

int main(){
    freopen("C:\\Users\\Jui\\Downloads\\jan_symmetry-input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
int a, b, c, d;
int T, mx;
cin >> T;
while(T--){
    cin >> N;
    c = 0;
    i = -1;
    mx = 0;
    REP(a, N){
        cin >> s[a];
        if(s[a] == 0) c++;
        if(s[a] == 1){
            if(c%2 == 1){
                if(mx < c){
                    mx = c;
                    i = a-(c+1)/2;
                }
            }
            c = 0;
        }
    }
    if(c%2 == 1){
        if(mx < c){
            mx = c;
            i = a-(c+1)/2;
        }
    }
    printf("%d\n", i);
}



return 0;
}
