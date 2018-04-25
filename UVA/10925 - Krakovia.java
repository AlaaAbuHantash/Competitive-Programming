import java.math.BigInteger;
import java.util.Scanner;
        
class Main
{
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        BigInteger r ,f , a ,x;
        int n ,  i ,c=1 ; 
        while(true)
        {
            x = BigInteger.ZERO;
            n = s.nextInt();
            f = s.nextBigInteger();
            if ( n== 0) break;
            for (i=0 ; i < n ; i++)
            {
                r = s.nextBigInteger();
                x = x.add(r);
            }
            a = x.divide(f);
            
            System.out.println("Bill #"+ c +" costs "+x+": each friend should pay "+a);
            c=c+1;
            System.out.println();
        }
       
    }
}
