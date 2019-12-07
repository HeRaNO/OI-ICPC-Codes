import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), cnt = 0;
		long k = in.nextLong();
		String s = in.next();
		long b = (k - 1) / n + 1;
		for (int i = 60; i != -1; i--)
			if (b > (1L << i)) {
				b -= (1L << i);
				cnt ^= 1;
			}
		int p = s.charAt((int)((k - 1) % n)) - '0';
		System.out.println(p ^ cnt);
	}
}