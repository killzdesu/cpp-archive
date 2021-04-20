#include "bits/stdc++.h"
#define rep(i, x,y) for(i=(int)x;i<(int)y;i++)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define len(x) (int)(x).size()
#define pb push_back
#define dump(x) cout <<(#x) << " = " << x << "\n";
#define dump_all(s) cout<<(#s)<<":\n";for(auto x:s)cout<<x<<" ";cout<<"\n";

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

struct TimeCard{
  int toInt(string t){
    int r = 0;
    r  = t[0]-'0';
    r*=10;
    r += t[1]-'0';
    r*=60;
    r+= t[3]-'0';
    r*=10;
    r+= t[4]-'0';
    if(t[6] == 'p') r += 12*60;
    return r;
  }
  string leave(vector <string> time){
    int sum = 0, a;
    string ans;
    char q[10];
    for(a=0;a<len(time)-1;a+=2){
      int A = toInt(time[a]);
      int B = toInt(time[a+1]);
      if(B < A) B += 24*60;
      sum += B-A;
    }
    if(sum > 40*60){ ans = "ABOVE 40"; return ans; }
    if(sum < 20*60){ ans = "BELOW 40"; return ans; }
    sum = 40*60-sum;
    int t = toInt(time[len(time)-1]);
    t += sum;
    if( t > 24*60 ) t-= 24*60;
    q[2] = ':'; q[5] = ','; q[6] = 'a'; q[7] = 'm'; q[8] = '\0';
    if(t > 12*60){ t-= 12*60; q[6] = 'p';}

    q[4] = (t%60)%10+'0';
    q[3] = ((t%60)/10)%10+'0';
    t /= 60;
    q[1] = t%10+'0';
    t/=10;
    q[0] = t + '0';;
    ans = q;
    return ans;
  }
};

int i, N, M;

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;



	return 0;
}
