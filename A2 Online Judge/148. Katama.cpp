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
#include <cmath>
#include <stdio.h>
#include <string.h>

#define mp make_pair

using namespace std;
int main()
{
	//freopen("test.in" , "rt" , stdin);

	string s ; 
	stack < char > st ; 
	while(getline(cin , s )) {
		if ( s == "***" ) 
			break;

		for (int i = 0 ; i < s.length() ; i++) 
			if (s[i] >= '0' && s[i] <= '9')
				st.push(s[i]);
		
		cout << st.top() ;
		st.pop() ;
		while ( !st.empty() ) {
			cout << " " << st.top() ; 
			st.pop();
		}
		cout << endl;

	}

	return 0;
}
