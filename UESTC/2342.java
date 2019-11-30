import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		long ans = 1;
		String[] s = new String[n];
		for (int i = 0; i < n; i++)
			s[i] = in.next();
		for (int i = 0; i < n; i++)
			if (s[i].equals("xx")) {
				System.out.println("NO");
				return ;
			}
		for (int i = 1; i < n; i++) {
			if (s[i - 1].charAt(0) == 'x' && s[i].charAt(1) == 'x') {
				System.out.println("NO");
				return ;
			}
			if (s[i - 1].charAt(1) == 'x' && s[i].charAt(0) == 'x') {
				System.out.println("NO");
				return ;
			}
		}
		for (int i = 1; i < n; i++)
			if (s[i].equals(".."))
				ans <<= 1;
		System.out.println("YES");
		System.out.println(ans);
	}
}