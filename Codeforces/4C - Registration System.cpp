#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
	int t ; 
	cin>> t ; 
	map < string , int > m ; 
	string s ; 
	while(t--) 
	{
		cin >> s ; 
		if (!m[s])
			cout << "OK" << endl;
		else 
			cout << s << m[s] << endl;
		m[s]++ ; 
	}

} 