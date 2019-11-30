import java.util.*;

public class Main {
	static final int Z1 = 10100;
	static final int Z2 = 100;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int a = in.nextInt();
		int b = in.nextInt();
		int[] cnt = new int[Z1 << 1 | 1];
		int[][] s = new int[Z1 << 1 | 1][Z2 << 1 | 1];
		long ans = 0;
		for (int i = 1; i <= n; i++) {
			int x = in.nextInt();
			int vx = in.nextInt();
			int vy = in.nextInt();
			ans += cnt[a * vx - vy + Z1] - s[a * vx - vy + Z1][vx + Z2];
			++cnt[a * vx - vy + Z1];
			++s[a * vx - vy + Z1][vx + Z2];
		}
		System.out.println(ans << 1);
	}
}