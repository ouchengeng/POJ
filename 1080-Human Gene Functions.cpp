#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
using namespace std;

int score['T'+1]['T'+1];  //积分表
const int inf = -99;
const int N = 110;
int dp[N][N];
void initial(void)  //打表
{
	score['A']['A']=5;
	score['C']['C']=5;
	score['G']['G']=5;
	score['T']['T']=5;
	score['-']['-']=inf;
	score['A']['C']=score['C']['A']=-1;
	score['A']['G']=score['G']['A']=-2;
	score['A']['T']=score['T']['A']=-1;
	score['A']['-']=score['-']['A']=-3;
	score['C']['G']=score['G']['C']=-3;
	score['C']['T']=score['T']['C']=-2;
	score['C']['-']=score['-']['C']=-4;
	score['G']['T']=score['T']['G']=-2;
	score['G']['-']=score['-']['G']=-2;
	score['T']['-']=score['-']['T']=-1;
	return;
}
int main()
{
	initial();
	int t;
	cin>>t;
	for(int i = 0; i < t; i++)
	{
		int len1, len2;
		string s1, s2;
		cin>>len1>>s1;
		cin>>len2>>s2;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 0;
		dp[1][0] = score[s1[0]]['-'];
		dp[0][1] = score['-'][s2[0]];
		for(int i = 1; i <= s1.length(); i++)
			dp[i][0] = dp[i - 1][0] + score[s1[i - 1]]['-'];
		for(int i = 1; i <= s2.length(); i++)
			dp[0][i] = dp[0][i - 1] + score['-'][s2[i - 1]];
		for(int i = 1; i <= len1; i++)
		{
			for(int j = 1; j <= len2; j++)
			{
				int t1 = dp[i - 1][j] + score[s1[i - 1]]['-'];
				int t2 = dp[i][j - 1] + score['-'][s2[j - 1]];
				int t3 = dp[i - 1][j - 1] + score[s1[i-1]][s2[j-1]];
				dp[i][j] = max(max(t1,t2),t3);
			}
		}
		cout<<dp[len1][len2]<<"\n";

	}
	return 0;
}