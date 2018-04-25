
import java.util.Scanner;
import java.math.BigInteger;

class Main
{

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        BigInteger  n1, n2 , r ;
        int n ; 
        n=sc.nextInt();
        for(int i = 0 ; i < n ; i++)
        {
            n1 = sc.nextBigInteger();
            n2= sc.nextBigInteger();
            r=n1.subtract(n2);
            System.out.println(r);
        }
    }
  
}
