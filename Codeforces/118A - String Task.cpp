#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string s; 

	int i ; 
	cin >> s ; 
	for (i = 0 ; i < s.length() ; i++)
	{
		 if (isupper(s[i]))
			s[i]= tolower(s[i]);


		if ((s[i] == 'a') || (s[i] == 'o')||( s[i] == 'u') ||( s[i] == 'i') || (s[i] == 'e')|| (s[i] == 'y'))
			continue ;
		else 
			cout << "." << s[i];
	
	}
	cout << endl; 
  return 0;
}
