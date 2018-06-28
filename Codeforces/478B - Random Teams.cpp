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
#include <math.h>
#include<cstdio>
#include<deque>
#include<sstream>
#include<math.h>
/*YOU got a DREAM, YOU gotta protect it. */
using namespace std;
#define mp make_pair
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main() {

	//freopen("input", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	long long a ,b ;
	cin >> a >> b ;
	long long x = a  / b ;
	long long  ms=0;
	long long  mx = (a-(b -1)-1)*(a-(b-1)) / 2;
	if (a%b){
		ms = (b-(a%b))* ((x-1) * x / 2 );
		x++;
		ms+= (a%b) * ((x-1)* x / 2);
	}
	else {
		ms = b *( (x-1) * x / 2) ;
	}
	printf("%I64d %I64d\n" , ms , mx);
	return 0;
}


