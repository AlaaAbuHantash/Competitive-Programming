#include <iostream> 
#include <string>  
#include <vector> 
using namespace std;

int main()
{
	int n , i , flag ,s1=0 , s2=0 , n1=0 ,n2=0  ,t;
	string s ; 
	cin >> n ; 
	cin >> s ; 
	flag = 1 ; t=0;
	for (i=0 ; i <n ; i++ )
		if (s[i]!= '7' && s[i] != '4')
		{
			flag = 0 ; break;
		}

	for (i=0 ; i<n/2 ; i++ )
		if(s[i]== '7')
			s1++ ; 
		else if (s[i]== '4')
			s2++;

	for (i=n/2 ; i<n ; i++ )
		if(s[i]== '7')
			n1++ ; 
		else if (s[i]== '4')
			n2++;

	if (s1 == n1 && n2 == s2 )
		t = 1;

	if (!flag || !t ) 
		cout << "NO\n"; 
	else 
		cout << "YES\n";


return 0;
}