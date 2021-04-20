#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std ;
const int MAXN = 300 + 10 ;

vector<int> sol;
struct xxx{
    int v[10] ;
    int sz ;
    int in ;

    bool operator <(const xxx &o)const{
        return sz < o.sz ;
    }
}e[MAXN];
bool vis[MAXN] ;
int n ;
int main(){

    scanf("%d",&n);

    for(int i = 1 ; i <= n ; i ++){
        int m ;
        scanf("%d",&m);
        for(int j = 1 ; j <= MAXN ; j ++)vis[j] = false ;
        e[i].sz = 0;
        e[i].in = i ;
        for(int j = 1 ; j <= m ; j ++){
            int x;
            scanf("%d",&x);
            vis[x] = true ;
        }

        for(int j = 1 ; j <= n; j ++) if(not vis[j]) {
            e[i].v[ e[i].sz++ ] = j;
        }
    }

    for(int i = 1 ; i <= MAXN ; i ++)vis[i] = false ;

    sort(e +1 , e +1 + n);

    for(int i = 1 ; i <= n; i ++ ){

        for(int j = 0 ; j < sol.size(); j ++){
            for(int k = 0 ; k < e[i].sz ;k ++){

                if(e[i].v[k] == sol[j]){
                    goto benz ;
                }
            }
        }
        sol.push_back(e[i].in);
        benz:;
    }
    printf("%d\n",sol.size());
    for(int i = 0 ; i < sol.size() ;i ++)
        printf("%d\n",sol[i]);
}
