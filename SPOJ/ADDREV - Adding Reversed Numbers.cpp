
#include <cstdio>
#include<stdio.h> 
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector> 
#include <string>
#include<sstream>
#include <map> 
#include <iomanip> 
using namespace std;

int main()
{
int n,num,i,a,b,ra,rb,lena,lenb,pa,pb,sum,rsum,len,power;
cin>>n;
for(num=0;num<n;num++)
{
cin>>a>>b;
ra=a;
rb=b;
lena=0;
lenb=0;
while(ra!=0)
{
ra/=10;
lena++;
}
while(rb!=0)
{
rb/=10;
lenb++;
}
pa=1;
pb=1;
for(i=1;i<lena;i++)
pa*=10;
for(i=1;i<lenb;i++)
pb*=10;
ra=0;
rb=0;
while(a!=0)
{
ra+=(a%10)*pa;
a/=10;
pa/=10;
}
while(b!=0)
{
rb+=(b%10)*pb;
b/=10;
pb/=10;
}
sum=ra+rb;
rsum=sum;
len=0;
while(rsum!=0)
{
rsum/=10;
len++;
}
power=1;
for(i=1;i<len;i++)
power*=10;
rsum=0;
while(sum!=0)
{
rsum+=(sum%10)*power;
sum/=10;
power/=10;
}
cout<<rsum<<endl;
}
} 