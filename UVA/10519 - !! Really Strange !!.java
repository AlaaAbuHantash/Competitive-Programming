
import java.util.Scanner;
import java.math.BigInteger;

class Main
{

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        BigInteger n , r ; 
        while (sc.hasNextBigInteger())
        {
            n= sc.nextBigInteger();
            if (n.equals(BigInteger.ZERO) )
                r = BigInteger.ONE ; 
            else 
               r = n.multiply(n).subtract(n).add(BigInteger.valueOf(2));
            
            System.out.println(r);
        }

    }
  
}
