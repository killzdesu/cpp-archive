#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define MAXM 44000010
#define MAXN 2000010
#define REP(_x,_y) for(_x=0;_x<_y;_x++)

using namespace std;

int i,n,k,N,M,K;
int MAX=44e6+10;
char t[44000010];
char p[44000010];
int gs[4000010];
int suff[4000010];
int fn[300][300];

int* prefix(char *p, int n)
{
    int k = -1;
    int i = 1;
    int *pi = (int*)malloc(sizeof(int)*n);
    if (!pi)
        return NULL;
    pi[0] = k;
    for (i = 1; i < n; i++)
    {
        while (k > -1 && p[k+1] != p[i])
            k = pi[k];
        if (p[i] == p[k+1])
            k++;
        pi[i] = k;
    }
    return pi;
}

int kmp(char *t, int m,char *p,int n)
{
    int i,cnt=0;
    int *pi = prefix(p,n);
    int k = -1;
    if (!pi)
        return -1;
    for (i = 0; i < m; i++)
    {
        while (k>-1 && p[k+1]!=t[i])
            k=pi[k];
        if (t[i]==p[k+1])
            k++;
        if (k==n-1)
        {
//			printf("@%d ",i-k);
            cnt++;
        }
    }
    return cnt;
}

int naive(char *t, int m,char *p,int n)
{
    int cnt=0;
    for(int s=0; s<=m-n; s++)
    {
        for(i=0; i<n; i++)
        {
            if(t[s+i]!=p[i])break;
        }
        if(i==n)
        {
//            printf("@%d ",s);
            cnt++;
        }
    }
    return cnt;
}

int rabin_karp(char *t, int m,char *p,int n,int d,int q)
{
    int ht,hp,dm;
    int i,cnt=0;
    ht=0;hp=0;
    dm=1;
    d=256;
    for(i=0; i<n-1; i++)
    {
        dm*=d;
    }
    for(i=0;i<n;i++)
    {
        hp=d*hp+p[i];
    }
    for(i=0;i<n-1;i++)
    {
        ht=d*ht+t[i];
    }
    for(int s=n-1; s<m; s++)
    {
        ht=d*ht+t[s];
        if(ht==hp)
        {
            for(i=0;i<n;i++)
            {
                if(t[s-n+1+i]!=p[i])break;
            }
            if(i>=n)
            {
//                printf("@%d ",s);
                cnt++;
            }
        }
        ht=ht-t[s-n+1]*dm;
    }
    return cnt;
}

int bm(char *t, int m,char *p,int n)
{
    int i,s,cnt=0,j;
    int bh[256]= {};
//    good(p,n,gs);
    for(i=0; i<n; i++)
    {
        bh[p[i]]=i;
    }
    s=0;
    while(s<m-n)
    {
        j=n-1;
        while(j>=0 and p[j]==t[s+j])j--;
        if(j==-1)
        {
//            printf("@%d ",s);
            cnt++;
            s++;
        }
        else
        {
            s+=max(j-bh[t[s+j]],1);
        }
    }
    return cnt;
}

int bmh(char *t, int m,char *p,int n)
{
    int i,s,cnt=0,j;
    int bh[256]= {};
//    good(p,n,gs);
    for(i=0; i<256; i++)bh[i]=n;
    for(i=n-1; i>=0; i--)
    {
        bh[p[i]]=n-i-1;
    }
    s=0;
    while(s<=n-m)
    {
        j=n-1;
        while(j>=0 and p[j]==t[s+j])j--;
        if(j==-1)
        {
//            printf("@%d ",s);
            cnt++;
            s++;
        }
        else
        {
            s+=max(n-bh[t[s+m]],1);
        }
    }
    return cnt;
}

void calhp(char *p, int n, int *bc)
{
    int i;
    for (i=0;i<256;i++)
        bc[i]=n;
    for (i=0;i<n-1;i++)
        bc[p[i]]=n-i-1;
}

void calbc(char *p, int n, int *bc)
{
    int i;
    for (i=0;i<256;i++)
        bc[i]=n;
    for (i=0;i<n;i++)
        bc[p[i]]=i;
}


void calgs1(char *p, int n)
{
    int f, g, i;
    suff[n-1]=n;
    g=n-1;
    for(i=n-2;i>=0;i--)
    {
        if (i>g and suff[i+(n-1)-f]<i-g)
            suff[i]=suff[i+(n-1)-f];
        else
        {
            if(i<g)
                g=i;
            f=i;
            while (g>=0 and p[g]==p[g+(n-1)-f])
                g--;
            suff[i]=f-g;
        }
    }
}

void calgs2(char *p, int n)
{
    int i,j;
    for(i=0;i<n;i++)gs[i]=n;
    j=0;
    for(i=n-1;i>=0;i--)
    {
        if(suff[i] == i+1)
        {
            for(;j<n-1-i;j++)
            {
                if(gs[j]==n)
                    gs[j]=n-1-i;
            }
        }
    }
    for (i=0;i<=n-2;i++)
        gs[n-1-suff[i]]=n-1-i;
}

int BM(char *t, int m, char *p, int n)
{
    int i, j, bc[256];
    int cnt=0;
    calgs1(p,n);
    calgs2(p,n);
    calbc(p,n,bc);

    j=0;
    while (j<=m-n)
    {
        for (i=n-1;i>=0&&p[i]==t[i + j];i--);
        if (i<0)
        {
//            printf("@%d ",j);
            cnt++;
            j+=gs[0];
        }
        else
            j+=max(gs[i],i-bc[t[i+j]]);
    }
    return cnt;
}

int BMH(char *t, int m, char *p, int n)
{
    int i, j, bc[256];
    int cnt=0;
    calgs1(p,n);
    calgs2(p,n);
    calhp(p,n,bc);

    j=0;
    while (j<=m-n)
    {
        for (i=n-1;i>=0&&p[i]==t[i + j];i--);
        if (i<0)
        {
//            printf("@%d ",j);
            cnt++;
            j+=gs[0];
        }
        else
            j+=max(gs[i],bc[t[i+j]]-n+1+i);
    }
    return cnt;
}

int finite(char *t, int m, char *p, int n)
{
	int a,b,c,d,cnt=0;
	for(a=0;a<=n;a++)
	{
		for(b=0;b<256;b++)
	    {
	    	c=min(n+1,a+2);
	        for(;c>0;c--)
	        {
	        	for(d=0;d<c-1;d++){
	            	if(p[d]!=p[a-c+1+d]) break;
	        	}
	         	if(d==c-1 and p[d]==b)break;
	        }
	     	fn[a][b]=c;
	    }
	}
	b=0;
	for(a=0;a<m;a++)
	{
		b=fn[b][t[a]];
		if(b==n) cnt++;
	}
	return cnt;
}

int batch(char* p)
{
    int i;
    clock_t start,ends;
    char ss[11];
    for(int a=0;a<10;a++)ss[a]=p[a];
    ss[10]='\0';
    k++;
    printf("Test #%02d    first 10 characters \'%s\'\n\n",k,ss);
    start = clock();
    i=kmp(t,strlen(t),p,strlen(p));
    ends = clock();
    printf("KMP\t\t\t:: ");
    cout << "found " << i;
    printf("\t");
    cout << " : in " << (double) (ends - start) / CLOCKS_PER_SEC << " s" << endl;
    start = clock();
    i=naive(t,strlen(t),p,strlen(p));
    ends = clock();
    printf("Brute Force\t\t:: ");
    cout << "found " << i;
    printf("\t");
    cout << " : in " << (double) (ends - start) / CLOCKS_PER_SEC << " s" << endl;

    start = clock();
    i=rabin_karp(t,strlen(t),p,strlen(p),256,2173913);
    ends = clock();
    printf("Rabin-Karp\t\t:: ");
    cout << "found " << i;
    printf("\t");
    cout << " : in " << (double) (ends - start) / CLOCKS_PER_SEC << " s" << endl;

    start = clock();
//    bm(t,strlen(t),p,strlen(p));
    i=BM(t,strlen(t),p,strlen(p));
    ends = clock();
    printf("Boyer-Moore\t\t:: ");
    cout << "found " << i;
    printf("\t");
    cout << " : in " << (double) (ends - start) / CLOCKS_PER_SEC << " s" << endl;

    start = clock();
    i=BMH(t,strlen(t),p,strlen(p));
    ends = clock();
    printf("Boyer-Moore+Horspool\t:: ");
    cout << "found " << i;
    printf("\t");
    cout << " : in " << (double) (ends - start) / CLOCKS_PER_SEC << " s" << endl;

    if(k<=5){
        start = clock();
        i=finite(t,strlen(t),p,strlen(p));
        ends = clock();
        printf("Finite Automaton\t:: ");
        cout << "found " << i;
        printf("\t");
        cout << " : in " << (double) (ends - start) / CLOCKS_PER_SEC << " s" << endl;
    }

    printf("-----------------------------------------------------------------------\n");
}

int main()
{
    int a,b,c,d,i;
    FILE *fp;
    fp=fopen("big_edited.txt","r"); // <<--------- Your text here..
    fgets(t,MAXM,fp);
    fclose(fp);

// If you want to batch input from file
//*
fp=fopen("test_texts.txt","r");
while(!feof(fp))
{
    fgets(p,MAXN,fp);
    p[strlen(p)-1]='\0';
    batch(p);
}
fclose(fp);
//*/

    return 0;
}
