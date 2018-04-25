import java.util.Scanner;
import java.math.BigInteger;

class Main
{

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);            
        BigInteger a[] = new  BigInteger[500] , n , b , c[] = new BigInteger[10] , f;
        int i  , x ;
        a[0] = BigInteger.ONE;
        a[1] = BigInteger.ONE;
        n = BigInteger.valueOf(2);
        for (i=2 ; i <=499 ; i++  , n=n.add(BigInteger.ONE))
            a[i] = a[i-1].multiply(n);


        while(sc.hasNext())
        {
            x = sc.nextInt();
            if (x == 0 ) break;
            f = a[x] ; 
            
            for ( i = 0 ; i < 10 ; i++)
              c[i] = BigInteger.ZERO;
            while (!(f.equals(BigInteger.valueOf(0))))
            {
                b = f.mod(BigInteger.valueOf(10));
                if(b.equals(BigInteger.valueOf(0)))
                    c[0] = c[0].add(BigInteger.ONE);
                else if(b.equals(BigInteger.valueOf(1)))
                    c[1] = c[1].add(BigInteger.ONE);
                else if(b.equals(BigInteger.valueOf(2)))
                    c[2] = c[2].add(BigInteger.ONE);
                else if(b.equals(BigInteger.valueOf(3)))
                    c[3] = c[3].add(BigInteger.ONE);
                else if(b.equals(BigInteger.valueOf(4)))
                    c[4] = c[4].add(BigInteger.ONE);
                else if(b.equals(BigInteger.valueOf(5)))
                    c[5] = c[5].add(BigInteger.ONE);
                else if(b.equals(BigInteger.valueOf(6)))
                    c[6] = c[6].add(BigInteger.ONE);
                else if(b.equals(BigInteger.valueOf(7)))
                    c[7] = c[7].add(BigInteger.ONE);
                else if(b.equals(BigInteger.valueOf(8)))
                    c[8] = c[8].add(BigInteger.ONE);
                else if(b.equals(BigInteger.valueOf(9)))
                    c[9] = c[9].add(BigInteger.ONE);
                
                f =f.divide(BigInteger.TEN);
            }
            
            System.out.println(x+"! --");
            System.out.printf("    (0)  %3d    (1)  %3d    (2)  %3d    (3)  %3d   (4)  %3d\n" , c[0] , c[1], c[2] , c[3] , c[4]);
            System.out.printf("    (5)  %3d    (6)  %3d    (7)  %3d    (8)  %3d   (9)  %3d\n",c[5] ,c[6]  ,c[7] ,c[8] , c[9] );
           //System.out.println(r);
        }
      }  
   
  
}
