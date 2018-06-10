#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
int main()
{
	string s  , t = "" ; 
	int i ; 
	cin >> s; 
	bool f  = false; 
	for ( i =  0; i < s.length() ; i++) 
	{
		if ( s[i] == '0'  &&  !f) 
			{
				f = true;
				continue;
		    }
		else 
			t = t + s[i] ; 
		//cout << t <<endl;
	}

	if (f) 
		cout << t << endl;
	else 
	{
		s = s.substr(1);
		cout << s <<endl;
	}
}