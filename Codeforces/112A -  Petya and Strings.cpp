#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string s1 , s2 ; 
	int i , c = 0; 
	cin >>s1 >> s2 ; 

	

	for (i= 0; i < s1.length() ; i++)
		if (toupper(s1[i]) != toupper(s2[i]))
		{
			if(static_cast<int>(toupper(s1[i])) > static_cast<int>(toupper(s2[i])))
			{c = 1;break;} 
			else 
			{c = -1;break ; } 

		}


		cout << c <<endl; 
  return 0;
}
