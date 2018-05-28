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

int main()
{
	//freopen("test.in" , "rt" , stdin);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n ;
	string s ; 
	cin >> s  >> n ;

	if (( s == "front" && n == 1 ) || ( s == "back" && n == 2) ) 
		cout << "L" << endl;
	else 
		cout << "R"<<endl;

	return 0 ;
}