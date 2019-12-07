import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int x = in.nextInt();
		int y = in.nextInt();
		for (int i = 1; i <= n; i++)
			y += in.nextInt();
		long _y = y;
		_y *= y;
		System.out.println(_y - x * x);
	}
}