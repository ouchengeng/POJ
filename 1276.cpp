#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<string.h>
using namespace std;

const int N = 1010;
int dis[N];
int value[N];
int count[100010];
int dp[100010];

int main()
{
	int cash, n;
	while(scanf("%d %d", &cash, &n) != EOF)
	{
		for(int i = 1; i <= n; i++)
			scanf("%d%d", &dis[i], &value[i]);
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++)
		{
			//取第i个
			memset(count, 0, sizeof(count));
			for(int j = value[i]; j <= cash; j++)
			{
				if(count[j - value[i]] < dis[i] && dp[j - value[i]] + value[i] <= j && dp[j - value[i]] + value[i] > dp[j])
				{
					dp[j] = dp[j - value[i]] + value[i];
					count[j] = count[j - value[i]] + 1;
				}
				else if(dp[j - 1] > dp[j])
				{
					dp[j] = dp[j - 1];
					count[j] = count[j-1];
				}
			}
		}
		cout<<dp[cash]<<"\n";
	}
	return 0;
}
