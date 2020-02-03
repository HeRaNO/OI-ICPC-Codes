import java.math.*;
import java.util.*;

public class Main {
	static BigInteger n;
	static int K;
	static BigInteger[][] C = new BigInteger[102][102];
	static BigInteger[] S = new BigInteger[102];

	static void TriC() {
		for (int i = 0; i <= 101; i++) {
			C[i][0] = C[i][i] = BigInteger.ONE;
			for (int j = 1; j < i; j++)
				C[i][j] = C[i - 1][j].add(C[i - 1][j - 1]);
		}
		return ;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		TriC();
		while (in.hasNext()) {
			S[0] = in.nextBigInteger();
			K = in.nextInt();
			BigInteger n = S[0].add(BigInteger.ONE);
			for (int k = 1; k <= K; k++) {
				S[k] = BigInteger.ONE;
				for (int i = 1; i <= k + 1; i++)
					S[k] = S[k].multiply(n);
				S[k] = S[k].subtract(BigInteger.ONE);
				for (int i = 0; i < k; i++)
					S[k] = S[k].subtract(C[k + 1][i].multiply(S[i]));
				S[k] = S[k].divide(BigInteger.valueOf(k + 1));
			}
			System.out.println(S[K]);
		}
	}
}