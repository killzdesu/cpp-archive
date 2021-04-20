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
char s[100010];
int SAN[100010];
int SA[100010];

bool cmpNoob(int a, int b){
    return strcmp(s+a, s+b) < 0;
}

void buildSuffixArray(int n)
{
    int a;
    REP(a, N) SAN[a] = a;
    sort(SAN, SAN+N, cmpNoob);
}

int gap;
int pos[100010];
int sa[100010];
int tmp[100010];

bool sufcmp(int i, int j){
    if (pos[i]!=pos[j])
        return pos[i] < pos[j];
      i += gap;
      j += gap;
      return (i < N && j < N)?pos[i]<pos[j]:i>j;
}

void buildSA()
{
    REP(i, N){
        SAN[i] = i;
        pos[i] = s[i];
    }

    for (gap = 1;; gap *= 2)
    {
        sort(SAN, SAN + N, sufcmp);

        REP(i, N-1) tmp[i+1] = tmp[i] + sufcmp(SAN[i], SAN[i+1]);
        REP(i, N) pos[SAN[i]] = tmp[i];
        if (tmp[N-1] == N-1) break;
    }
}


int height[100010], rank[100010];

void getHeight(int n, int *pos){
  for (int i=0; i<n; ++i) rank[pos[i]] = i;
  height[0] = 0;
  int h = 0;
  for (int i=0; i<n; ++i){
    if (rank[i] > 0){
      int j = pos[rank[i]-1];
      while (i + h < n and j + h < n and s[i+h] == s[j+h]) h++;
      height[rank[i]] = h;
      if (h > 0) h--;
    }
  }
}

int main(){
int a, b, c, d;
cin >> s;
N = strlen(s);
//buildSuffixArray(N);
buildSA();
REP(a, N){
    printf("%d ", SAN[a]);
}
getHeight(N, SAN);
EL;
REP(a, N){
    printf("%d ", height[a]);
}

return 0;
}
