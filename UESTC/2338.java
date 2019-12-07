import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] cnt = new int[101];
		int a = 0, b = 0;
		for (int i = 1; i <= n; i++) {
			int x = in.nextInt();
			int y = in.nextInt();
			++cnt[x]; ++cnt[y];
		}
		for (int i = 1; i <= 100; i++)
			if ((cnt[i] & 1) == 1) {
				if (a == 0) a = i;
				else b = i;
			}
		if (a != 0) {
			System.out.println(a * b);
			return ;
		}
		for (int i = 100; i >= 0; i--)
			if (cnt[i] != 0) {
				System.out.println(i * i);
				return ;
			}
	}
}