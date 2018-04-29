#include <iostream> 
#include <string>  
#include <vector> 
#include<algorithm>
#include <stdio.h>
#include <ctype.h>
using namespace std;

int main()
{

	string s; 
	int i , u =0, l=0 ; 
	cin >> s ; 

	for ( i =0 ; i <s.length() ; i++ ) 
		if (isupper(s[i]))
			u++;
		else
			l++;


	if(u>s.length()/2)
		for ( i =0 ; i <s.length() ; i++ ) s[i]=toupper(s[i]);
	else 
		for ( i =0 ; i <s.length() ; i++ ) s[i]=tolower(s[i]);

	cout<<s<<endl;



return 0;
}