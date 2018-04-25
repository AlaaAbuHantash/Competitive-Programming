import java.util.Scanner;
import java.math.BigDecimal ;

class Main
{

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int t ; 
        char s[] ;
        t = sc.nextInt() ; 
        String rf;
        BigDecimal n ,r;
        for ( int i=0; i < t ; i++)
        {
            r=BigDecimal.ZERO ; 
            n = sc.nextBigDecimal() ; 
            while ( n.compareTo(BigDecimal.ZERO) != 0)
            {
                r = r.add(n);
                n = sc.nextBigDecimal() ; 

            }
           

           s = r.toString().toCharArray();
            
           rf=r.toString();
            for ( int j= rf.length()-1 ; j >= 0; j--)
                if (s[j] =='.' )
                {             
                    rf = rf.substring(0,rf.length()-1) ;
                    break;
                }
                else if ( s[j] != '0')
                    break;
                else if ( s[j] == '0')
                   rf = rf.substring(0,rf.length()-1) ;
            
            System.out.println(rf);
        }
    }
  
}
