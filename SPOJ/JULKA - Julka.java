import java.util.Scanner; 
import java.math.BigInteger;

public class Main 
{

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        BigInteger n1 , n2,r2 ,r1 ; 
        for (int i = 0 ; i < 10 ; i++) {
            n1=sc.nextBigInteger();
            n2=sc.nextBigInteger();
            r1=n1.add(n2).divide(BigInteger.valueOf(2));
            r2=n1.subtract(n2).divide(BigInteger.valueOf(2));
            System.out.println(r1+ " " +r2);
        }
    }
}
 