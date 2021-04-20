#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> v1, v2, v;
vector<int>::iterator it;
map<int, int> m;

int main(){
    freopen("B-large.in", "r", stdin);
    //freopen("B-lg-out.txt", "w", stdout);
int a, b, c, d;
double C, F, X, t, R;
int W, T;
cin >> W;
for(T=1;T<=W;T++){
    cin >> C >> F >> X;
    R = 2;
    t = 0;
    while(1){
        t += C/R;
        if( (X-C)/R <= X/(R+F) ) break;
        else R+=F;
    }
    t += (X-C)/R;
    printf("Case #%d: %.8lf\n", T, t);
}


return 0;
}
