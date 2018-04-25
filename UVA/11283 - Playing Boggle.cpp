#include <iostream>
#include<string> 
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<math.h>
#include<string.h>


using namespace std;
#define mp make_pair 
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ; 
vector<string > st(4); 
int  vis[4][4];
int len  , n , t ; 
string s ; 
bool f ; 
void dfs ( int x , int y  , int r  ) {
	if ( f) return ; 
	if ( r == len )  {
		f = 1 ; 
	}
	for ( int i = 0 ; i < 8 ; i ++) {
		int nx = x + dx[i]; 
		int ny = y + dy[i] ; 
		if ( nx >=0 && ny>=0 && nx < 4 && ny < 4 ) 
			if ( !vis[nx][ny] && st[nx][ny] == s[r] ) {
				vis[nx][ny]  = 1 ; 
				dfs ( nx , ny , r+1 ) ;
			}
	}
	vis[x][y]  = 0;

}
int main() {
	//freopen("input.in","rt",stdin);
	//freopen ("myfile.txt","w",stdout);
	int tt = 1 ;
	scanf("%d",&t) ; 
	while(t-- ) {
		for ( int i = 0 ; i < 4 ; i++) 
			cin >> st[i] ; 
		scanf("%d",&n ) ; 
		int sum = 0 ; 
		for ( int k = 0 ; k < n ; k++ ) {
			cin >> s ; 
			f=0;
			len = s.length();
			for ( int i = 0 ; i < 4 && !f ; i++) 
				for ( int j = 0 ; j < 4 ; j++) 
					if ( st[i][j] == s[0] ) {
						memset(vis,0,sizeof(vis));
						vis[i][j] = 1 ; 
						dfs(i,j,1);
						if (f ) break;
					}
					if (f) {
						if ( len == 3 || len == 4 )
							sum+=1;
						else if ( len == 5 ) sum+=2 ; 
						else if ( len == 6 ) sum+=3;
						else if ( len == 7 ) sum+=5 ;
						else if ( len >= 8 ) sum+=11;
					}
		}
		printf("Score for Boggle game #%d: %d\n",tt++ , sum ) ; 
	}
	return 0 ; 
}
