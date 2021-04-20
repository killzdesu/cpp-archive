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
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;

int i, n, k, N, M, K;

const ll P109 = 1e9+9;

ll P[1000100];

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

ll power(ll x, ll y, ll mod){
    return P[y];
}

ll pow2er(ll x, ll y, ll mod){
    if(y < 2) return (y==0?1:x);
    if(y % 2 == 0){
        ll T=power(x, y/2, mod);
        return (T*T)%mod;
    }
    else {
        return (x*power(x, y-1, mod))%mod;
    }
}

char s[1000100];
ll ha[1000100];

ll gethash(int lo, int hi){  // get hash from s[lo...hi]
    if(lo == 0) return ha[hi];
    return (ha[hi]- (ha[lo - 1] * power(257LL, hi-lo+1, P109))%P109 + P109*2)%P109;
}

int main(){
int a, b, c, d;
cin >> s;
N = strlen(s);
P[0] = 1;
REPI(a, N) P[a] = (P[a-1]*257)%P109;
ha[0] = (s[0]-'a');
REPI(a, N-1){
    ha[a] = ha[a-1]*257LL+(ll)(s[a]-'a');
    ha[a] %= P109;
}
vector<int> p;
REP(a, N){
    if((gethash(0, a)) == gethash(N-a-1, N-1)) p.pb(a);
}
//REP(a, p.size()){
//    cout << p[a] << " ";
//}EL;
int lo = 0, hi = p.size()-1, mi;
while(lo < hi){
    mi = lo+(hi-lo+1)/2;
    int len = p[mi];
    ll F = gethash(0, len);
    for(a=1; a+len < N-1; a++){
        if(gethash(a, a+len) == F){
            break;
        }
    }
    if(a+len < N-1) lo = mi;
    else hi = mi-1;
}
int len = p[lo];
ll F = gethash(0, len);
for(a=1; a+len < N-1; a++){
    if(gethash(a, a+len) == F){
        break;
    }
}
if(a+len < N-1) REP(a, p[lo]+1) printf("%c", s[a]);
else cout << "Just a legend";
return 0;
}
