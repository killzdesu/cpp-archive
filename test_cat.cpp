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

ll s[100010];
ll t[100010];
int Q[100010];

ll dp[2][100010];
ll qt[100010];


ll getv(int d, int a, int b){
    return dp[d][a]-a*t[b]+qt[a]+b*t[b]-qt[b];
}

double fx(int d, int a, int b){
    return
    ((double)dp[d][a]+qt[a]-dp[d][b]-qt[b])/
    ((double)(-b)-(-a)); // --> a-b
}

int main(){
int a, b, c, d;
cin >> N >> M >> K;
REPI(a, N-1) scanf("%I64d", s+a+1), s[a+1]+=s[a];
REPI(a, M){
    scanf("%d %d", &c, &d);
    t[a] = d-s[c];
}
sort(t+1, t+M+1);
REPI(a, M){
    qt[a] = t[a];
    qt[a] += qt[a-1];
}
int i, j;
int now = 1, prev = 0;
REP(a, M+1) dp[0][a] = 1999999999999999LL;
dp[0][0] = 0;
REP(i, K){
    REP(a, M+1) dp[now][a] = 1999999999999999LL;
    dp[now][0] = 0;
    int l = 0, r = 0;
    Q[0] = 0;
    for(a=1;a<=M;a++){
        while(l < r and fx(prev, Q[l+1], Q[l]) <= t[a]) l++;
//        while(l < r and dp[prev][Q[l+1]]+qt[Q[l+1]]-dp[prev][Q[l]]-qt[Q[l]] <= t[a]*(Q[l+1]-Q[l])) l++;
        dp[now][a] = dp[prev][Q[l]]+t[a]*(a-Q[l])-(qt[a]-qt[Q[l]]);
//        while(l < r and (dp[prev][Q[r]]+qt[Q[r]]-dp[prev][Q[r-1]]-qt[Q[r-1]])/(double)(Q[r]-Q[r-1]) >
//                        (dp[prev][a]+qt[a]-dp[prev][Q[r]]-qt[Q[r]])/(double)(a-Q[r]) ) r--;
        while(l < r and fx(prev, Q[r-1], a) <= fx(prev, Q[r-1], Q[r])) r--;
        Q[++r] = a;
    }
    swap(now, prev);

}
ll sum = dp[prev][M];
cout << sum;
return 0;
}

//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int n,m,p,x,h,t,now,last,d[100010],ti[100010],q[100010];
//long long f[100010][2],sum[100010];
//int main(){
//    scanf("%d%d%d",&n,&m,&p);
//    for(int i=2;i<=n;++i){
//        scanf("%d",&d[i]);
//        d[i]+=d[i-1];
//    }
//    for(int i=1;i<=m;++i){
//        scanf("%d%d",&x,&ti[i]);
//        ti[i]-=d[x];
//    }
//    sort(ti+1,ti+m+1);
//    for(int i=1;i<=m;i++)
//        sum[i]=sum[i-1]+ti[i];
//    memset(f,63,sizeof(f));
//    f[0][0]=0;
//    for(int e=1;e<=p;++e){
//        last=now;now^=1;
//        h=t=0;q[t]=0;
//        for(int i=1;i<=m;++i){
//            while(h<t&&f[q[h+1]][last]+sum[q[h+1]]-f[q[h]][last]-sum[q[h]]<=(long long)ti[i]*(q[h+1]-q[h]))++h;
//            f[i][now]=f[q[h]][last]+(long long)ti[i]*(i-q[h])-(sum[i]-sum[q[h]]);
//            while(h<t&&(f[q[t]][last]+sum[q[t]]-f[q[t-1]][last]-sum[q[t-1]])/(double)(q[t]-q[t-1]) > (f[i][last]+sum[i]-f[q[t]][last]-sum[q[t]])/(double)(i-q[t]) )--t;
//            q[++t]=i;
//        }
//    }
//    printf("%I64d\n",f[m][now]);
//    return 0;
//}
