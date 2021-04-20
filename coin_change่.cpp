#include <cstdio>
#include <iostream>
using namespace std;
int i,j,z[5]={50,25,10,5,1},n=5;
int dp[100005][6];
int ch(int left,int chk)
{
    if(dp[left][chk]!=0) return dp[left][chk];
    int sum=0;
    int i;
    if(left==0) return dp[left][chk]=1;
    for(i=chk; i<n; i++)
    {
        if(left>=z[i]) sum+=ch(left-z[i],i);
    }
    return dp[left][chk]=sum;
}
int main()
{
    int left;
//    for(i=0; i<7489; i++)
//    {
//        ch(i,0);
//    }
    ch(7489, 0);
    while(scanf("%d",&left)) printf("%d\n",ch(left,0));
    return 0;
}
