#include<iostream>
using namespace std;

int s[5];

int main()
{
    int sx,sy,tx,ty,t,chk;
    char c;
    cin >> t >> sx >> sy >> tx >> ty ;
    if(tx>=sx)
    {
        s[2]=tx-sx;
    }
    else
    {
        s[4]=sx-tx;
    }
    if(ty>=sy)
    {
        s[1]=ty-sy;
    }
    else
    {
        s[3]=sy-ty;
    }
    for(int i=0; i<t; i++)
    {
        cin >> c;
        chk=0;
        if(s[1]!=0 and c=='N')
        {
            s[1]--;
            chk=1;
        }
        if(s[2]!=0 and c=='E')
        {
            s[2]--;
            chk=1;
        }
        if(s[3]!=0 and c=='S')
        {
            chk=1;
            s[3]--;
        }
        if(s[4]!=0 and c=='W')
        {
            s[4]--;
            chk=1;
        }
        if(!s[1] and !s[2] and !s[3] and !s[4])
        {
            cout << i+1 ;
            return 0;
        }
    }
    cout << "-1" ;
}
