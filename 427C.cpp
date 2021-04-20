#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int N, K, T, M, d[100010], vs[100010], g[100010], mn[100010], G, ord[100010];
long long k, s[100010], C, way;
vector<int> v[100010], vt[100010];
vector<int> grp[100010];

void dfs_vt(int x){
    if(vs[x] == K) return;
    vs[x] = K;
    for(int a=0;a<vt[x].size();a++){
        dfs_vt(vt[x][a]);
    }
    d[x] = T++;
    return;
}

void dfs(int x){
    if(vs[x] == K) return;
    vs[x] = K;
    g[x] = G;
    k = min(s[x], k);
    grp[G].push_back(x);
    for(int a=0;a<v[x].size();a++){
        dfs(v[x][a]);
    }
    return;
}

bool cmp(int a, int b){
    return d[a] > d[b];
}

int main(){
int a, b, c;
cin >> N;
for(a=0;a<N;a++){
    scanf("%I64d", &s[a]);
    ord[a] = a;
}
cin >> M;
for(a=0;a<M;a++){
    scanf("%d %d", &c, &b);
    c--;b--;
    v[c].push_back(b);
    vt[b].push_back(c);
}
K = 1;
for(a=0;a<N;a++){
    dfs_vt(a);
}
sort(ord, ord+N, cmp);
K = 2;
for(a=0;a<N;a++){
    k = 2e9;
    if(vs[ord[a]] != K){
        G++;
        dfs(ord[a]);
        C += k;
        mn[G] = k;
    }
}
for(a=1;a<=G;a++){
    c = 0;
    for(b=0;b<grp[a].size();b++){
        if(s[grp[a][b]] == mn[a]) c++;
    }
    way *= c;
    way %= 1000000007;
}
cout << C << " " << way;

return 0;
}
