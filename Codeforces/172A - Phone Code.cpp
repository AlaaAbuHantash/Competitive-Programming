#include <iostream> 
#include <string>  
#include <vector> 
#include<algorithm>
#include<iomanip>
using namespace std;

int main()
{
	int i ,t , j  , c=0; 
	cin >> t ; 
	bool flag;
	vector<string>s(t);
	for(i=0;i<t;i++)
		cin>>s[i];

	for (j=0;j<s[0].length() ; j++)
	{
		flag = true;
		for(i=1;i<t;i++)
			if(s[i-1][j] != s[i][j])
				flag=false;

		if(flag)c++;
		else break;
	}
	cout << c << endl;
return 0;
}