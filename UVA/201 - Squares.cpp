/**			
***** Judge
******* Yourself 
********* Only   
*/
#define _CRT_SECURE_NO_WARNINGS
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
#include<cmath>
//#include "testlib.h"

using namespace std;
#define mp make_pair
#define eps 1e-6
int a[11][11][11][11];
int main() {
	freopen("a.txt", "rt", stdin);
	//freopen("out.txt","w",stdout);
	int  n , m  ; 
	char ch ;
	int t = 1; 
	while( cin >> n ) {
		if(t>1) {
			puts("");
			puts("**********************************\n");
		}
		cin >> m ; 
		memset(a,0,sizeof(a));
		for ( int i = 0 , x , y ; i < m ; i ++ ) {
			cin >> ch >> x >> y ; 
			x--,y--;
			if ( ch == 'H' ) {
				a[x][y][x][y+1] = 1 ; 
			}
			else {
				swap(x,y);
				a[x][y][x+1][y] = 1 ; 
			}
		}
		vector<int > v(n);
		int ff = 0 ; 
		for ( int sz = 1 ; sz <= n ; sz++ ) {
			for ( int i = 0 ; i < n ; i ++ ) {
				for ( int j = 0 ; j < n ; j++ ) {
					// i,j -> i+sz,j
					// i,j -> i, j+sz 
					// i+sz,j -> i+sz, j+sz 
					// i,j+sz -> i+sz , j+sz 
					int f = 1 ; 
					for ( int x = i ; x < i + sz && x < n ; x++ ) 
						if(!a[x][j][x+1][j]) f=0;
					
					for ( int y = j ; y < j + sz && y < n  ; y++ ) 
						if(!a[i][y][i][y+1]) f=0;
					

					for ( int x = i ; x < i + sz && j+sz < n && x < n ; x++ ) 
						if(!a[x][j+sz][x+1][j+sz]) f=0;
					
					for ( int y = j ; y < j + sz && i+sz < n &&  y < n  ; y++ ) 
						if(!a[i+sz][y][i+sz][y+1]) f=0;
					if(f){
						ff = 1 ; 
						v[sz-1]++;
					}
				}
			}

		}
		printf("Problem #%d\n\n",t++);
		if (ff){
			for ( int i = 0 ; i < n ; i ++ ) {
				if(v[i]) 
					printf("%d square (s) of size %d\n",v[i] , i+1) ; 
			}
		}
		else {
			puts("No completed squares can be found.");
		}
	}


	return 0 ; 
}