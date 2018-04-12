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
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
map < int , int > m ;
class TaroJiroDividing {

public :
	int getNumber(int A, int B) {
		int c = 0 ;
		m.clear();
		while (1){
			m[A]=1 ;
			if(A%2) break;
			A = A / 2 ;
		}
		while (1){
			if ( m[B]) c++ ;
			if (B%2)break;
			B = B / 2 ;
		}
		return c ;
	}
};
int main() {
	//freopen("input", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);

	return 0;
}


















