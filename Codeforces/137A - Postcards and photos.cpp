#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<stack>
using namespace std;
int main()
{
	string s , temp ; 
	int i ,c = 0 ,same=0; 
	cin >> s ; 

	for (i=1;i<s.length();i++)
	{
		if (s[i-1]!=s[i])
		{
			c++;
			same=0;

		}
		else
		{
			same++;
			if(same == 5 )
			{
				c++;
				same = 0 ;
			}

		}
	}

	cout << c+1<<endl;
}