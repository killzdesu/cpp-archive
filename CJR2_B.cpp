#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<map>
#include<math.h>
#include<set>
#include<string>
#include<vector>
#define LSOne(S) (S & (-S))

using namespace std;

int N, M, K, i, k;
int s[1005], st[1005];
int t[1005];
int mn;

class BIT {



public:

        // initialize a BIT of n elements to zero
        int* ft, size;
        BIT(int n) {
                size = n;
                ft = new int[n+1];
        }

        ~BIT()  {
                delete [] ft;
        }

        // returns sum of the range [1...b]
        int sum(int b) {
                int sum = 0;
                for (; b; b -= LSOne(b)) sum += ft[b];
                return sum;
        }

        // returns sum of the range [a...b]
        int sum(int a, int b) {
                return sum(b) - (a == 1 ? 0 : sum(a - 1));
        }

        // update value of the k-th element by v (v can be +ve/inc or -ve/dec)
        // i.e., increment or decrement kth element by a value v
        void update(int k, int v) {
                for (; k <= size; k += LSOne(k)) ft[k] += v;
        }

    // divide each original frequency by c
        void scaleDown(int c){
        for (int i=1 ; i<=size ; i++) ft[i] /= c;
    }

    // multiply each original frequency by c
    void scaleUp(int c){
        for (int i=1 ; i<=size ; i++) ft[i] *= c;
    }
};


bool cmps(int a, int b){
    return s[a] < s[b];
}

bool in_cmps(int a, int b){
    return s[b] < s[a];
}
BIT B(1005);
int main(){
freopen("B-small-attempt1 (1).in", "r", stdin);
freopen("B_out-.txt", "w", stdout);
int a, b, c, d;
int R, T;
cin >> R;
T = R;
int mx, mxa;
while(T--){
    scanf("%d", &N);
    mx = -1111111;
    for(a=0;a<N;a++){
        scanf("%d", &st[a]);
        if(st[a] > mx){
            mx = st[a];
            mxa = a;
        }
    }
    mn = 2e9;
    for(d=0;d<N;d++){
        for(a=0;a<N+10;a++){
            B.ft[a] = 0;
        }
        c = 0;
        b = 0;
        i = 0;
        for(a=0;a<N;a++)t[a] = a;
        for(a=0;a<d;a++){
            if(i == mxa){ i++;}
            s[a] = st[i++];
        }
        s[a] = mx;
        for(a=d+1;a<N;a++){
            if(i == mxa){ i++;}
            s[a] = st[i++];
        }
        c += (int)fabs(mxa-d);

//        for(a=0;a<N;a++){
//            printf("%d ", s[a]);
//        }printf(" <<\n");

        sort(t, t+d, cmps);
        sort(t+d+1, t+N, in_cmps);
        for(a=0;a<N;a++){
            if(t[a] == d) continue;
            s[t[a]] = a+1;
        }
        s[d] = d+1;
//        for(a=0;a<N;a++)printf("%d ",s[a]);
//        printf(" :\n");
        for(a=d-1;a>=0;a--){
            c += B.sum(1, s[a]);
//            printf("%d <\n", B.sum(1, s[a]));
            B.update(s[a], 1);
//            printf("%d %d %d<\n", t[a], a, s[a]);
        }
        for(a=N-1;a>d;a--){
            c += B.sum(d+1, s[a]);
//            printf("%d %dX\n", B.sum(d+2, s[a]), s[a]);
            B.update(s[a], 1);
//            printf("%d %d %d<\n", t[a], a, s[a]);
        }
//        printf("--\n");
//        printf("%d\n", c);
        mn = min(c, mn);

    }
    printf("Case #%d: %d\n", R-T, mn);
}

return 0;
}
