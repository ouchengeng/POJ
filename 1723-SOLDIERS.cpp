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

const int N = 10010;
int x[N], y[N];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d %d", x + i, y + i);
	sort(x, x + n);
	sort(y, y + n);
	for(int i = 0; i < n; i++)
		x[i] -= i;
	sort(x, x + n);
	int ans = 0, mid = n / 2;
	for(int i = 0; i < n; i++)
		ans += abs(x[i] - x[mid]) + abs(y[i]-y[mid]);
	printf("%d\n", ans);
	return 0;
}