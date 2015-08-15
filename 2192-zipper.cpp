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

const int N = 210;
bool dp[N][N];
int main()
{
	int t;
	cin>>t;
	string s1, s2, s3;
	for(int i = 1; i <= t; i++)
	{
		cin>>s1>>s2>>s3;
		if(s1.length() + s2.length() != s3.length())
		{
			cout<<"Data set "<<i<<": "<<"no\n";
			continue;
		}
		memset(dp, false, sizeof(dp));
		dp[0][0] = true;
		if(s1[0] == s3[0])
			dp[1][0] = true;
		if(s2[0] == s3[0])
			dp[0][1] = true;
		for(int i = 0; i <= s1.length(); i++)
			for(int j = 0; j <= s2.length(); j++)
			{
				//dp[i][j]
				if(i >= 1 && s1[i-1] == s3[i+j-1])
					dp[i][j] = dp[i-1][j] || dp[i][j];
				if(j >= 1 && s2[j-1] == s3[i+j-1])
					dp[i][j] = dp[i][j-1] || dp[i][j];
			}
		cout<<"Data set "<<i<<": "<<(dp[s1.length()][s2.length()]?"yes\n":"no\n");
	}
	return 0;
}