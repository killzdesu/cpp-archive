#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int oszto[] = {1,5,10,25,50};
int tabla[5][7500], i, j, k;

int  ermevaltas(int n)
{
    for(i = 0; i < n + 1; i++)
        tabla[0][i] = 1;
    for(i = 0; i < 5; i++)
        tabla[1][i] = tabla[2][i] = tabla[3][i] = tabla[4][i] = 1;
    for(i = 1; i < 5; i++)
    {
        for(j = 5; j < n + 1; j++)
        {
            for(k = 0; k <= i; k++)
            {
                if(j >= oszto[k])
                {
                    tabla[i][j] += tabla[k][j - oszto[k]];
                }
            }
        }
    }
}

 int main()
{
    ermevaltas(7489);
    while(scanf("%d",&j) == 1)
    {
        printf("%d\n",tabla[4][j]);
    }
    return 0;
}
