#include <iostream> 
#include <string>  
#include <vector> 
using namespace std;

int main()
{

	int n , t ,i , j; 
	cin >> n >> t ; 
	vector<string> s (n); 
	vector<int> max (t); 
	for (i=0 ; i < n ; i++)
		cin >> s[i];

	
	for (i=0 ; i < t; i++)
	{
		for (j=0 ; j < n ; j++)
			if (static_cast<int>(s[j][i]) > max[i])
				max[i]=static_cast<int>(s[j][i]);
		//cout << max[i]<<endl;
	}

int c = 0;
for (j=0 ; j < n ; j++)
	for (i=0 ; i < t; i++)
	{
		
		if (s[j][i]>=max[i])
		{
			c++;
			break;
		}

	}
	cout << c <<endl;
	
return 0;
}