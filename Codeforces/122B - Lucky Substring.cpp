#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	int  i , n4 , n7 , n ; 
	string s ; 
	cin >> s ; 
	n4= 0 ; n7 = 0 ;
	for (i=0 ; i<s.length() ; i++ ) 
	{
		if (s[i] == '4' ) 
			n4++;
		else if (s[i] == '7' ) 
			n7++;
	}
	if  (n7 > n4 ) cout << "7" << endl;
	else if ( n4 > n7 ) cout << "4" <<endl;
	else if (n4 == n7 && n4 !=0 ) cout << "4" <<endl;
	else if ( !n4 && !n7 ) cout << "-1"<<endl;

}
