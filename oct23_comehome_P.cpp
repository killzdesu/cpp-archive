/*
LANG: C++
*/
#include<stdio.h>
#include<set>
#include<list>
using namespace std;
int ci(char a) {
    if('a'<=a&&a<='z')return a-'a';
    else return a-'A'+26;
}
char ic(int a) {
    if(a<26)return a+'a';
    else return a+'A'-26;
}
list<pair<int,int> > link[52];
set<pair<int,int> > data;
int dis[52];
bool vis[52];
int main() {
    char a,b;
	int n,l,i,j;
	scanf("%d",&n);
//	REP(i, 52)dis[i] = 2e9;
	for(i=0;i<n;i++) {
	    scanf(" %c %c %d",&a,&b,&l);
	    link[ci(a)].push_back(make_pair(ci(b),l));
	    link[ci(b)].push_back(make_pair(ci(a),l));
	}
	data.insert(make_pair(dis[ci('Z')],ci('Z')));
	vis[ci('Z')]=true;
	dis[ci('Z')] = 0;
	while(!data.empty()) {
	    i=data.begin()->second;
	    if(data.begin()->first==dis[i]) {
            for(list<pair<int,int> >::iterator il=link[i].begin();il!=link[i].end();il++) {
                j=il->first;
                l=il->second;
                if((vis[j]==false)||(dis[i]+l<dis[j])) {
                    dis[j]=dis[i]+l;
                    vis[j]=true;
                    data.insert(make_pair(dis[j],j));
                }
            }
	    }
	    data.erase(data.begin());
	}
	l=2000000000;
	for(i=ci('A');i<51;i++)
        if(vis[i]&&dis[i]<l) {
            l=dis[i];
            a=ic(i);
        }
    printf("%c %d",a,l);
	return 0;
}
