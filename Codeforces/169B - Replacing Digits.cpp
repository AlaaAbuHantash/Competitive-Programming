#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility> 
#include <stack>
#include <cstring> 
using namespace std;
int main()
{
	//freopen("test.in" , "rt" , stdin);

	string s1 , s2 , r = "" ;
	cin >> s1 >> s2 ; 

	sort(s2.rbegin(),s2.rend());

	for ( int i = 0, j=0; i <s1.length() ; i++ ) 
	{
		if ( s2[j] >s1[i] ) 
		{
			r = r + s2[j] ; 
			j++;
		}
		else 
			r+=s1[i];
	}
	cout << r << endl;
	return 0;
}

