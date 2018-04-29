#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;
int main()
{
	string s ; 
	char ch =' '; 
	getline(cin , s ) ;
	int x = s.length() , a ;
	x--;
	while(x--)
	{
		
		ch = toupper(s[x]);
		if ( ch == ' ' ) continue;
		if ( isalpha(ch)) break; 
	}
	if (ch == 'A' ||ch== 'E' || ch == 'I'|| ch == 'O'|| ch == 'U'|| ch =='Y' ) 
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;
	return 0;
}