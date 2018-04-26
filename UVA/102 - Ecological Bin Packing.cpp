#include<stdio.h>

int main()
{
    long int a[7], i,b[5],g[5],c[5],small;


    while(scanf("%ld%ld%ld%ld%ld%ld%ld%ld%ld",&b[1],&g[1],&c[1],&b[2],&g[2],&c[2],&b[3],&g[3],&c[3])==9)
    {
       a[1]=b[2]+b[3]+g[1]+g[2]+c[1]+c[3];
       a[2]=b[2]+b[3]+g[1]+g[3]+c[1]+c[2];
       a[3]=b[1]+b[3]+g[1]+g[2]+c[2]+c[3];
       a[4]=b[1]+b[2]+g[1]+g[3]+c[2]+c[3];
       a[5]=b[1]+b[3]+g[2]+g[3]+c[1]+c[2];
       a[6]=b[1]+b[2]+g[2]+g[3]+c[1]+c[3];
       small=a[1];
       for(i=2;i<7;i++)
       {
           if(a[i]<small)
            small=a[i];
       }
       for(i=1;i<7;i++)
       {
           if(a[i]==small)
           {
                if(i==1)
                    printf("BCG %ld\n",small);
                else if(i==2)
                    printf("BGC %ld\n",small);
                else if(i==3)
                    printf("CBG %ld\n",small);
                else if(i==4)
                    printf("CGB %ld\n",small);
                else if(i==5)
                    printf("GBC %ld\n",small);
                else
                    printf("GCB %ld\n",small);
                break;
           }
       }

    }
    return 0;
}


