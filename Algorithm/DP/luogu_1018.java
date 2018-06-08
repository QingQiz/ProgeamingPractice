// ======================================================================
// Dsp: 乘积最大
// URL: https://www.luogu.org/problemnew/show/P1018
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
import java.math.BigInteger;
import java.util.Scanner;

public class luogu_1018 {
	static Scanner inner = new Scanner(System.in);

	static BigInteger max(BigInteger a, BigInteger b) {
		if (a.compareTo(b) > 0)
			return a;
		else
			return b;
	}

	public static void main(String[] args) {
		int n = inner.nextInt();
		int k = inner.nextInt();
		String data = inner.next();
		BigInteger[][] dp = new BigInteger[50][50];
		BigInteger[][] vle = new BigInteger[50][50];
		for (int i = 0; i < 50; ++i) {
			for (int j = 0; j < 50; ++j) {
				dp[i][j] = BigInteger.ONE;
				vle[i][j] = BigInteger.ZERO;
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = i; j <= n; ++j) {
				vle[i][j] = vle[i][j - 1].multiply(BigInteger.TEN).add(BigInteger.valueOf((int)(data.charAt(j - 1) - '0')));
			}
		}
		for (int i = 1; i <= n; ++i) {
			dp[i][0] = vle[1][i];
		}
		for (int i = 1; i <= k; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int p = i; p < j; ++p) {
					dp[j][i] = max(dp[j][i], dp[p][i - 1].multiply(vle[p + 1][j]));
				}
			}
		}
		System.out.println(dp[n][k]);
	}
}
// ======================================================================
// Keys: 区间dp
// 用dp[i][j]表示从字符串开头长度为i分配了j个乘号获得的乘积的最大值
// 枚举区间的划分点p (j+1~i)
// 因此状态转移方程为:
// dp[i][j] = max(dp[i][j], dp[p][j - 1] * vle[p + 1][i])
// 其中vle[i][j]表示的数字为从字符串第i位起到第j位为止构成的数字的大小
// ======================================================================
