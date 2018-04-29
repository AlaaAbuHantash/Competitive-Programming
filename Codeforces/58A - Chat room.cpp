#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int main()
{
	string s , H="hello";
	
	cin >> s ; 

	int j = 0 ,c=0; 
	for (int i = 0 ; i <=s.length() ; i++)
	{
		if (H[j]==s[i])
		{
			//cout << H[j]<<s[i]<<endl;
			c++;
			j++;
		
		}
	}

	//cout << c <<endl;

	if(c == 6)
		cout << "YES"<<endl;
	else
		cout << "NO"<<endl;
}

