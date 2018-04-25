import java.io.Console;
import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;
import java.math.BigInteger;
import java.util.*;
import javax.swing.text.StyledEditorKit.BoldAction;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int arr[] = new int[105];
		int a, k = 0;
		BigInteger res, p;
		while (sc.hasNext()) {
			arr[k] = sc.nextInt();
			a = arr[k];
			res = BigInteger.valueOf(arr[k]);
			k++;
			if (a == -999999) {
				for (int i = 0; i < k - 1; i++) {
					p = BigInteger.valueOf(arr[i]);
					res = res.max(p);
					for (int j = i + 1; j < k - 1; j++) {
						p = p.multiply(BigInteger.valueOf(arr[j]));
						res = res.max(p);
					}
				}
				System.out.println(res);
				k = 0;
			}

		}

	}

}
