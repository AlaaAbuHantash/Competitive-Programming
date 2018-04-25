import java.math.BigInteger;
import java.util.Scanner;

class Main
{
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        int n  , i , c = 1 ;
        int[] m= new int[15];
        int[] a= new int[15];

        while (true)
        {
            n = s.nextInt();
            if (n < 0)break;
            for(i=1 ; i <13 ;i++) m[i] = s.nextInt();
            for(i=0; i < 12 ;i++) a[i] = s.nextInt(); 
            
            m[0] = n;
            System.out.println("Case "+c+":");
            c = c + 1 ;
             for(i=0; i < 12 ;i++)
             {
                 if(m[i] - a[i] >= 0 )
                 {
                     m[i+1] = m[i+1] + m[i] - a[i];  
                     System.out.println("No problem! :D");
                 }
                 else 
                 {
                     m[i+1] = m[i+1] + m[i];  
                     System.out.println("No problem. :(");
                 }
                 
             }
        }
       } 
}
