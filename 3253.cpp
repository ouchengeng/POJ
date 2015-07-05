//#include "stdafx.h"
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int a[1001];
int main()
{
	priority_queue<long long, vector<long long>, greater<long long>> q;
	int n;
	scanf("%d", &n);
	long long j;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &j);
		q.push(j);
	}
	if(n == 1)
	{
		printf("0\n");
		return 0;
	}
	long long ans = 0;
	while(q.size() != 0)
	{
		int a = q.top(); q.pop();
		int b = q.top(); q.pop();
		a += b;
		ans += a;
		if(q.empty())
			break;
		q.push(a);
	}
	printf("%lld\n", ans);
	return 0;
}

