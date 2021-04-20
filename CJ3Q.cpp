#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

int P;
set<double> K, N, bK;
set<double>::iterator it, is;

double kturn(double tell){
    double ret;
    set<double>::iterator it;
    it = K.lower_bound(tell);
    if(it == K.end()){
        it = K.begin();
    }
    ret = *it;
    K.erase(it);
    return ret;
}

void check(double Ken, double Naomi){
    if(Ken < Naomi) P++;
    return;
}

int main(){
    freopen("D-large.in", "r", stdin);
    freopen("D-lg-out-1.txt", "w", stdout);
int a, b, d;
double c;
int W, T, n;
cin >> W;
for(T=1;T<=W;T++){
    cin >> n;
    K.clear();
    bK.clear();
    N.clear();
    for(a=0;a<n;a++){
        scanf("%lf", &c);
        N.insert(c);
    }
    for(a=0;a<n;a++){
        scanf("%lf", &c);
        K.insert(c);
        bK.insert(c);
    }
    printf("Case #%d: ", T);
    //Normal
    P = 0;
//    is = N.end();
//    for(;is!=N.begin(); ){
//        is--;
//        check(kturn(*is), *is);
//        //printf("%lf \n", kturn(*is));
//    }

    for(is=N.begin();is!=N.end(); is++){
        check(kturn(*is), *is);
        //printf("%lf \n", kturn(*is));
    }
    d = P;

    // Optimal
    P = 0;
    K = bK;
    for(is = N.begin(); is != N.end(); is++){
        if(*is < *(K.begin())){
            it = K.end();
            it--;
            K.erase(it);
        }
        else {
            P++;
            K.erase(K.begin());
        }
    }


    printf("%d %d", P, d);
    printf("\n");
}


return 0;
}
