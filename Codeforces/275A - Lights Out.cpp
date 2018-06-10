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
/*YOU got a DREAM, YOU gotta protect it. */
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main() {
	//freopen("input" , "rt" , stdin);
	//freopen ("myfile.txt","w",stdout);
	int x;
	bool r[3][3];
	memset(r, 1, sizeof(r));
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			cin >> x;
			if (x % 2 == 1) {
				r[i][j] = !r[i][j];
				for ( int k = 0 ; k < 4 ; k++){
					int nx = dx[k]+ i ;
					int ny = dy[k] + j ;
					if ( nx >= 0 && nx <3 && ny >=0 && ny <3)
						r[nx][ny] = !r[nx][ny];
				}

			}
		}
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
			cout << r[i][j];
		cout<<"\n";
	}
	return 0;
}

