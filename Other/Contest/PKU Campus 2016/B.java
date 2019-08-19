import java.math.*;
import java.util.*;

public class Main{
	public static void main(String [] args){
		Scanner cin = new Scanner(System.in);
		BigInteger n, _2, _3, _5, _7;
		_2 = BigInteger.valueOf(2);
		_3 = BigInteger.valueOf(3);
		_5 = BigInteger.valueOf(5);
		_7 = BigInteger.valueOf(7);
		for (int t = cin.nextInt(); t > 0; t--) {
			n = cin.nextBigInteger();
			System.out.println('3');
			System.out.println(n);
			System.out.println(n.multiply(_5).add(_2));
			System.out.println(n.multiply(_7).add(_3));
		}
	}
}