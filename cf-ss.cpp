#include<stdio.h>
int dp[30][30],d[30],nle;
char str1[200100],str2[200100];
main()
{
    int cnt,i,j,k;
    scanf("%d",&nle);
    scanf("%s",str1);
    scanf("%s",str2);
    for(i=0;i<30;i++)
        d[i]=-1;
    for(i=0;i<30;i++)
        for(j=0;j<30;j++)
            dp[i][j]=-1;
    cnt=0;
    for(i=0;i<nle;i++)
    {
        if(str1[i]!=str2[i])
        {
            cnt++;
            d[str1[i]-'a']=i+1;
            dp[str1[i]-'a'][str2[i]-'a']=i+1;
        }
    }
    for(i=0;i<30;i++)
    {
        for(j=0;j<30;j++)
        {
            if(dp[i][j]!=-1&&dp[j][i]!=-1)
                break;
        }
        if(j<30)
            break;
    }
    if(i<30&&j<30)
    {
        printf("%d\n%d %d",cnt-2,dp[i][j],dp[j][i]);
    }
    else
    {
        for(i=0;i<30;i++)
        {
            for(j=0;j<30;j++)
            {
                if(dp[i][j]!=-1&&d[j]!=-1)
                    break;
            }
            if(j<30)
                break;
        }
        if(i<30&&j<30)
            printf("%d\n%d %d",cnt-1,dp[i][j],d[j]);
        else
            printf("%d\n-1 -1",cnt);
    }
    return 0;
}
