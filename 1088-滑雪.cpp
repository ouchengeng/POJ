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
const int N = 105;
struct node
{
	int x, y;
	int height;
};
int value[N][N];
int dp[N][N];
node sorted[N * N];

bool cmp(node &a, node &b)
{
	return a.height < b.height;
};
int main()
{
	int row, col;
	int count = 0;
	scanf("%d %d", &row, &col);
	for(int i = 0; i < row; i++)
		for(int k,j = 0; j < col; j++)
		{
			scanf("%d", &k);
			value[i][j] = k;
			dp[i][j] = 1;
			sorted[count].x = i;
			sorted[count].y = j;
			sorted[count++].height = k;
		}
	sort(sorted, sorted + count, cmp);
	int ans = 0;
	for(int i = 0; i < count; i++)
	{
		//upper x - 1
		int x = sorted[i].x - 1, y = sorted[i].y;
		if(x >= 0 && value[x][y] < sorted[i].height)
			dp[sorted[i].x][sorted[i].y] = max(dp[sorted[i].x][sorted[i].y], dp[x][y]+1);
		//low
		x = sorted[i].x + 1, y = sorted[i].y;
		if(x < row && value[x][y] < sorted[i].height)
			dp[sorted[i].x][sorted[i].y] = max(dp[sorted[i].x][sorted[i].y], dp[x][y]+1);
		//left
		x = sorted[i].x, y = sorted[i].y - 1;
		if(y >= 0 && value[x][y] < sorted[i].height)
			dp[sorted[i].x][sorted[i].y] = max(dp[sorted[i].x][sorted[i].y], dp[x][y]+1);
		//right
		x = sorted[i].x, y = sorted[i].y + 1;
		if(y < col && value[x][y] < sorted[i].height)
			dp[sorted[i].x][sorted[i].y] = max(dp[sorted[i].x][sorted[i].y], dp[x][y]+1);
		
		ans = max(ans, dp[sorted[i].x][sorted[i].y]);
	}
	printf("%d\n", ans);
	return 0;
}