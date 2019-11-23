import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), ans = 0;
		for (int i = 1; i <= n; i++)
			ans += in.nextInt() - 1;
		System.out.println(ans);
	}
}