#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define EL printf("\n");
#define DB if(DBG)printf
#define IT iterator
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

using namespace std;

int DBG=1;
int i, n, k, N, M, K;

bool qs(char x) {
    return (x == '?');
}

char t[2000010];
char p[20010];
int gs[20010];
int suff[20010];
int F[20010];

// Pay attention!
// the prefix under index i in the table above is
// is the string from pattern[0] to pattern[i - 1]
// inclusive, so the last character of the string under
// index i is pattern[i - 1]

void build_failure_function(char p[]) {

    int i, j;
    int m = strlen(p);
    F[0] = F[1] = 0; // always true

    for(i=2; i<=m; i++) {
        j = F[i-1];
        while(1) {
            if(p[j] == p[i-1]) {
                F[i] = j+1;
                break;
            }
            if(j == 0) {
                F[i] = 0;
                break;
            }
            j = F[j];
        }
    }
}

int kmp(char* t, int N, char *p, int M){
    build_failure_function(p);
    int now = 0;
    int i = 0, cnt = 0;
    while(i < N){
        if(t[i] == p[now]){
            i++;
            now++;
            if(now == M) cnt++;
        }
        else if(now > 0) now = F[now];
        else i++;
    }
    return cnt;
}

int main() {
    int a, b, c, d;
    cin >> N >> M;
    scanf("%s", t);
	scanf("%s", p);
	printf("%d", kmp(t, N, p, M));
    return 0;
}
