import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int ans = 0;
		int a[] = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = 1000000000;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				int x = in.nextInt();
				if (x != -1)
					a[j] = Math.min(a[j], x);
			}
		for (int i = 0; i < n; i++)
			ans += a[i];
		System.out.println(ans);
	}
}