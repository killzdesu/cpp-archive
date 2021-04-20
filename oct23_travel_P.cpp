/*
LANG: C++
*/
#include<stdio.h>
#include<list>
#include<queue>
using namespace std;
list<int>link[30000];
queue<int>q,tmp;
int chk[30000];
int bfs(int a,int b,int k) {
    if(a==b)return 0;
    int i,t=1;
    chk[a]=k;
    while(!tmp.empty())tmp.pop();
    while(!q.empty())q.pop();
    q.push(a);
    while(1) {
        while(!q.empty()) {
            i=q.front();
            for(list<int>::iterator il=link[i].begin();il!=link[i].end();il++) {
                if(*il==b)return t;
                if(chk[*il]!=k) {
                    chk[*il]=k;
                    tmp.push(*il);
                }
            }
            q.pop();
        }
        while(!tmp.empty()) {
            q.push(tmp.front());
            tmp.pop();
        }
        t++;
    }
}
int main() {
	int n,m,i,a,b,ans=0;
	scanf("%d",&n);
	for(i=1;i<n;i++) {
        scanf("%d %d",&a,&b);
        link[a-1].push_back(b-1);
        link[b-1].push_back(a-1);
	}
	scanf("%d",&m);
	a=0;
	for(i=1;i<=m;i++) {
	    scanf("%d",&b);
	    b--;
	    ans+=bfs(a,b,i);
	    a=b;
	}
	printf("%d",ans);
	return 0;
}
