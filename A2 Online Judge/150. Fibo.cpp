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

int dp [1005];
int fib ( int x ) 
{

	if ( dp[x] != -1 ) 
		return dp[x];


	dp[x] = (fib ( x -2) + fib ( x-1 )) %10 ; 
	return dp[x];
}

int main()
{
	//freopen("test.in" , "rt" , stdin);

	int n ; 
	memset(dp , -1 , sizeof dp ) ;
	dp[0] = 0 ; 
	dp[1] = 1 ; 
	dp[2] = 1 ; 
	dp[3] = 2 ; 
	fib(100);
	//for ( int i = 0 ; i < 100 ; i ++) 
	 // cout <<i << " " << fib(i)  << endl; 
	while( cin >> n ) 
	{
		n = n %60 ; 
		cout << dp[n]%10<<endl;
	}
	return 0;
}
