import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		int[] c = new int[n];
		int ans = 0, p = n >> 1;
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		for (int i = 0; i < n; i++) {
			b[i] = in.nextInt();
			c[i] = b[i] - a[i];
			ans += a[i];
		}
		for (int i = 0; i < n; i++) {
			int mn = i;
			for (int j = i; j < n; j++)
				if (c[j] < c[mn])
					mn = j;
			if (mn != i) {
				int t = c[i];
				c[i] = c[mn];
				c[mn] = t;
			}
		}
		for (int i = 0; i < p; i++)
			ans += c[i];
		System.out.println(ans);
	}
}