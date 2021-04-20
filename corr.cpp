#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin, unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define dump(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;

int i, n, k, N, M, K;

deque<char> s1, s2;
char s[100010];

int main()
{
    int n,i,res = 0;

    scanf("%d", &n);
    scanf("%s", s);

    REP(i, n) s1.pb(s[i]);

    scanf("%s", s);

    REP(i, n) s2.pb(s[i]);

    while(s1.front() == s2.front()){
        s1.pop_front(), s2.pop_front();
    }

    while(s1.back() == s2.back()){
        s1.pop_back(), s2.pop_back();
    }

    s1.push_front(s2.front());
    s2.push_back(s1.back());

    res += (s1==s2);

    s1.pop_front();
    s2.pop_back();

    s1.push_back(s2.back());
    s2.push_front(s1.front());

    res += (s1==s2);

    printf("%d",res);
}
