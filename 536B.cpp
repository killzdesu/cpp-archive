#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin, unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define P109 1000000009LL
#define P107 1000000007LL
#define EL printf("\n");
#include<bits/stdc++.h>
#define IT iterator
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;

int N, M;

char P[1000010];
int val[1000010];
ll h[1000010];
int Q[1000010];

ll pow(ll a, ll b, ll M)
{
    if(b < 2){
        return(b==0?1:a);
    }

    if(b % 2 == 0)
    {
        ll T = pow(a,b/2,M);
        return (T * T) % M;
    } else {
        return (pow(a,b-1,M)*a) % M;
    }
}

int main()
{
    int i,j,l;
    long long h1,h2;

    cin >> N >> M;
    cin >> P;

    l = strlen(P);

    REP(i, M)
    {
        scanf("%d", &val[i]);
        Q[val[i]]++;
        Q[val[i] + l]--;
    }

    h[0] = (ll)(P[0] - 'a');

    REPI(i, l-1){
        h[i] = ((ll)(P[i] - 'a') + h[i - 1] * 257LL) % 1000000009LL;
    }

    REPI(i, M-1)
    {
        if(val[i]-val[i - 1] < l)
        {
            h1 = h[l-1];
            h2 = h[l-(val[i]-val[i-1])-1];

            for(j=0;j<val[i]-val[i-1];j++)
            {
                h1 += 1000000009LL-(((pow(257LL,(ll)(l-j-1),1000000009LL))*(ll)(P[j]-'a'))%1000000009LL);
                h1 %= 1000000009LL;
            }

            if(!(h1 == h2))
            {
                printf("0\n");
                return 0;
            }
        }
    }

    for(i=2;i<=N;i++)
    {
        Q[i] += Q[i-1];
    }
    j = 0;

    REPI(i, N)
    {
        if(Q[i] == 0)
        {
            j++;
        }
    }

    cout << pow((ll)26,(ll)j,P107);
}
