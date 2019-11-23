import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] ans = new int[n + 1];
		int[][] cnt = new int[101][10105];
		for (int i = 1; i <= n; i++) {
			int k = in.nextInt();
			int b = in.nextInt();
			for (int j = 0; j <= 100; j++)
				++cnt[j][k * j + b];
		}
		for (int i = 0; i <= 100; i++)
			for (int j = 0; j <= 10100; j++)
				++ans[cnt[i][j]];
		for (int i = 2; i <= n; i++) {
			if (i != 2) System.out.print(' ');
			System.out.print(ans[i]);
		}
	}
}