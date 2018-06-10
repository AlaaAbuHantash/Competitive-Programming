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
int dx[] = {0 , 0 , -1 , 1 } ; 
int dy[] = {1 , -1 , 0 , 0 } ; 

int main()
{
	//freopen("test.in" , "rt" , stdin);
	int n  , x , sum = 0 ;
	cin >> n ; 
	for ( int i = 0 ; i < n ; i++)  {
		cin >> x ;
		sum+=x;
	}
	
	if ( sum % n ==0 ) cout << n << endl;
	else cout << n-1 << endl;
	return 0 ;
}