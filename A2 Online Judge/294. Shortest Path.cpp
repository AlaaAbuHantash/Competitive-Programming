#include<iostream>
#include<queue> 
#include<string.h>
#include<stdio.h>
using namespace std ; 
int t , n , m , x ; 
char ch ; 
int a[2005][2005],vis[2005] ,res[2005] ; 
void bfs () {

	int lev = 1 ;
	queue<int > q ; 
	q.push(x) ; 
	vis[x] = 1 ; 
	res[x] = 0; 
	while(!q.empty() ) {
		int siz = q.size() ; 
		while(siz-- ) {
			int fr = q.front() ; 
			q.pop() ; 
			for ( int i = 0 ; i < n ; i++) 
				if ( a[fr][i]  == 1  && !vis[i] ) {
					vis[i] = 1; 
					res[i] = lev; 
					q.push(i);
				}
		}
		lev++;
	}

	printf("%d",res[0]);
	for ( int i = 1 ; i < n ; i++) 
		printf(" %d" , res[i] ) ; 
	printf("\n");
}
int main () {
	//freopen("test.in", "rt", stdin);
	scanf("%d",&t) ; 
	while(t--){
		memset(a , 0 , sizeof(a ) ) ;
		memset(vis, 0 , sizeof(vis ) ) ;
		memset(res , -1 , sizeof(res ) ) ;

		scanf("%d%d",&n,&x); 
		x--;
		for ( int i = 0 ; i < n ; i ++) 
			for ( int j = 0 ; j < n ; j++) {
				scanf(" %c",&ch) ;	
				a[i][j] = ch-'0'; 
			}

			bfs() ; 
	}
	return 0 ; 
}