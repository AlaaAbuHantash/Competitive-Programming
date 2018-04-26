#include<stdio.h>
#include <iostream>

using namespace std; 

int main()

{

int T,x , y ; 
 scanf("%d", &T);
while (T--)
{        scanf("%d%d", &x,&y);
   if (x%2==0 && y%2==0 && (x==y || x-y == 2)) 
	{
printf("%d\n", x+y);
	}
	else if (x%2!=0 && y%2!=0 && (x==y|| x-y==2))
	{
printf("%d\n", x+y-1);
   }
	else 
		printf("No Number\n");

}

return 0 ;
}

