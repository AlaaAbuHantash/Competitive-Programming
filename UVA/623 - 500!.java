
import java.util.Scanner;
import java.math.BigInteger;

class Main
{

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);            
        BigInteger a[] = new  BigInteger[1020] , n;
        int i  , x;
        a[0] = BigInteger.ONE;
        a[1] = BigInteger.ONE;
        n = BigInteger.valueOf(2);
        for (i=2 ; i <=1010 ; i++  , n=n.add(BigInteger.ONE))
            a[i] = a[i-1].multiply(n);

        while(sc.hasNext())
        {
            x = sc.nextInt();
            System.out.println(x+"!");
            System.out.println(a[x]);
           //System.out.println(r);
        }
      }  
   
  
}
