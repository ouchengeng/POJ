#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
using namespace std;

const int N = 400;
int a[N][N];
int dp[2][N];
int main()
{
	int n;
	memset(a, 0, sizeof(a));
	memset(dp, 0, sizeof(dp));
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			scanf("%d", &a[i][j]);
	for(int i = 1; i <= n; i++)
	{
		int cur = i % 2;
		int last = (i + 1) % 2;
		for(int j = 1; j <= i; j++)
			dp[cur][j] = max(dp[last][j - 1], dp[last][j]) + a[i][j];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(dp[n%2][i] > ans)
			ans = dp[n%2][i];
	printf("%d", ans);
	return 0;
}