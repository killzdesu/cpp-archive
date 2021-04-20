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
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-sm-out.txt", "w", stdout);
int a, b, c, d;
int s1[100], s2[100];
int X, T;
cin >> X;
for(T=0;T<X;T++){
    cin >> c;
    m.clear();
    v.clear();
    for(a=1;a<=4;a++){
        for(b=0;b<4;b++){
            cin >> d;
            if(a == c) m[d] = 1;
        }
    }
    cin >> c;
    for(a=1;a<=4;a++){
        for(b=0;b<4;b++){
            cin >> d;
            if(a == c){
                if(m[d]== 1){
                    v.push_back(d);
                }
            }
        }
    }

    printf("Case #%d: ", T+1);
    if(v.size() == 0)printf("Volunteer cheated!");
    if(v.size() > 1)printf("Bad magician!");
    if(v.size() == 1)printf("%d", v[0]);

    printf("\n");
//    for(it=v.begin();it!=v.end();it++){
//        printf("%d ", *it);
//    }
//    printf("\n");
}


return 0;
}
