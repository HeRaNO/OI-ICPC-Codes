import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int w = in.nextInt();
		int k = in.nextInt();
		long ans = 0, c = 0;
		for (int i = 1; i <= n; i++) {
			int h = in.nextInt();
			if (h + c > w) {
				ans += (h + c - w);
				c += k;
			}
		}
		System.out.println(ans);
	}
}