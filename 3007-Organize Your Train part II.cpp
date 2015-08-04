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
#include<set>
using namespace std;
const int size = 75;
const int mod=99991;
int ans = 0;
int prime[100] = {3, 5, 7, 11, 13, 17, 19, 23, 29,31, 37, 41, 43, 47, 53, 59, 61, 67, 71,73, 79, 83, 89, 97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541};
struct node
{
	char s[size];
	node *next;
	node()
	{
		next = NULL;
	}
};
node *hashtable[mod];

void strcpy2(char *s1, char *s2, char *train, int pos, int len)
{
	int i = 0, j = 0;
	for(i = 0; i <= pos; i++)
		s1[i] = train[i];
	s1[i++] = '\0';
	for(i = pos + 1; i < len; i++)
		s2[j++] = train[i];
	s2[j] = '\0';
}

void strreverse(char *s1, char *s2)
{
	int i = 0;
	int len = strlen(s1);
	s2[len--] = '\0';
	while(s1[i] != '\0')
		s2[len--] = s1[i++];
}

void strcpy1(char *target, char *source)
{
	int i = 0;
	while(source[i] != '\0')
	{
		target[i] = source[i];
		i++;
	}
	target[i] = '\0';
}
void insert(char *s)
{
	int key = 0;
	for(int i = 0; s[i] != '\0'; i++)
		key += (s[i] - 'a' + 1) * prime[i];
	key %= mod;
	if(hashtable[key] == NULL)
	{
		node *tmp = new node();
		strcpy(tmp->s, s);
		hashtable[key] = tmp;
		ans++;
	}
	else
	{
		node *root = hashtable[key];
		if(!strcmp(root->s, s))
			return;
		else
		{
			while(root->next != NULL)
			{
				if(!strcmp(root->next->s, s))
					return;
				root = root->next;
			}
			node *tmp = new node();
			strcpy1(tmp->s, s);
			root->next = tmp;
			ans++;
		}
	}
}
void strcat2(char *train, char *s1, char *s2)
{
	int i = 0, pos = 0;
	while(s1[i] != '\0')
		train[pos++] = s1[i++];
	i = 0;
	while(s2[i] != '\0')
		train[pos++] = s2[i++];
	train[pos] = '\0';
}
int main()
{
	int n;
	char train[size];
	cin>>n;
	while(n--)
	{
		cin>>train;
		int len = strlen(train);
		if(len <= 1)
		{
			cout<<1<<"\n";
			continue;
		}
		memset(hashtable,0,sizeof(hashtable)); 
		ans = 0;

		for(int i = 0; i < len - 1; i++)
		{
			char tmp[size];
			strcpy1(tmp, train);
			char s1[size], s2[size];
			char s3[size], s4[size];
			strcpy2(s1, s2, train, i, len);
			strreverse(s1, s3);
			strreverse(s2, s4);
			

			strcat2(tmp, s1, s2);
			insert(tmp);
			strcat2(tmp, s1, s4);
			insert(tmp);
			strcat2(tmp, s3, s4);
			insert(tmp);
			strcat2(tmp, s3, s2);
			insert(tmp);
			strcat2(tmp, s2, s1);
			insert(tmp);
			strcat2(tmp, s2, s3);
			insert(tmp);
			strcat2(tmp, s4, s1);
			insert(tmp);
			strcat2(tmp, s4, s3);
			insert(tmp);
		}
		cout<<ans<<"\n";

	}
	return 0;
}