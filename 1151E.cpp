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

int s[100010];

ll getInvCount(int n) 
{ 
    set<int> set1; 
    set1.insert(s[0]); 
    ll invcount = 0; 
    set<int>::iterator itset1; // Iterator for the set 
    for (int i=1; i<n; i++) 
    { 
        set1.insert(s[i]); 
        itset1 = set1.upper_bound(s[i]); 
        invcount += distance(itset1, set1.end()); 
    } 
    return invcount; 
} 

long long mergeSortAndCountInversions(int* arr, int size)
{
  int m;

	if (size <= 1)
		return 0;

	m = size / 2;

	long long invCountA = 0, invCountB = 0, invCountC = 0;
	invCountA = mergeSortAndCountInversions(arr, m);
	invCountB = mergeSortAndCountInversions(arr + m, size - m);

	int* arrPartA = new int[m];
	int* arrPartB = new int[size - m];

	memcpy(arrPartA, arr, sizeof(int) * m);
	memcpy(arrPartB, arr + m, sizeof(int) * (size - m));

	int i = 0, j = 0, k = 0;

	while (k < size)
	{
		if (arrPartA[i] <= arrPartB[j])
		{
			arr[k] = arrPartA[i];
			i++;
			/* invCountC += j; */
		}
		else
		{
			arr[k] = arrPartB[j];
			j++;
			invCountC += m-i;
		}
		k++;
		if (i >= m || j >= (size - m))
			break;
	}
	/* invCountC -= j; */
	while (i < m)
	{
		arr[k] = arrPartA[i];
		k++;
		i++;
    /* invCountC ++; */
		/* invCountC += j; */
	}
	while (j < (size - m))
	{
		arr[k] = arrPartB[j];
		k++;
		j++;
	}

	delete []arrPartA;
	delete []arrPartB;

	return (invCountA + invCountB + invCountC);
}

int i, N, M;
bool chk[100010];

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
	int a, b, c, d;
	int T;
  cin >> N;
  rep(a, 0, N) cin >> s[a], chk[s[a]] = 1;
  ll sm = getInvCount(N), s2 = 0;
  dump(sm);
  ll t = mergeSortAndCountInversions(s, N);
  dump(t);
  i = 1;
  rep(a, 1, N+1) if(chk[a] == 1) s2 += N-a+1, i++;
  dump(s2);

	return 0;
}
