#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<utility>
using namespace std;

const int N = 1501;
int main()
{
	int a[N];
	a[1] = 1;
	int d1 = 1, d2 = 1, d3 = 1;
	for(int i = 2; i < 1501; i++)
	{
		a[i] = min(a[d1]*2, min(a[d2]*3, a[d3]*5));
		if(a[i] == a[d1]*2) d1++;
		if(a[i] == a[d2]*3) d2++;
		if(a[i] == a[d3]*5) d3++;
	}
	int n;
	scanf("%d", &n);
	while(n != 0)
	{
		printf("%d\n", a[n]);
		scanf("%d", &n);
	}
	return 0;
}