#include<bits/stdc++.h>
#define REP(x,y) for(x=0;x<(int)y;x++)
#define REPI(x,y) for(x=1;x<=(int)y;x++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

int i, N, M, K;
string users[105];
string mes[105];
vector<int> send[105];
bool chk;

bool isPerson(string x, int num){
    if(x.length() == 0) return false;
    chk = false;
    for(int a=0;a<N;a++){
        if(users[a] == x){
            send[num].pb(a);
            chk = true;
        }
    }
    return chk;
}

int main(){
int a, b, c, d;
int T, last;
string tmp;
cin >> T;
while(T--){
    cin >> N;
    REP(a, N) cin >> users[a];
    scanf("%d ", &M);
    REP(a, M){
        getline(cin, mes[a]);
        last = -1;
        for(b=0;b<mes[a].length();b++){
            if(mes[a][b]=='?' or mes[a][b]=='.' or mes[a][b]==' ' or mes[a][b]==',' or mes[a][b]=='!'){
                tmp = mes[a].substr(last+1, b-last-1);
                printf("%s ## is %d\n", tmp.c_str(), isPerson(tmp, b));
                last = b;
            }
        }
        tmp = mes[a].substr(last+1, b-last);
        printf("%s is %d\n", tmp.c_str(), isPerson(tmp, b));
    }
}

return 0;
}
