import java.math.BigInteger;
import java.util.Scanner;
        
class Main
{
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        BigInteger a , b  , r ;
        r = BigInteger.ZERO;
        String c ;
       
        while(s.hasNext())
        {
            a = s.nextBigInteger();
            c = s.next();
            b = s.nextBigInteger();
            if ("%".equals(c))
                r = a.mod(b);
            else if ( "/".equals(c))
                r = a.divide(b);
            
            System.out.println(r);
        }
       
    }
}
