//#include "stdafx.h"
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int a[1001];
int dp[1001];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int len = 1;
	dp[1] = a[1];
	for(int i = 2; i <= n; i++)
	{
		if(a[i] > dp[len])
			dp[++len] = a[i];
		else
		{
			int pos = lower_bound(dp, dp + len, a[i]) - dp;
			dp[pos] = a[i];
		}
	}
	printf("%d\n", len);
	return 0;
}

