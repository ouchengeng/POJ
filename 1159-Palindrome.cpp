#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
using namespace std;
const int N = 5100;

int dp[2][N];
int main()
{
	memset(dp, 0, sizeof(dp));
	int t;
	string s1, s2;
	cin>>t>>s1;
	s2 = s1;
	for(int i = 0; i < s1.length(); i++)
	{
		int pos = s1.length() - i - 1;
		s2[i] = s1[pos];
	}
	int len = s1.length();
	for(int i = 1; i <= len; i++)
	{
		int cur = i % 2;
		int last = (i + 1) % 2;
		for(int j = 1; j <= len; j++)
		{
			if(s1[i - 1] == s2[j - 1])
				dp[cur][j] = dp[last][j - 1] + 1;
			else
				dp[cur][j] = max(dp[cur][j - 1], dp[last][j]);
		}
	}
	cout<<len - dp[len % 2][len];
	return 0;
}