#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility> 
#include <stack>
#include <cstring> 
#include <functional>
using namespace std;
int main()
{
	//freopen("test.in" , "rt" , stdin);
	char s , d ; 
	int ss ,dd ; 
	cin >> s >>ss>> d >>dd; 
	int  i = 0 ; 
	queue<string > q ; 
	while (true ) 
	{
		if ( s == d  && ss == dd ) 
			break;


		if (s!=d && dd != ss ) 
		{
			if ( s < d ) 
			{
				if ( ss > dd ) 
				{
					ss--;
					s++;
					q.push("RD" ) ; 
				}
				else 
				{
					s++;
					ss++;
					q.push("RU" );
				}
			}
			else 
			{
				if ( ss > dd ) 
				{
					ss--;
					s--;
					q.push("LD");
				}
				else
				{
					ss++;
					s--;
					q.push("LU");
				}
			
			}
		}

		if (s == d  && ss != dd ) 
		{
			if ( ss > dd ) 
			{
				ss-- ; 
				q.push("D" ) ; 
			}
			else 
			{
				ss++;
				q.push("U");
			}
		}

		else if (ss == dd && s != d  ) 
		{
			if ( s > d ) 
			{
				s-- ; 
				q.push("L" ) ; 
			}
			else 
			{
				s++;
				q.push("R");
			}
		}


	}



	cout << q.size() << endl;

	while(!q.empty() ) 
	{
		cout << q.front() <<endl;
		q.pop();
	}

	return 0;
}



