import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long n = in.nextLong();
		long[] f = new long[41];
		for (int i = 1; i <= 40; i++)
			f[i] = 3 * f[i - 1] + 1;
		for (int i = 1; i <= 40; i++)
			if (n <= f[i]) {
				System.out.println(i);
				return ;
			}
	}
}