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
#define foreach(it,x) for(typeof(x.begin())it=x.begin();it!=x.end();it++)
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;

int i, n, k, N, M;
const int K = 3;
const int MAXN = 1 << K;
const double PI = acos(-1.0);

struct FFT{
    int a, b, N;
    vector<base> A;
    FFT(){
        N = MAXN;
        A = vector<base>(MAXN, base(0.0));
    }
    FFT operator + (FFT B) {
        FFT res;
        for(int i=0; i < N; i++){
            res.A[i] = A[i] + B.A[i];
        }
        return res;
    }
    FFT operator * (FFT B) {
        FFT res;
        for(int i=0; i < N; i++){
            res.A[i] = A[i] * B.A[i];
        }
        return res;
    }

    int rev(int x) {
        int res = 0;
        for (int i = 0; i < K; i++) {
            res |= (((x >> (K - i - 1)) & 1) << i);
        }
        return res;
    }

    FFT(vector<int> s){
        N = MAXN;
        A = vector<base>(N, base(0.0));
        REP(a, s.size()){
            A[a] = s[a];
        }
//        return;
        (*this).fft(1);
    }

    void fft(int inv){
        REP(a, N){
            if(rev(a) > a) swap(A[rev(a)], A[a]);
        }
        for(int len=1; len < N; len*=2){
            double fi = inv*PI/(double)len;
            base w1(cos(fi), sin(fi));
            for(a=0;a<N;a+=2*len){
                base w(1.0);
                for(b=a;b<a+len;b++){
                    base v = A[b];
                    base u = A[b+len]*w;
                    A[b] = v+u;
                    A[b+len] = v-u;
                    w *= w1;
                }
            }
        }
        if(inv == -1){
            REP(a, N){
                A[a] /= N;
            }
        }
    }

};

int main(){
int a, b, c, d;
int s[100];
FFT t;
vector<int> X1 = {1, 1, 1};
vector<int> X2 = {1, 1};
FFT x1(X1);
FFT x2(X2);
x1 = x1 * x2;
x1.fft(-1);
REP(a, MAXN) s[a] = a;
REP(a, MAXN) if(t.rev(a) > a) swap(s[t.rev(a)], s[a]);
REP(a, MAXN) printf("%d ", s[a]); EL;
REP(a, MAXN){
    printf("%d ", (int)(x1.A[a].real()+0.5));
}

return 0;
}
