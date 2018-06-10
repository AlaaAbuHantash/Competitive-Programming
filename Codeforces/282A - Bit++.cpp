#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n  , x = 0 , i ; 
	cin >> n ; 
	string  s ;

	for (i=0 ; i < n ; i++)
	{
		cin >> s ; 
		if (s == "X++")
			x++;
		else if (s == "++X")
			++x;
		else if (s == "X--")
			x--;
		else if (s == "--X")
			--x;
	}

	cout << x << endl;
  return 0;
}
