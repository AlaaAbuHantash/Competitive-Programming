#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility> 
#include <stack>
using namespace std;
int main()
{
 
	string s ; 
	stack<int> s2 ; 
	cin >> s ; 
	int i ; 
	vector <int> v (s.length()) ;
	for ( i =0 ; i <s.length() ; i++)
	{
		if ( s[i] == '(')
			s2.push(i) ; 
		else if (s[i] == ')' && s2.size() ) 
		{
			//cout << i << " " << s2.top() << endl;
			v[i]= 1; 
			v[s2.top()] = 1 ; 
			s2.pop(); 

		}
	}

	int c = 0 , x = 0 , max = 0  , len=1 ; 
	for ( i = 0 ; i <s.length() ; i++ ) 
	{
		//cout << v[i] << " " ;
		if (v[i] ==1 )
			x++ ;
		else 
		{
			if ( x > max ) 
			{
				max = x ; 
				len = 1 ; 
			//	cout << max << endl;
			}
			else if ( x == max ) 
			{
				len++;
			}
			
			x=0;
		}
	}
		

		   if ( x > max ) 
			{
				max = x ; 
				len = 1 ; 
				//cout << max << endl;
			}
			else if ( x == max ) 
			{
				len++;
			}

		if (max == 0 ) 
			cout << "0 1" << endl;
		else 
			cout << max << " " << len << endl;

	return 0;
}