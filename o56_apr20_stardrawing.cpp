#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back

using namespace std;

int i, n, k, N, M, K;

struct star{
    int type, x, y, z;
    bool operator < (const star &b) const{
        if(type!=b.type) return type < b.type;
        if(x != b.x) return x < b.x;
        if(y != b.y) return y < b.y;
        return z < b.z;
    }
}t;

star ms(int d, int a, int b, int c){
    t.type = d;
//    if(a >= b and a >= c){
//        t.x = a;
//        a = -1;
//    }
//    else if(b >= a and b >= c){
//        t.x = b;
//        b = -1;
//    }
//    else if(c >= b and c >= a){
//        t.x = c;
//        c = -1;
//    }
//    // --------------------
//    if(a >= b and a >= c){
//        t.y = a;
//        a = -1;
//    }
//    else if(b >= a and b >= c){
//        t.y = b;
//        b = -1;
//    }
//    else if(c >= b and c >= a){
//        t.y = c;
//        c = -1;
//    }
//    // --------------------
//    if(a >= b and a >= c){
//        t.z = a;
//        a = -1;
//    }
//    else if(b >= a and b >= c){
//        t.z = b;
//        b = -1;
//    }
//    else if(c >= b and c >= a){
//        t.z = c;
//        c = -1;
//    }
    if(a < b) swap(a, b);
    if(b < c) swap(b, c);
    if(a < b) swap(a, b);
    if(b < c) swap(b, c);
    if(a < b) swap(a, b);
    if(b < c) swap(b, c);
    t.x = a;
    t.y = b;
    t.z = c;
    return t;
}

int dmx, d1, loop;
set<star> S;
vector<int> v[100010];
int vs[100010], p[100010];

int find_loop(int x){
    if(p[x]) return 0;
    p[x] = 1;
    int a, c=1;
    REP(a, v[x].size()){
        c += find_loop(v[x][a]);
    }
    return c;
}

int d31, d32, d33;

void dfs(int x){
    if(vs[x]){
        return ;
    }
    vs[x] = 1;
    n++;

    dmx = max(dmx, (int)v[x].size());
    if(v[x].size() == 1) d1++;
    for(int a=0;a<v[x].size();a++){
        dfs(v[x][a]);
    }

    if(v[x].size() == 3){
        p[x] = 1;
        d31 = find_loop(v[x][0]);
        d32 = find_loop(v[x][1]);
        d33 = find_loop(v[x][2]);
    }
}

int main(){
int a, b, c, d;
cin >> N >> M;
REP(a, M){
    scanf("%d %d", &c, &d);
    v[c].pb(d);
    v[d].pb(c);
}
REPI(a, N){
    dmx = 0;
    d1 = 0;
    n = 0;
    if(vs[a]) continue;
    dfs(a);
    if(n == 1){
        S.insert(ms(5, n, 0, 0));
    }
    else if(dmx != 3){
        if(d1)
            S.insert(ms(1, n, 0, 0));
        else
            S.insert(ms(3, n, 0, 0));
    }
    else {
        if(d1 == 1){
            S.insert(ms(4, d31, d32, d33));
        }
        else {
            S.insert(ms(2, d31, d32, d33));
        }
    }
}
set<star>::iterator it;
for(it=S.begin(); it!=S.end(); it++){
    printf("%d| %d %d %d\n",it->type, it->x, it->y, it->z);
}
cout << S.size();

return 0;
}
