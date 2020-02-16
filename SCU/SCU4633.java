import java.math.*;
import java.util.*;

public class Main{
	public static void main(String [] args){
		Scanner cin = new Scanner(System.in);
		BigInteger a, b;
		BigInteger _2 = BigInteger.valueOf(2);
		while (cin.hasNext()) {
			a = cin.nextBigInteger();
			b = cin.nextBigInteger();
			while (true) {
				if (a.compareTo(b) > 0) a = a.divide(_2);
				else if (a.compareTo(b) == 0) break;
				else b = b.divide(_2);
			}
			System.out.println(a);
		}
	}
}