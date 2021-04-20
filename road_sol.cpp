#include<cstdio>
#include<cstdlib>
const int fin=0;
int N,M,K,rest;
int p[20010],use[100010];
struct rec {
    int x,y,w;
} a[100010];

int getf(int x) {
//    return p[x]=(p[x]!=x&&p[p[x]]!=p[x])?getf(p[x]):p[x];
    if(p[x] != x) p[x] = getf(p[x]);
    return p[x];
}
void merge(int x,int y) {
    int px=getf(x),py=getf(y);
    if(px!=py) {
        p[py]=px;
        --rest;
    }
}

int main() {
    int i,cnt=0;
    scanf("%d%d%d",&N,&M,&K);
    for(i=1; i<=M; ++i)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
    for(i=1; i<=M; ++i)if(a[i].w==0)++cnt;
    if(cnt<K) {
        puts("no solution");
        return 0;
    }
    for(i=1; i<=N; ++i)p[i]=i;
    rest=N;
    cnt=0;
    for(i=1; i<=M; ++i){
        if(a[i].w==1){
            merge(a[i].x,a[i].y);
        }
    }
    for(i=1; i<=M; ++i)
        if(a[i].w==0)
            if(getf(a[i].x)!=getf(a[i].y)) {
                merge(a[i].x,a[i].y);
                cnt+=(use[i]=1);
            }
    if(cnt>K) {
        puts("no solution");
        return 0;
    }
    for(i=1; i<=N; ++i)p[i]=i;
    for(i=1; i<=M; ++i)if(use[i])merge(a[i].x,a[i].y);
    if(cnt<K)
        for(i=1; i<=M; ++i)
            if(a[i].w==0 and getf(a[i].x)!=getf(a[i].y)) {
                merge(a[i].x,a[i].y);
                if((cnt+=(use[i]=1))==K)break;
            }
    if(cnt!=K) {
        puts("no solution");
        return 0;
    }
    for(i=1; i<=M; ++i)
        if(a[i].w==1&&getf(a[i].x)!=getf(a[i].y)) {
            merge(a[i].x,a[i].y);
            if((cnt+=(use[i]=1))==N-1)break;
        }
    for(i=1; i<=M; ++i)if(use[i])
            printf("%d %d %d\n",a[i].x,a[i].y,a[i].w);
    return 0;
}
