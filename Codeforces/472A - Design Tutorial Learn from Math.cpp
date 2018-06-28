#include<iostream> 
#include<stdio.h>
#include<string.h>
using namespace std ; 
bool isprime[1000001];

void prime()
{

	memset(isprime,true,sizeof(isprime));

	isprime[0]=isprime[1]=1;
	for(int i=2;i*i<=1000000;i++)
		if(isprime[i])
			for(int j=i*i;j<=1000000;j+=i)
				isprime[j]=false;

}
int main () {
	int x , a , b ; 
	prime();
	scanf("%d",&x ) ; 
	for ( int i = 4 ; i < x ; i++ )
		if (!isprime[i] && !isprime[x-i] ){
			printf("%d %d\n" , i, x - i);
			break;
		}

	return 0 ; 
}