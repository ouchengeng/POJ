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

const int N = 30010;
int n, m;
int p[N];
int r[N];
int find(int x)
{
	if(p[x] == x)
		return x;
	p[x] = find(p[x]);
	return p[x];
}
void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x == y)
		return;
	if(r[x] >= r[y])
	{
		p[y] = x;
		r[x] += r[y];
	}
	else
	{
		p[x] = y;
		r[y] += r[x];
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	while(n != 0 || m != 0)
	{
		for(int i = 0; i < n; i++)
		{
			p[i] = i;
			r[i] = 1;
		}
		int first, second, nums, x, y;
		for(int j = 0; j < m; j++)
		{
			scanf("%d %d", &nums, &first);
			for(int i = 1; i < nums; i++)
			{
				scanf("%d", &second);
				merge(first, second);
			}
		}
		printf("%d\n", r[find(0)]);
		scanf("%d %d", &n, &m);
	}
	return 0;
}