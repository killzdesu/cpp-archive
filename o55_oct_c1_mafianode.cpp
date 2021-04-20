#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#include<queue>
#include<set>
#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define pb push_back
#define mp make_pair

using namespace std;

vector<int> tp;
set<int> S;
set<int>::iterator it;
priority_queue<pair<int, int> > Q;
int i, n, k, N, M, K;
char s[10];
int sc[1000500];

void update(){
    for(it = S.begin(); it != S.end(); it++){
        Q.push(mp(sc[*it], *it));
    }
    S.clear();
//    REP(i, tp.size()){
//        Q.push(mp(sc[tp[i]], tp[i]));
//    }
//    tp.clear();
}

void clr(){
    while(!Q.empty() and Q.top().fi != sc[Q.top().se]) Q.pop();
}

int main(){
int a, b, c, d;
cin >> N >> M >> i;
M += i;
REPI(a, N){
    Q.push(mp(0, a));
}
for(a=0;a<M;a++){
    scanf("%s", s);
    if(s[0] == 'L'){
        scanf("%d %d", &c, &d);
        sc[d]++;
        S.insert(d);
//        tp.pb(d);
        //Q.push(mp(sc[d], d));
    }
    if(s[0] == 'C'){
        scanf("%d %d", &c, &d);
        sc[d]+=3;
        S.insert(d);
//        tp.pb(d);
        //Q.push(mp(sc[d], d));
    }
    if(s[0] == 'R'){
        update();
        clr();
        printf("%d\n", Q.top().se);
    }
    if(s[0] == 'D'){
        update();
        clr();
        if(Q.empty())continue;
        sc[Q.top().se] = -1;
        Q.pop();
    }
}


return 0;
}
//#include<cstdio>
//#include<cstdlib>
//#include<cstring>
//#include<string>
//#include<map>
//#include<algorithm>
//#include<vector>
//#include<iostream>
//#include<cmath>
//#include<queue>
//#include<set>
//#define fi first
//#define se second
//#define REP(_x, _y) for(_x=0;_x<_y;_x++)
//#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
//#define pb push_back
//#define mp make_pair
//
//using namespace std;
//
//set<int> S;
//set<int>::iterator it;
//priority_queue<pair<int, int> > Q;
//int i, n, k, N, M, K;
//char s[10];
//int sc[1000010];
//
//void update(){
//    for(it = S.begin(); it != S.end(); it++){
//        Q.push(mp(sc[*it], *it));
//    }
//    S.clear();
//}
//
//void clr(){
//    while(!Q.empty() and Q.top().fi != sc[Q.top().se]) Q.pop();
//}
//
//int main(){
//int a, b, c, d;
//cin >> N >> M >> i;
//M += i;
//for(a=0;a<M;a++){
//    scanf("%s", s);
//    if(s[0] == 'L'){
//        scanf("%d %d", &c, &d);
//        sc[d]++;
//        S.insert(d);
//    }
//    if(s[0] == 'C'){
//        scanf("%d %d", &c, &d);
//        sc[d]+=3;
//        S.insert(d);
//    }
//    if(s[0] == 'R'){
//        update();
//        printf("%d\n", Q.top().se);
//        clr();
//    }
//    if(s[0] == 'D'){
//        update();
//        clr();
//        sc[Q.top().fi] = -1;
//        Q.pop();
//        clr();
//    }
//}
//
//
//return 0;
//}
//
