import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String s = in.next();
		String Nico = new String("NicoNicoNi");
		int ans = 0;
		for (int i = 0; i <= s.length() - 10; i++) {
			String t = s.substring(i, i + 10);
			if (t.equals(Nico)) ++ans;
		}
		System.out.println("NicoNicoNi * " + ans);
	}
}