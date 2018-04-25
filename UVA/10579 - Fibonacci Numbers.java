import java.util.Scanner;
import java.math.BigInteger;

class Main
{

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        BigInteger  r , arr[] = new BigInteger[10005];
        arr[0] = BigInteger.ZERO ; 
        arr[1] =BigInteger.ONE ; arr[2] = BigInteger.ONE ; 
        for (int i = 3 ; i <= 10000 ; i++)
        {
            arr[i] = arr[i-1].add(arr[i-2]) ;
           //System.out.println(arr[i]);
        }
       // System.out.println(arr[10000]);
        int n ; 
        while (sc.hasNextBigInteger())
        {
            n= sc.nextInt();
            System.out.println(arr[n]);
        }

    }
  
}
