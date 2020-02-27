import java.math.*;
import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		BigInteger _3 = new BigInteger("3");
		BigInteger _11 = new BigInteger("11");
		for (int i = 0; i < t; i++) {
			String s = in.next();
			BigInteger n = new BigInteger(s);
			if (n.remainder(_3).compareTo(BigInteger.ZERO) == 0) System.out.print("Yes ");
			else System.out.print("No ");
			if (n.remainder(_11).compareTo(BigInteger.ZERO) == 0) System.out.println("Yes");
			else System.out.println("No");
		}
	}
}