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
	string s1 , s2 ,s3 ; 

	cin >> s1 >> s2 >> s3 ; 


	if ( s1 == s2 && ( s1 == "rock"   && s3 ==  "paper"  || s1 == "paper" && s3 == "scissors"   || s1 == "scissors" && s3 == "rock" ) ){
			cout << "S" <<endl;
	}
	else if (s2 == s3 && ( s2 == "rock"   && s1 ==  "paper"  || s2 == "paper" && s1 == "scissors"   || s2 == "scissors" && s1 == "rock" )  ) {
			cout << "F" <<endl;
	}
	else if ( s1 == s3  && ( s1 == "rock"   && s2 ==  "paper"  || s1 == "paper" && s2 == "scissors"   || s1 == "scissors" && s2 == "rock" ) ) {
			cout << "M" <<endl;
	}
	else 
		cout << "?" <<endl;
	return 0 ;
}