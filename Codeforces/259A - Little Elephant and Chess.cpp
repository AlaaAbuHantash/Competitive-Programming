#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility> 
using namespace std;
int main()
{
  
	vector <string >s (8); 
	bool f = true ,b  = false , w = false  ; 
	int i  , j ;
	int c = 0 ;
	string t = "" ; 
	for ( i = 0 ; i <8 ; i++)
		{
			cin >> s[i] ; 
			for(j=0;j<8;j++)
				if(s[i][j] == 'B' ) 
					b=true;
				else if ( s[i][j] == 'W')
					w = true;
	}

	
	for ( i = 1 ; i <8 ; i++)
	{

		t = s[i-1].substr(0,7);
		t = s[i-1][7] + t ; 
		if ( s[i-1] != s[i] && t != s[i])
				f=false;
		if ( s[i-1] == s[i] ) 
			c++;
		t="";
	}

	if ( f  && b && w  && c != 7 )
		cout << "YES"<<endl;
	else
		cout <<"NO"<<endl;
	return 0;
}