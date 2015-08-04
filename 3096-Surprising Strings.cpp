#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<fstream>
#include<queue>
#include<stack>
#include<deque>
using namespace std;

int main()
{
	const int n = 10000;
	bool vis[n];
	string s;
	cin>>s;
	while(s != "*")
	{
		if(s.length() <= 2)
			cout<<s<<" is surprising.\n";
		else
		{
			bool is = true;
			for(int i = 1; i < s.length(); i++)
			{
				memset(vis, false, sizeof(vis));
				for(int j = 0; j < s.length(); j++)
				{
					if(i + j >= s.length())
						break;
					int pos = s[j] * 100 + s[i+j];
					if(vis[pos])
					{
						is = false;
						break;
					}
					else
						vis[pos] = true;
				}
				if(!is)
					break;
			}
			if(is)
				cout<<s<<" is surprising.\n";
			else
				cout<<s<<" is NOT surprising.\n";
		}
		cin>>s;
	}
	return 0;

}