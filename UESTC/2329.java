import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int x = in.nextInt();
		int y = in.nextInt();
		int ans = ~(1 << 31);
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		for (int i = 0; i <= 5000; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++)
				cnt += Math.max((a[j] - x * i + y - 1) / y, 0);
			ans = Math.min(ans, cnt + i);
		}
		System.out.println(ans);
	}
}