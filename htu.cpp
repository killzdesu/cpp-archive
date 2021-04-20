#include <cstdio>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

#define MAX_N 1000
#define TRIALS 100

bool used[MAX_N][MAX_N];

int n,m;
vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input()
{
  scanf("%d %d",&n,&m);
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      used[i][j] = false;

  for(int i=0; i<m; i++) {
    int u,v;
    scanf("%d %d",&u,&v); u--; v--;
    if(used[u][v]) {
      printf("Input error\n");
      exit(0);
    }

    used[u][v] = used[v][u] = true;
    adj[u].push_back(v);
    deg[u]++;
    if(u!=v) {
      adj[v].push_back(u);
      deg[v]++;
    }
  }
}

long long ht(int s, int t)
{
  int u = s;
  int c = 0;
  while(u!=t) {
    int vindex = ((rand()) % deg[u]);
    int v = adj[u][vindex];
    c++;
    u = v;
  }
  return c;
}

main()
{
  long long total = 0;
    freopen("Hi.txt", "r", stdin);
  srand((long int)(time(0)));
  read_input();
  for(int i=0; i<TRIALS; i++) {
    long long c = ht(0,n-1);
    total += c;
  }
  double avr = ((double)total)/TRIALS;
  printf("%f\n",avr);
}
