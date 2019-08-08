import java.math.*;
import java.util.*;

public class Main{
	public static void main(String [] args){
		Scanner cin = new Scanner(System.in);
		BigInteger f[] = new BigInteger[205];
		BigInteger _3[] = new BigInteger[205];
		f[1] = BigInteger.valueOf(1);
		f[2] = BigInteger.valueOf(2);
		_3[0] = BigInteger.valueOf(1);
		_3[1] = BigInteger.valueOf(3);
		for (int i = 2; i <= 200; i++)
			_3[i] = _3[i - 1].multiply(_3[1]);
		for (int i = 3; i <= 200; i++)
			f[i] = f[i - 1].multiply(_3[1]);
		int n, t;
		for (t = cin.nextInt(); t > 0; t--) {
			n = cin.nextInt();
			if (n == 2) {
				System.out.println("-1");
			}
			else {
				for (int i = 1; i < n; i++)
					System.out.println(f[i]);
				System.out.println(_3[n - 2]);
			}
		}
	}
}